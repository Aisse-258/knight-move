#include <iostream>
#include <QString>
#include <QTextStream>
#include "position_class.h"
using namespace std;
void pos_init(Position **positions, int chessBoardSize) {//генерация таблицы позиций
	for (int i=0;i<chessBoardSize;i++){
		int c='a';
		for (int j=0;j<chessBoardSize;j++){
			positions[i][j].pos_name = c+QString::number(i+1);
			positions[i][j].x = 14 + j*30;
			positions[i][j].y = 223 - i*30;
			//out<<positions[i][j][0]<<"\t"<<positions[i][j][1]<<"\t"<<positions[i][j][2]<<"\t";
			c++;
		}
		//out<<endl;
	}
}
