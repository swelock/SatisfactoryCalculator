#include "recipe_manager.h"

RecipeManager::RecipeManager(QObject *parent)
    : QObject(parent)
{
    // Initialize default settings
}

GameRecipe RecipeManager::selectBestRecipe(const QString& itemClass) const
{
    // Get available recipes for the item
    QList<GameRecipe> recipes = GameData::instance().getRecipesForItem(itemClass);
    
    if (!recipes.isEmpty()) {
        // For now, return the first recipe (default recipe)
        return recipes.first();
    }
    
    // Return empty recipe if none found
    return GameRecipe();
}

void RecipeManager::setAlternateRecipe(const QString& itemClass, const QString& recipeClassName)
{
    m_selectedAlternateRecipes[itemClass] = recipeClassName;
}

void RecipeManager::resetAllAlternateRecipes()
{
    m_selectedAlternateRecipes.clear();
} 