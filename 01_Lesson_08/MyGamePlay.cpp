#include "MyGamePlay.h"
//#include "MyGamePlayData.h"


void clearScr()
{
    clear();
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
        refresh();
    }

    printw("\nHuman: %c", g.human);
    printw("\nComputer: %c", g.ai);
    printw("\n");
    refresh();

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
    TCoord tmp;
    // 1. Pre win situation - заботится о своем выигрыше
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
                    tmp.y = y;
                    tmp.x = x;
                    return tmp;
                    //return{y, x}
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
                    //return {y, x}
                    g.ppField[y][x] = GameSymbols::EMPTY;
                    tmp.y = y;
                    tmp.x = x;
                    return tmp;
                }
                g.ppField[y][x] = GameSymbols::EMPTY;
            }
        }
    }


    // 1. по приоритетам + рандом
    if (g.ppField[1][1] == GameSymbols::EMPTY)
    {
        //return {1, 1};
        tmp.y = 1;
        tmp.x = 1;
        return tmp;
    }

    TCoord buf[4];
    size_t num = 0;
    
    if (g.ppField[0][0] == GameSymbols::EMPTY)
    {
        buf[num].y = 0;
        buf[num].x = 0;
        num++;
    }
    
    else if (g.ppField[2][2] == GameSymbols::EMPTY)
    {
        buf[num].y = 2;
        buf[num].x = 2;
        num++;
    }
    
    else if (g.ppField[2][0] == GameSymbols::EMPTY)
    {
        buf[num].y = 2;
        buf[num].x = 0;
        num++;
    }
    
    else if(g.ppField[0][2] == GameSymbols::EMPTY)
    {
        buf[num].y = 0;
        buf[num].x = 2;
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
        buf[num].y = 1;
        buf[num].x = 0;
        num++;
    }
    
    else if (g.ppField[1][2] == GameSymbols::EMPTY)
    {
        buf[num].y = 1;
        buf[num].x = 2;
        num++;
    }
    
    else if (g.ppField[0][1] == GameSymbols::EMPTY)
    {
        buf[num].y = 0;
        buf[num].x = 1;
        num++;
    }
    
    else if(g.ppField[2][1] == GameSymbols::EMPTY)
    {
        buf[num].y = 2;
        buf[num].x = 1;
        num++;
    }

    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num; // выбираем случайный не угол
        return buf[index];
    }
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
                refresh();
                return WON_HUMAN;
            }
            
            else if (g.ppField[y][0] == g.ai)
            {
                refresh();
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
                refresh();
                return WON_HUMAN;
            }
            
            else if (g.ppField[0][x] == g.ai)
            {
                refresh();
                return WON_AI;
            }
        }
    }

    // проверим диагонали
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[1][1] == g.human)
        {
            refresh();
            return WON_HUMAN;
        }
        
        if (g.ppField[1][1] == g.ai)
        {
            refresh();
            return WON_AI;
        }
    }
    
    if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[2][0])
    {
        if (g.ppField[1][1] == g.human)
        {
            refresh();
            return WON_HUMAN;
        }
        
        if (g.ppField[1][1] == g.ai)
        {
            refresh();
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
        refresh();
        return DRAW;
    }
    else
    {
        refresh();
        return IN_PROGRESS;
    }
}

void congrats(const TGame& g)
{
    if (g.progress == WON_HUMAN)
    {
        printw("\nWon human =)\n");
        refresh();
    }
    else if (g.progress == WON_AI)
    {
        printw("\nWon computer =(\n");
        refresh();
    }
    else
    {
        printw("Draw =/\n");
        refresh();
    }
}

void __attribute__((fastcall)) deinitGame(TGame& g)
{
    for (size_t i = 0; i < g.SIZE; ++i)
    {
       delete[] g.ppField[i];
    }
    delete[] g.ppField;
}    

void GamePlay(TGame& g)
{
        clearScr();
        drawGame(g);
    
        if (g.turn & 1)
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

}
