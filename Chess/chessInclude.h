

#pragma once

class Figure;
class MoveInfo;
class King;

#define MAX_INDEX 7
#define SIDE_SIZE MAX_INDEX + 1

typedef enum { BLACK,WHITE } Color;
typedef enum { A,B,C,D,E,F,G,H } CharCoord;


#include <vector>
#include <string>
#include <list>
#include <exception>


using namespace std;

#include "Chessboard.h"
#include "Figure.h"
#include "Figures.h"
#include "MoveInfo.h"
#include "Player.h"
#include "GameManager.h"