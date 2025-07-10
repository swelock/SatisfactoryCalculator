#pragma once

#include <QObject>
#include <QString>
#include <QMap>
#include <QVector>
#include <QSet>
#include <QReadWriteLock>
#include "game_data.h"

class RecipeManager : public QObject
{
    Q_OBJECT

public:
    enum class OptimizationGoal {
        MinimizeRawResources,
        MinimizeBuildings,
        MaximizeEfficiency
    };

    explicit RecipeManager(QObject *parent = nullptr);
    
    GameRecipe selectBestRecipe(const QString& itemClass) const;
    void setAlternateRecipe(const QString& itemClass, const QString& recipeClassName);
    void resetAllAlternateRecipes();

private:
    QMap<QString, QString> m_selectedAlternateRecipes;
    OptimizationGoal m_goal = OptimizationGoal::MaximizeEfficiency;
}; 