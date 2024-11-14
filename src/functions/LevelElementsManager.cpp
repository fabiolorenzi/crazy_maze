#include "LevelElementsManager.h"

unsigned int SetLevelInitialTimer(LevelNumber levelNumber)
{
    if (levelNumber == LevelNumber::LevelOne) {
        return 99;
    }
    
    return 0;
}

void PopulateWallsInMazeArray(LevelNumber levelNumber, Wall* wallsArray[50], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        wallsArray[0] = new Wall(0, (height / 2) - 10, width * 10, 10, 0x8B, 0x45, 0x13, 0x00);
        wallsArray[1] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(-920, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(-940, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[4] = new Wall(-960, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[5] = new Wall(-980, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[6] = new Wall(-1000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[7] = new Wall(-1200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[8] = new Wall(-1400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[9] = new Wall(-1600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[10] = new Wall(-1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[11] = new Wall(-2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[12] = new Wall(-2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[13] = new Wall(-2400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[14] = new Wall(-2600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[15] = new Wall(-2800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[16] = new Wall(-3000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[17] = new Wall(-3200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[18] = new Wall(1000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[19] = new Wall(1200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[20] = new Wall(1300, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[21] = new Wall(1400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[22] = new Wall(1500, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[23] = new Wall(1600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[24] = new Wall(1700, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[25] = new Wall(1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[26] = new Wall(1900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[27] = new Wall(2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[28] = new Wall(2100, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[29] = new Wall(2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[30] = new Wall(-1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[31] = new Wall(-2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[32] = new Wall(-2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[33] = new Wall(-2400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[34] = new Wall(-2600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[35] = new Wall(-2800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[36] = new Wall(-3000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[37] = new Wall(-3200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[38] = new Wall(1000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[39] = new Wall(1200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[40] = new Wall(1300, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[41] = new Wall(1400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[42] = new Wall(1500, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[43] = new Wall(1600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[44] = new Wall(1700, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[45] = new Wall(1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[46] = new Wall(1900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[47] = new Wall(2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[48] = new Wall(2100, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[49] = new Wall(2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
    } else if (levelNumber == LevelNumber::LevelTwo) {
        wallsArray[0] = new Wall(0, (height / 2) - 10, width * 10, 10, 0x8B, 0x45, 0x13, 0x00);
        wallsArray[1] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[4] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[5] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[6] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[7] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[8] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[9] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[10] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[11] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[12] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[13] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[14] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[15] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[16] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[17] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[18] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[19] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[20] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[21] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[22] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[23] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[24] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[25] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[26] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[27] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[28] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[29] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[30] = new Wall(-1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[31] = new Wall(-2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[32] = new Wall(-2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[33] = new Wall(-2400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[34] = new Wall(-2600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[35] = new Wall(-2800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[36] = new Wall(-3000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[37] = new Wall(-3200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[38] = new Wall(1000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[39] = new Wall(1200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[40] = new Wall(1300, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[41] = new Wall(1400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[42] = new Wall(1500, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[43] = new Wall(1600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[44] = new Wall(1700, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[45] = new Wall(1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[46] = new Wall(1900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[47] = new Wall(2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[48] = new Wall(2100, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[49] = new Wall(2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
    } else if (levelNumber == LevelNumber::LevelThree) {
        wallsArray[0] = new Wall(0, (height / 2) - 10, width * 10, 10, 0x8B, 0x45, 0x13, 0x00);
        wallsArray[1] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[4] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[5] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[6] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[7] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[8] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[9] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[10] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[11] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[12] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[13] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[14] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[15] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[16] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[17] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[18] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[19] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[20] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[21] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[22] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[23] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[24] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[25] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[26] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[27] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[28] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[29] = new Wall(-900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[30] = new Wall(-1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[31] = new Wall(-2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[32] = new Wall(-2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[33] = new Wall(-2400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[34] = new Wall(-2600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[35] = new Wall(-2800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[36] = new Wall(-3000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[37] = new Wall(-3200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[38] = new Wall(1000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[39] = new Wall(1200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[40] = new Wall(1300, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[41] = new Wall(1400, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[42] = new Wall(1500, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[43] = new Wall(1600, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[44] = new Wall(1700, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[45] = new Wall(1800, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[46] = new Wall(1900, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[47] = new Wall(2000, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[48] = new Wall(2100, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[49] = new Wall(2200, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00);
    }
}

void PopulateEnemiesInMazeArray(LevelNumber levelNumber, Enemy* enemiesArray[10], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        enemiesArray[0] = new Enemy(200, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[1] = new Enemy(300, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 1);
        enemiesArray[2] = new Enemy(1000, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 2);
        enemiesArray[3] = new Enemy(1100, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 6);
        enemiesArray[4] = new Enemy(1200, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
        enemiesArray[5] = new Enemy(1200, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[6] = new Enemy(1300, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 1);
        enemiesArray[7] = new Enemy(1400, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 2);
        enemiesArray[8] = new Enemy(1500, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 6);
        enemiesArray[9] = new Enemy(1600, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
    } else if (levelNumber == LevelNumber::LevelTwo) {
        enemiesArray[0] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[1] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[2] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[3] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[4] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[5] = new Enemy(1200, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[6] = new Enemy(1300, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 1);
        enemiesArray[7] = new Enemy(1400, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 2);
        enemiesArray[8] = new Enemy(1500, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 6);
        enemiesArray[9] = new Enemy(1600, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
    } else if (levelNumber == LevelNumber::LevelThree) {
        enemiesArray[0] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[1] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[2] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[3] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[4] = new Enemy(-900, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[5] = new Enemy(1200, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[6] = new Enemy(1300, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 1);
        enemiesArray[7] = new Enemy(1400, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 2);
        enemiesArray[8] = new Enemy(1500, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 6);
        enemiesArray[9] = new Enemy(1600, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
    }
}

void PopulateObjectsInMazeArray(LevelNumber levelNumber, CatchableObject* objectsArray[5], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        objectsArray[0] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::LifeObject);
        objectsArray[1] = new CatchableObject(-100, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[2] = new CatchableObject(-1100, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[3] = new CatchableObject(-1200, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[4] = new CatchableObject(-1900, height - 450, 40, 40, ObjectType::VictoryObject);
    } else if (levelNumber == LevelNumber::LevelTwo) {
        objectsArray[0] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::LifeObject);
        objectsArray[1] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[2] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[3] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[4] = new CatchableObject(-900, height - 450, 40, 40, ObjectType::VictoryObject);
    } else if (levelNumber == LevelNumber::LevelThree) {
        objectsArray[0] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::LifeObject);
        objectsArray[1] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[2] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[3] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[4] = new CatchableObject(-900, height - 450, 40, 40, ObjectType::VictoryObject);
    }
}