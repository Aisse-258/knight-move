#include "position_class.h"
#include <iostream>
#include <QString>
using namespace std;

Position::Position()
{

}

Position::Position(QString pos, int X, int Y)
{
	this->pos_name = pos;
	this->x = X;
	this->y = Y;
}

Position::Position(const Position & pos) {
	this->pos_name = pos.pos_name;
	this->x = pos.x;
	this->y = pos.y;
}

Position::~Position()
{

}
