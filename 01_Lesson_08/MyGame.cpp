//#include <iostream>
//#include <ncurses.h>
//#include <unistd.h>
//#include <random>
//#include <chrono>
#include "MyGamePlay.h"
#include "MyGamePlayData.h"
#include <curses.h>
#define msleep(msec) usleep(msec*1000)


int main()
{
    initscr();
    nodelay(stdscr, false);
    TGame g;
//    initGame(g);
    refresh();    
    
    char iCommand = '\0';
    do
    {
        printw("Press 'N/n' for new game \n");
        printw("\nPress 'ESC/q/e' for exit");
        iCommand = getch();
        refresh();
        switch (iCommand)
        {
            case 'N':
            case 'n':
            {    
                initGame(g);
    
                do
                {
                    GamePlay(g);
                } 
    
                while (g.progress == IN_PROGRESS);

                deinitGame(g);    
                congrats(g);
                refresh();
                break; 
            }
        
            case 27:
            case 'q':
            case 'e':
            {   
                printw("\nBye, bye!\nSee you next time.\n");
                refresh();
		        msleep(3000);
                break;
            }
            default:
                printw("Please, try again.");
                break;
        }
    }
    while (iCommand != 27);

    refresh();
    
    endwin();

    return 0;
}
