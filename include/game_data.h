#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <QString>
#include <QMap>
#include <QList>
#include <QSet>
#include <QMultiMap>
#include <QVector>

// Structure for an ingredient or product in a recipe
struct ItemAmount {
    QString itemClass;
    int amount;
};

// Structure for an item definition
struct GameItem {
    QString name;
    QString className;
    QString description;
};

// Structure for a recipe
struct GameRecipe {
    QString name;
    QString className;
    double time; // Crafting time in seconds
    QVector<ItemAmount> ingredients;
    QVector<ItemAmount> products;
    QString building;
};

// Singleton class to manage loading and accessing all game data
class GameData {
public:
    static GameData& instance();

    const QMap<QString, GameItem>& getItems() const;
    const GameItem& getItem(const QString& className) const;
    bool hasRecipeForItem(const QString& className) const;
    QList<GameRecipe> getRecipesForItem(const QString& className) const;
    QString getItemName(const QString& className) const;

    const QMap<int, QVector<ItemAmount>>& getHubUpgradeRequirements() const;
    const QMap<int, QVector<ItemAmount>>& getElevatorPhaseRequirements() const;

    // Methods to add data
    void addRecipe(const QString& forItem, const GameRecipe& recipe);
    void addHubRequirement(int tier, const QVector<ItemAmount>& requirements);
    void addElevatorRequirement(int phase, const QVector<ItemAmount>& requirements);

private:
    GameData(); // Private constructor
    GameData(const GameData&) = delete;
    void operator=(const GameData&) = delete;

    void loadData(); // Central data loading method
    void populateItems();
    void populateRecipes();

    QMap<QString, GameItem> m_items;
    QMultiMap<QString, GameRecipe> m_recipesByItem; // Maps item className to its primary recipe
    QMap<int, QVector<ItemAmount>> m_hubUpgradeRequirements;
    QMap<int, QVector<ItemAmount>> m_liftPhaseRequirements;
};

#endif // GAME_DATA_H 