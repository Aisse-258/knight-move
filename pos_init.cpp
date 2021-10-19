#include <iostream>
#include <QString>
#include <QTextStream>
using namespace std;
void pos_init(QString ***positions, int chessBoardSize) {//генерация таблицы позиций
	for (int i=0;i<chessBoardSize;i++){
		int c='a';
		for (int j=0;j<chessBoardSize;j++){
			positions[i][j][0] = c+QString::number(i+1);
			positions[i][j][1] = QString::number(14 + j*30);
			positions[i][j][2] = QString::number(223 - i*30);
			//out<<positions[i][j][0]<<"\t"<<positions[i][j][1]<<"\t"<<positions[i][j][2]<<"\t";
			c++;
		}
		//out<<endl;
	}
}
