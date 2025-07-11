#pragma once

#include <QString>
#include <QMap>
#include <QVector>
#include <QCache>
#include <QThread>
#include <QMutex>
#include <memory>
#include "game_data.h"

/**
 * @brief High-performance calculation engine for Satisfactory production chains
 * 
 * This class implements an optimized calculation system with:
 * - Multi-threaded calculations
 * - Advanced caching mechanisms
 * - Memory pooling for large calculations
 * - Lazy evaluation strategies
 */
class CalculatorEngine : public QObject
{
    Q_OBJECT

public:
    struct CalculationRequest {
        QString itemClass;
        double amountPerMinute;
        QMap<QString, double> customProductionRates;
        int maxDepth = 20;
        bool useAlternateRecipes = false;
    };

    struct CalculationResult {
        QMap<QString, double> rawResources;
        QMap<QString, double> intermediateResources;
        QVector<QString> calculationSteps;
        QMap<QString, int> buildingCounts;
        double totalCalculationTime = 0.0;
        bool success = true;
        QString errorMessage;
    };

    struct ProductionChain {
        QString itemClass;
        GameRecipe recipe;
        double itemsPerMinute;
        double machinesNeeded;
        QVector<std::shared_ptr<ProductionChain>> dependencies;
    };

    // Caching system structures
    struct CacheKey {
        QString itemClass;
        double amountPerMinute;
        int recipeHash;
        
        bool operator==(const CacheKey& other) const {
            return itemClass == other.itemClass && 
                   qAbs(amountPerMinute - other.amountPerMinute) < 0.001 &&
                   recipeHash == other.recipeHash;
        }
    };

    struct CacheEntry {
        QMap<QString, double> rawResources;
        QMap<QString, double> intermediateResources;
        QVector<QString> steps;
        QMap<QString, int> buildings;
    };

    explicit CalculatorEngine(QObject *parent = nullptr);
    ~CalculatorEngine();

    // Main calculation methods
    CalculationResult calculateProduction(const CalculationRequest& request);
    CalculationResult calculateHubRequirements(int tier, const QMap<QString, double>& customRates = {});
    CalculationResult calculateLiftRequirements(int phase, const QMap<QString, double>& customRates = {});

    // Performance optimization methods
    void clearCache();
    void preloadRecipes();
    void setMaxCacheSize(int maxSize);
    void enableMultithreading(bool enabled);

    // Recipe management
    void setAlternateRecipe(const QString& itemClass, const QString& recipeClass);
    void resetAlternateRecipes();
    QStringList getAvailableAlternateRecipes(const QString& itemClass) const;

    // Statistics and debugging
    int getCacheHitRate() const;
    int getTotalCalculations() const;
    QString getPerformanceReport() const;

signals:
    void calculationProgress(int percentage);
    void calculationFinished(const CalculationResult& result);
    void calculationError(const QString& error);

private slots:
    void onCalculationThreadFinished();

private:
    // Core calculation methods
    void calculateRequirementsRecursive(
        const QString& itemClass,
        double amountPerMinute,
        QMap<QString, double>& totalRaw,
        QMap<QString, double>& totalIntermediate,
        QVector<QString>& steps,
        QMap<QString, int>& buildings,
        int depth = 0
    );

    std::shared_ptr<ProductionChain> buildProductionChain(
        const QString& itemClass,
        double amountPerMinute,
        int depth = 0
    );

    GameRecipe selectOptimalRecipe(const QString& itemClass) const;
    QString formatCalculationStep(
        const QString& itemClass,
        const GameRecipe& recipe,
        double amountPerMinute,
        double machinesNeeded,
        int depth
    ) const;

    // Caching system

    // Performance monitoring
    mutable QMutex m_cacheMutex;
    mutable QMutex m_statsMutex;
    
    QCache<QString, CacheEntry> m_calculationCache;
    QMap<QString, QString> m_selectedAlternateRecipes;
    
    // Statistics
    mutable int m_cacheHits = 0;
    mutable int m_cacheMisses = 0;
    mutable int m_totalCalculations = 0;
    
    // Configuration
    int m_maxDepth = 20;
    bool m_multithreadingEnabled = true;
    bool m_useAlternateRecipes = false;
    
    // Thread management
    QThread* m_calculationThread = nullptr;
    
    // Recipe optimization data
    QMap<QString, QVector<GameRecipe>> m_recipeCache;
    QMap<QString, double> m_recipeEfficiencyCache;
    
    // Helper methods
    QString generateCacheKey(const QString& itemClass, double amount, const GameRecipe& recipe) const;
    double calculateRecipeEfficiency(const GameRecipe& recipe) const;
    void updatePerformanceStats() const;
    
    friend class CalculationWorker;
};

/**
 * @brief Worker thread for heavy calculations
 */
class CalculationWorker : public QObject
{
    Q_OBJECT

public:
    CalculationWorker(CalculatorEngine* engine, const CalculatorEngine::CalculationRequest& request);

public slots:
    void calculate();

signals:
    void finished(const CalculatorEngine::CalculationResult& result);
    void progress(int percentage);

private:
    CalculatorEngine* m_engine;
    CalculatorEngine::CalculationRequest m_request;
};

// Hash function for CacheKey
inline uint qHash(const CalculatorEngine::CacheKey& key, uint seed = 0)
{
    return qHash(key.itemClass, seed) ^ qHash(key.amountPerMinute) ^ qHash(key.recipeHash);
} 