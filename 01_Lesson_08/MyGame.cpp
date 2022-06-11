#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <random>
#include <chrono>
#define msleep(msec) usleep(msec*1000)


enum class GameSymbols : char
{
    EMPTY = ' ',
    CROSS = 'X',
    ZERO = 'O'
};

enum TProgress
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

struct TCoord
{
    size_t y{0};
    size_t x{0};
};

#pragma pack(push, 1)
struct TGame
{
    GameSymbols** ppField = nullptr; //Новое игровое поле
    const size_t SIZE = 3;
    TProgress progress = IN_PROGRESS;
    GameSymbols human;
    GameSymbols ai;
    size_t turn = 0U;//ход. Если четные, ходит человек. Нечетные AI
};
#pragma pack(pop)


void clearScr()
{
    clear();
//    system("cls");
//    std::cout << "\x1B[2J\x1B[H";
}

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t>dis(min, max);
    return dis(generator);
}


void __attribute__((fastcall)) initGame(TGame& g)
{
//    clear();
    g.ppField = new GameSymbols* [g.SIZE];
    for (size_t i = 0; i < g.SIZE; ++i)
    {
        g.ppField[i] = new GameSymbols[g.SIZE];
    }

    for (size_t y = 0; y < g.SIZE; ++y)
    {
        for (size_t x = 0; x < g.SIZE; ++x)
        {
            g.ppField[y][x] = GameSymbols::EMPTY;
        }
    }

    if (getRandomNum(0, 1000) > 500)
    {
        g.human = GameSymbols::CROSS; // ходит первый
        g.ai = GameSymbols::ZERO;
        g.turn = 0;
    }    
    else
    {
        g.human = GameSymbols::ZERO;
        g.ai = GameSymbols::CROSS;
        g.turn = 1;
    }
}
void __attribute__((fastcall)) drawGame(const TGame& g)
{
    printw("     ");
    
    for (size_t x = 0; x < g.SIZE; ++x)
    {
        printw("%d", x + 1);
        printw("   ");
    }

    printw("\n"); 
    
    for (size_t y = 0; y < g.SIZE; ++y)
    {
        printw(" %d", y + 1);
        printw(" | ");
        
        for (size_t x = 0; x < g.SIZE; ++x)
        {
            printw("%c", g.ppField[y][x]);
            printw(" | ");
        }
        
        printw("\n"); 
    }

    printw("\nHuman: %c", g.human);
    printw("\nComputer: %c", g.ai);
    printw("\n");
    refresh();

}

void __attribute__((fastcall)) deinitGame(TGame& g)
{
    for (size_t i = 0; i < g.SIZE; ++i)
    {
       delete[] g.ppField[i];
    }
    delete[] g.ppField;
}    

// выиграл ли кто-то?
TProgress __attribute__((fastcall)) getWon(const TGame& g)
{
    // перебираем строки матрицы
    for (size_t y = 0; y < g.SIZE; ++y)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
            {
                return WON_HUMAN;
            }
            
            else if (g.ppField[y][0] == g.ai)
            {
                return WON_AI;
            }
        }
    }
    
    // перебираем столбцы матрицы
    for (size_t x = 0; x < g.SIZE; ++x)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
            {
                return WON_HUMAN;
            }
            
            else if (g.ppField[0][x] == g.ai)
            {
                return WON_AI;
            }
        }
    }

    // проверим диагонали
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[1][1] == g.human)
        {
            return WON_HUMAN;
        }
        
        if (g.ppField[1][1] == g.ai)
        {
            return WON_AI;
        }
    }
    
    if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[2][0])
    {
        if (g.ppField[1][1] == g.human)
        {
            return WON_HUMAN;
        }
        
        if (g.ppField[1][1] == g.ai)
        {
            return WON_AI;
        }

    }

    // проверка на ничью
    bool draw(true);
    for (size_t y = 0; y < g.SIZE; ++y)
    {
        for (size_t x = 0; x < g.SIZE; ++x)
        {
            if (g.ppField[y][x] == GameSymbols::EMPTY)
            {
                draw = false;
                break;
            }
        }

        if (!draw)
        {
            break;
        }
    }
    
    if (draw)
    {
        return DRAW;
    }
    else
    {
        return IN_PROGRESS;
    }
}

// получить координаты куда ходит человек
TCoord __attribute__((fastcall)) getHumanCoord(const TGame& g)
{
    int ch = 0;
    TCoord c;
    do
    {
        printw("\nEnter X (1...3): ");
//        ch = getch();
        scanw("%d", &ch);
        c.x = ch;
        printw("\nEnter Y (1...3): ");
//        ch = getch();
        scanw("%d", &ch);
        c.y = ch;
        c.x--;
        c.y--;

    }
    while (c.x > 2 || c.y > 2 || g.ppField[c.y][c.x] != GameSymbols::EMPTY);

    return c;
}

// получить координаты куда ходит ПК
TCoord __attribute__((fastcall)) getAICoord(TGame& g)
{
    // 1. Pre win situation
    for (size_t y = 0; y < g.SIZE; ++y)
    {
        for (size_t x = 0; x < g.SIZE; ++x)
        {
            if (g.ppField[y][x] == GameSymbols::EMPTY)
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WON_AI)
                {
                    g.ppField[y][x] = GameSymbols::EMPTY;
                    return {y, x};
                }
                g.ppField[y][x] = GameSymbols::EMPTY;
            }
        }
    }
    

    // 2. Pre fail situation - мешает победить человеку
    for (size_t y = 0; y < g.SIZE; ++y)
    {
        for (size_t x = 0; x < g.SIZE; ++x)
        {
            if (g.ppField[y][x] == GameSymbols::EMPTY)
            {
                g.ppField[y][x] = g.human;
                if (getWon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = GameSymbols::EMPTY;
                    return {y, x};
                }
                g.ppField[y][x] = GameSymbols::EMPTY;
            }
        }
    }


    // 1. по приоритетам + рандом
    if (g.ppField[1][1] == GameSymbols::EMPTY)
    {
        return {1, 1};
    }

    TCoord buf[4];
    size_t num = 0;
    
    if (g.ppField[0][0] == GameSymbols::EMPTY)
    {
        buf[num] ={0, 0};
        num++;
    }
    if (g.ppField[2][2] == GameSymbols::EMPTY)
    {
        buf[num] ={2, 2};
        num++;
    }
    if (g.ppField[2][0] == GameSymbols::EMPTY)
    {
        buf[num] ={2, 0};
        num++;
    }
    if (g.ppField[0][2] == GameSymbols::EMPTY)
    {
        buf[num] ={0, 2};
        num++;
    }

    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num; // выбираем случайный угол
        return buf[index];
    }

    // проверяем свободные не углы

    
    if (g.ppField[1][0] == GameSymbols::EMPTY)
    {
        buf[num] ={1, 0};
        num++;
    }
    if (g.ppField[1][2] == GameSymbols::EMPTY)
    {
        buf[num] ={1, 2};
        num++;
    }
    if (g.ppField[0][1] == GameSymbols::EMPTY)
    {
        buf[num] ={0, 1};
        num++;
    }
    if (g.ppField[2][1] == GameSymbols::EMPTY)
    {
        buf[num] ={2, 1};
        num++;
    }

    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num; // выбираем случайный не угол
        return buf[index];
    }
}

void congrats(const TGame& g)
{
    if (g.progress == WON_HUMAN)
    {
        printw("\nWon human =)");
    }
    else if (g.progress == WON_AI)
    {
        printw("\nWon computer =(");
    }
    else
    {
        printw("Draw =/");
    }
}

int main()
{
    initscr();
    nodelay(stdscr, false);
    TGame g;
    initGame(g);
    
    do
    {
        clearScr();
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
    
    } 
    
    while (g.progress == IN_PROGRESS);
    congrats(g);

    deinitGame(g);    

    getch();

    refresh();
    
    endwin();

    return 0;
}
