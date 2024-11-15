#include "LevelElementsManager.h"

unsigned int SetLevelInitialTimer(LevelNumber levelNumber)
{
    if (levelNumber == LevelNumber::LevelOne) {
        return 150;
    } else if (levelNumber == LevelNumber::LevelTwo) {
        return 120;
    } else if (levelNumber == LevelNumber::LevelThree) {
        return 999;
    }
    
    return 0;
}

void PopulateWallsInMazeArray(LevelNumber levelNumber, Wall* wallsArray[50], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        wallsArray[0] = new Wall(0, (height / 2) - 10, width * 5, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[1] = new Wall(560, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(700, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(840, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[4] = new Wall(980, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[5] = new Wall(990, (height / 2) - 90, 310, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[6] = new Wall(1300, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[7] = new Wall(1440, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[8] = new Wall(1450, 80, 240, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[9] = new Wall(1800, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[10] = new Wall(2400, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[11] = new Wall(2540, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[12] = new Wall(2680, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[13] = new Wall(2820, (height / 3 ) + 10, 10, 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[14] = new Wall(2820, 0, 10, 180, 0x80, 0x80, 0x80, 0x00);
        wallsArray[15] = new Wall(2960, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[16] = new Wall(3040, 80, 1000, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[17] = new Wall(3040, 90, 10, (height / 2) - 170, 0x80, 0x80, 0x80, 0x00);
        wallsArray[18] = new Wall(3040, (height / 2) - 80, 190, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[19] = new Wall(3300, 160, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[20] = new Wall(3130, 150, 180, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[21] = new Wall(3380, 80, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[22] = new Wall(3460, 160, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[23] = new Wall(3460, 160, 400, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[24] = new Wall(3940, 80, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[25] = new Wall(4030, 0, 10, 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[26] = new Wall(4030, 160, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[27] = new Wall(4100, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[28] = new Wall(4160, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[29] = new Wall(4210, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[30] = new Wall(4210, (height / 2) - 80, 360, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[31] = new Wall(4660, (height / 2) - 80, 650, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[32] = new Wall(4660, 80, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[33] = new Wall(4300, 170, 360, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[34] = new Wall(4740, 0, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[35] = new Wall(4220, 80, 380, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[36] = new Wall(4840, 80, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[37] = new Wall(4940, 0, 10, (height / 2) - 120, 0x80, 0x80, 0x80, 0x00);
        wallsArray[38] = new Wall(5000, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[39] = new Wall(5060, 0, 10, (height / 2) - 120, 0x80, 0x80, 0x80, 0x00);
        wallsArray[40] = new Wall(5060, (height / 2) - 130, 320, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[41] = new Wall(5380, 0, 10, (height / 2) - 60, 0x80, 0x80, 0x80, 0x00);
        wallsArray[42] = new Wall(5500, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[43] = new Wall(5700, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[44] = new Wall(5760, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[45] = new Wall(5840, 80, 500, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[46] = new Wall(5840, 160, 320, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[47] = new Wall(6240, 160, 100, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[48] = new Wall(5840, 240, 500, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[49] = new Wall((width * 5) + 60, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
    } else if (levelNumber == LevelNumber::LevelTwo) {
        wallsArray[0] = new Wall(0, (height / 2) - 10, width * 5, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[1] = new Wall(-60, 0, 10, (height / 2), 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(-10, (height / 2) - 10, 10, 60, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(-120, (height / 2) + 50, 120, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[4] = new Wall(-120, (height / 2), 10, 60, 0x80, 0x80, 0x80, 0x00);
        wallsArray[5] = new Wall(-300, (height / 2) - 10, 190, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[6] = new Wall(-310, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[7] = new Wall(800, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[8] = new Wall(880, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[9] = new Wall(960, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[10] = new Wall(1040, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[11] = new Wall(1120, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[12] = new Wall(1200, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[13] = new Wall(1280, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[14] = new Wall(1360, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[15] = new Wall(1360, (height / 2) - 90, 240, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[16] = new Wall(1600, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[17] = new Wall(1680, (height / 2) - 80, 10, 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[18] = new Wall(1680, (height / 2) - 80, 200, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[19] = new Wall(1880, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[20] = new Wall(1600, (height / 2) - 160, 200, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[21] = new Wall(1680, (height / 2) - 240, 200, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[22] = new Wall(1600, 50, 200, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[23] = new Wall(1940, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[24] = new Wall(2020, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[25] = new Wall(2500, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[26] = new Wall(2700, (height / 2) - 80, 500, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[27] = new Wall(2780, (height / 2) - 160, 420, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[28] = new Wall(2860, (height / 2) - 240, 340, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[29] = new Wall(2940, 50, 260, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[30] = new Wall(3480, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[31] = new Wall(3600, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[32] = new Wall(3720, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[33] = new Wall(3840, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[34] = new Wall(5000, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[35] = new Wall(5100, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[36] = new Wall(5200, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[37] = new Wall(5300, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[38] = new Wall(5400, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[39] = new Wall(5500, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[40] = new Wall(5600, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[41] = new Wall(5700, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[42] = new Wall(5800, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[43] = new Wall(5900, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[44] = new Wall(320, 40, 10, height, 0x80, 0x80, 0x80, 0x00);
        wallsArray[45] = new Wall(4100, 240, 10, (height / 2) - 240, 0x80, 0x80, 0x80, 0x00);
        wallsArray[46] = new Wall(4140, 160, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[47] = new Wall(4180, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[48] = new Wall(4220, 160, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[49] = new Wall(4260, 240, 10, (height / 2) - 240, 0x80, 0x80, 0x80, 0x00);
    } else if (levelNumber == LevelNumber::LevelThree) {
        wallsArray[0] = new Wall(0, (height / 2) - 10, width * 3, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[1] = new Wall(500, (height / 2) - 80, 10, 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[2] = new Wall(500, (height / 2) - 80, 400, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[3] = new Wall(900, (height / 2) - 160, 10, 90, 0x80, 0x80, 0x80, 0x00);
        wallsArray[4] = new Wall(980, (height / 2) - 240, 10, 240, 0x80, 0x80, 0x80, 0x00);
        wallsArray[5] = new Wall(500, (height / 2) - 160, 400, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[6] = new Wall(580, (height / 2) - 240, 400, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[7] = new Wall(500, 0, 10, 210, 0x80, 0x80, 0x80, 0x00);
        wallsArray[8] = new Wall(1060, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[9] = new Wall(1060, (height / 2) - 80, 400, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[10] = new Wall(1460, 0, 10, (height / 2) - 70, 0x80, 0x80, 0x80, 0x00);
        wallsArray[11] = new Wall(1540, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[12] = new Wall(1620, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[13] = new Wall(1700, 80, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[14] = new Wall(1780, 0, 10, (height / 2) - 80, 0x80, 0x80, 0x80, 0x00);
        wallsArray[15] = new Wall(1780, (height / 2) - 80, 500, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[16] = new Wall(1860, (height / 2) - 160, 420, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[17] = new Wall(1780, (height / 2) - 240, 500, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[18] = new Wall(2380, (height / 2) - 300, 10, (height / 2) - 70, 0x80, 0x80, 0x80, 0x00);
        wallsArray[19] = new Wall(1860, (height / 2) - 300, 530, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[20] = new Wall(2440, 0, 10, (height / 2) - 60, 0x80, 0x80, 0x80, 0x00);
        wallsArray[21] = new Wall(2500, 0, 10, (height / 2) - 60, 0x80, 0x80, 0x80, 0x00);
        wallsArray[22] = new Wall(2560, 40, 10, (height / 2) - 50, 0x80, 0x80, 0x80, 0x00);
        wallsArray[23] = new Wall(2620, 0, 10, (height / 2) - 60, 0x80, 0x80, 0x80, 0x00);
        wallsArray[24] = new Wall(2620, (height / 2) - 60, 400, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[25] = new Wall(2680, 0, 10, (height / 2) - 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[26] = new Wall(2740, 0, 10, (height / 2) - 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[27] = new Wall(2800, 0, 10, (height / 2) - 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[28] = new Wall(2860, 0, 10, (height / 2) - 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[29] = new Wall(2920, 0, 10, (height / 2) - 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[30] = new Wall(3080, 0, 10, (height / 2) - 60, 0x80, 0x80, 0x80, 0x00);
        wallsArray[31] = new Wall(3080, (height / 2) - 60, 500, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[32] = new Wall(2980, 0, 10, (height / 2) - 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[33] = new Wall(3640, 50, 10, (height / 2) - 50, 0x80, 0x80, 0x80, 0x00);
        wallsArray[34] = new Wall(3700, 50, 10, (height / 2) - 100, 0x80, 0x80, 0x80, 0x00);
        wallsArray[35] = new Wall(3340, (height / 2) - 110, 300, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[36] = new Wall(3280, (height / 2) - 160, 300, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[37] = new Wall(3340, (height / 2) - 210, 300, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[38] = new Wall(3280, (height / 2) - 260, 300, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[39] = new Wall(3280, 100, 10, (height / 2) - 150, 0x80, 0x80, 0x80, 0x00);
        wallsArray[40] = new Wall(3230, 60, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[41] = new Wall(3180, 100, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[42] = new Wall(3130, 50, 10, (height / 2) - 160, 0x80, 0x80, 0x80, 0x00);
        wallsArray[43] = new Wall(3700, (height / 2) - 60, 140, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[44] = new Wall(3130, 50, 580, 10, 0x80, 0x80, 0x80, 0x00);
        wallsArray[45] = new Wall(400, 0, 10, (height / 2) - 50, 0x80, 0x80, 0x80, 0x00);
        wallsArray[46] = new Wall(300, 50, 10, (height / 2) - 50, 0x80, 0x80, 0x80, 0x00);
        wallsArray[47] = new Wall(200, 0, 10, (height / 2) - 50, 0x80, 0x80, 0x80, 0x00);
        wallsArray[48] = new Wall(0, 50, 10, (height / 2) - 50, 0x80, 0x80, 0x80, 0x00);
        wallsArray[49] = new Wall(-100, 0, 10, height, 0x80, 0x80, 0x80, 0x00);
    }
}

void PopulateEnemiesInMazeArray(LevelNumber levelNumber, Enemy* enemiesArray[10], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        enemiesArray[0] = new Enemy(2460, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[1] = new Enemy(2880, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[2] = new Enemy(3880, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 7);
        enemiesArray[3] = new Enemy(4170, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
        enemiesArray[4] = new Enemy(4955, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[5] = new Enemy(5715, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
        enemiesArray[6] = new Enemy(5920, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[7] = new Enemy(6040, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[8] = new Enemy(6160, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[9] = new Enemy(6420, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
    } else if (levelNumber == LevelNumber::LevelTwo) {
        enemiesArray[0] = new Enemy(-220, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[1] = new Enemy(-50, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[2] = new Enemy(1065, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[3] = new Enemy(1965, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
        enemiesArray[4] = new Enemy(2720, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[5] = new Enemy(2860, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[6] = new Enemy(3000, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[7] = new Enemy(3200, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[8] = new Enemy(3765, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 15);
        enemiesArray[9] = new Enemy(4320, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
    } else if (levelNumber == LevelNumber::LevelThree) {
        enemiesArray[0] = new Enemy(1640, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 3);
        enemiesArray[1] = new Enemy(2160, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[2] = new Enemy(2750, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[3] = new Enemy(2935, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[4] = new Enemy(3360, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 9);
        enemiesArray[5] = new Enemy(3460, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[6] = new Enemy(3760, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 10);
        enemiesArray[7] = new Enemy(1260, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[8] = new Enemy(530, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
        enemiesArray[9] = new Enemy(850, height - 50, 40, 40, 0x00, 0x00, 0xFF, 0xFF, width, height, 5);
    }
}

void PopulateObjectsInMazeArray(LevelNumber levelNumber, CatchableObject* objectsArray[5], int width, int height)
{
    if (levelNumber == LevelNumber::LevelOne) {
        objectsArray[0] = new CatchableObject(3500, (height / 2) - 80, 40, 40, ObjectType::LifeObject);
        objectsArray[1] = new CatchableObject(3960, 20, 40, 40, ObjectType::TimeObject);
        objectsArray[2] = new CatchableObject(6260, (height / 4) - 75, 40, 40, ObjectType::TimeObject);
        objectsArray[3] = new CatchableObject(4920, (height / 2) - 60, 40, 40, ObjectType::LifeObject);
        objectsArray[4] = new CatchableObject(5715, (height / 2) + 10, 40, 40, ObjectType::VictoryObject);
    } else if (levelNumber == LevelNumber::LevelTwo) {
        objectsArray[0] = new CatchableObject(2440, (height / 2) - 230, 40, 40, ObjectType::LifeObject);
        objectsArray[1] = new CatchableObject(3140, 5, 40, 40, ObjectType::TimeObject);
        objectsArray[2] = new CatchableObject(3650, 10, 40, 40, ObjectType::LifeObject);
        objectsArray[3] = new CatchableObject(4165, 10, 40, 40, ObjectType::TimeObject);
        objectsArray[4] = new CatchableObject(-260, (height / 2) - 70, 40, 40, ObjectType::VictoryObject);
    } else if (levelNumber == LevelNumber::LevelThree) {
        objectsArray[0] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::LifeObject);
        objectsArray[1] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[2] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[3] = new CatchableObject(-900, height - 150, 40, 40, ObjectType::TimeObject);
        objectsArray[4] = new CatchableObject(-900, height - 450, 40, 40, ObjectType::VictoryObject);
    }
}