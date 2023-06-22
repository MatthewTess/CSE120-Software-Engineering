#include "MazeGame.h"

int main(void)
{
    srand((unsigned)time(NULL));

    Player player;
    
    startMazeGame(player);

    return 0;
}
