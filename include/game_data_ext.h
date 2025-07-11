#ifndef GAME_DATA_EXT_H
#define GAME_DATA_EXT_H

#include "game_data.h"

// Forward declaration
class GameData;

void populateAlternateRecipes(GameData& gameData);
void populateHubRequirements(GameData& gameData);
void populateElevatorRequirements(GameData& gameData);

#endif // GAME_DATA_EXT_H 