//#include <iostream>
//#include <ncurses.h>
//#include <unistd.h>
//#include <random>
//#include <chrono>
#include "MyGamePlay.h"
#include "MyGamePlayData.h"
//#define msleep(msec) usleep(msec*1000)


int main()
{
    initscr();
    nodelay(stdscr, false);
    TGame g;
    initGame(g);
    
    do
    {
        GamePlay(g);
/*        clearScr();
        drawGame(g);
    
        if (g.turn % 2 == 0)
        {
            TCoord c = getHumanCoord(g);
            g.ppField[c.y][c.x] = g.human;    
        }
        else
        {
            TCoord c = getAICoord(g);
            g.ppField[c.y][c.x] = g.ai;    
        }
    
        g.turn++;
    
        g.progress = getWon(g);    
        refresh(); 
 */
    } 
    
    while (g.progress == IN_PROGRESS);

    congrats(g);

    deinitGame(g);    

    getch();

//    refresh();
    
    endwin();

    return 0;
}
