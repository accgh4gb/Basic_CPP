#pragma once
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <random>
#include <chrono>
#include "MyGamePlayData.h"



void clearScr();

int32_t getRandomNum(int32_t min, int32_t max);

TCoord __attribute__((fastcall)) getHumanCoord(const TGame& g);

void __attribute__((fastcall)) initGame(TGame& g);

TCoord __attribute__((fastcall)) getAICoord(TGame& g);

TProgress __attribute__((fastcall)) getWon(const TGame& g);

void congrats(const TGame& g);

void __attribute__((fastcall)) deinitGame(TGame& g);

void __attribute__((fastcall)) drawGame(const TGame& g);

void GamePlay(TGame& g);
