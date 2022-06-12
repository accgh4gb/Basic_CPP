#pragma once
#include <iostream>

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
    size_t y = 0;
    size_t x = 0;
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
