#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include <QString>
using namespace std;

class Position
{
public:
	Position();
	Position(QString pos, int X, int Y);
	Position(const Position &);
	QString pos_name;
	int x;
	int y;
	~Position();
};

#endif // POSITION_H
