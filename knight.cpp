#include <iostream>
#include <QString>
#include <QTextStream>
#include "pos_init.h"
using namespace std;
QTextStream out(stdout);
const int chessBoardSize = 8;
int chessBoard [chessBoardSize][chessBoardSize] = {0};
QString ***positions;
QString **stepPositions;//здесь будет путь
int knight (QString pos1, QString pos2) {
	positions = new QString **[chessBoardSize];
	for(int i=0; i<chessBoardSize;i++) {
		positions[i] = new QString *[chessBoardSize];
		for (int j=0;j<chessBoardSize;j++) {
			positions[i][j] = new QString [3];
		}
	}
	pos_init(positions, chessBoardSize);
	if (pos1.length() != 2 || pos2.length() != 2 ||
		QString::compare(pos1, positions[0][0][0]) < 0 || QString::compare(pos1, positions[7][7][0]) > 0 ||
		QString::compare(pos2, positions[0][0][0]) < 0 || QString::compare(pos2, positions[7][7][0]) > 0 ) {
		return -1;//если введенные строки не являются позициями, -1
	}
	int step = 0;
	int i,j;
	if (QString::compare(pos1, pos2) == 0) {//если позиции равны
		stepPositions = new QString *[step+1];//путь состоит из одной позиции
		stepPositions[0] = new QString [3];
		stepPositions[0][0] = pos1;
		for (i=0;i<chessBoardSize;i++){//всё равно сохраняем координаты первой позиции, чтобы отобразить там коня
			for (j=0; j<chessBoardSize; j++){
				if (QString::compare(pos1, positions[i][j][0]) == 0) {
					stepPositions[0][1] = positions[i][j][1];
					stepPositions[0][2] = positions[i][j][2];
					chessBoard[i][j] = 9999;
				}
				else {
					chessBoard[i][j] = -1;
				}
			}
		}
		return step;
	}
	int pos_i1, pos_j1, pos_i2, pos_j2;
	for (i=0;i<chessBoardSize;i++){//отметили начальную и конечную позиции на доске
		for (j=0; j<chessBoardSize; j++){
			if (QString::compare(pos1, positions[i][j][0]) == 0) {
				pos_i1 = i;
				pos_j1 = j;
				chessBoard[i][j] = 0;
			}
			else if (QString::compare(pos2, positions[i][j][0]) == 0) {
				chessBoard[i][j] = 9999;
				pos_i2 = i;//запоминаем, где конец, чтобы строить то него путь обратно
				pos_j2 = j;
			}
			else {
				chessBoard[i][j] = -1;
			}
		}
	}
	bool came = false;
	do {
		step++;
		for (i=0;i<chessBoardSize;i++){
			for (j=0; j<chessBoardSize; j++){
				if (chessBoard[i][j] == step-1) {//находим точку из предыдущего шага
					if(i+1<8 && j+2<8){//пробуем сделать ход
						if (chessBoard[i+1][j+2] == 9999) {//если приходим в конечную точку, готово
							came = true;
							break;
						}
						else if (chessBoard[i+1][j+2] == -1){//если нет, и там ещё не были, ставим там новую точку
							chessBoard[i+1][j+2] = step;
						}
					}
					if(i-1>=0 && j+2<8){//и так во все стороны, пока точки не закончатся или мы не придём куда надо
						if (chessBoard[i-1][j+2] == 9999) {
							came = true;
							break;
						}
						else if (chessBoard[i-1][j+2] == -1){
							chessBoard[i-1][j+2] = step;
						}
					}
					if(i-2>=0 && j+1<8){
						if (chessBoard[i-2][j+1] == 9999) {
							came = true;
							break;
						}
						else if (chessBoard[i-2][j+1] == -1){
							chessBoard[i-2][j+1] = step;
						}
					}
					if(i-2>=0 && j-1>=0){
						if (chessBoard[i-2][j-1] == 9999) {
							came = true;
							break;
						}
						else if (chessBoard[i-2][j-1] == -1){
							chessBoard[i-2][j-1] = step;
						}
					}
					if(i-1>=0 && j-2>=0){
						if (chessBoard[i-1][j-2] == 9999) {
							came = true;
							break;
						}
						else if (chessBoard[i-1][j-2] == -1){
							chessBoard[i-1][j-2] = step;
						}
					}
					if(i+1<8 && j-2>=0){
						if (chessBoard[i+1][j-2] == 9999) {
							came = true;
							break;
						}
						else if (chessBoard[i+1][j-2] == -1){
							chessBoard[i+1][j-2] = step;
						}
					}
					if(i+2<8 && j-1>=0){
						if (chessBoard[i+2][j-1] == 9999) {
							came = true;
							break;
						}
						else if (chessBoard[i+2][j-1] == -1){
							chessBoard[i+2][j-1] = step;
						}
					}
					if(i+2<8 && j+1<8){
						if (chessBoard[i+2][j+1] == 9999) {
							came = true;
							break;
						}
						else if (chessBoard[i+2][j+1] == -1){
							chessBoard[i+2][j+1] = step;
						}
					}
				}
			}
		}
		/*for (i=0; i<chessBoardSize; i++){
			for (j=0; j<chessBoardSize; j++){
				cout<<chessBoard[i][j]<<"\t";
			}
			cout<<endl;
		}*/
	}
	while(!came);
	for (i=0; i<chessBoardSize; i++){
		for (j=0; j<chessBoardSize; j++){
			out<<chessBoard[i][j]<<"\t";
		}
		out<<endl;
	}
	stepPositions = new QString*[step + 1];
	for(i=0;i<step + 1;i++){
		stepPositions[i] = new QString[3];
	}
	stepPositions[0][0] = pos1;//сохраняем начало и конец пути
	stepPositions[0][1] = positions[pos_i1][pos_j1][1];
	stepPositions[0][2] = positions[pos_i1][pos_j1][2];
	stepPositions[step][0] = pos2;
	stepPositions[step][1] = positions[pos_i2][pos_j2][1];
	stepPositions[step][2] = positions[pos_i2][pos_j2][2];
	if (step == 1) {
		return step;
	}
	int stepBack = step;
	do{
		stepBack--;
		if(pos_i2+1<8 && pos_j2+2<8){//ищем возможный предыдущий шаг
			if (chessBoard[pos_i2+1][pos_j2+2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2+1][pos_j2+2] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2+1][pos_j2+2][0];//если нашли, помещаем его в список шагов
				stepPositions[stepBack][1] = positions[pos_i2+1][pos_j2+2][1];
				stepPositions[stepBack][2] = positions[pos_i2+1][pos_j2+2][2];
				pos_i2 = pos_i2+1;//следующий будем искать с этой точки
				pos_j2 = pos_j2+2;
				continue;
			}
		}
		if(pos_i2-1>=0 && pos_j2+2<8){
			if (chessBoard[pos_i2-1][pos_j2+2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2-1][pos_j2+2] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2-1][pos_j2+2][0];
				stepPositions[stepBack][1] = positions[pos_i2-1][pos_j2+2][1];
				stepPositions[stepBack][2] = positions[pos_i2-1][pos_j2+2][2];
				pos_i2 = pos_i2-1;
				pos_j2 = pos_j2+2;
				continue;
			}
		}
		if(pos_i2-2>=0 && pos_j2+1<8){
			if (chessBoard[pos_i2-2][pos_j2+1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2-2][pos_j2+1] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2-2][pos_j2+1][0];
				stepPositions[stepBack][1] = positions[pos_i2-2][pos_j2+1][1];
				stepPositions[stepBack][2] = positions[pos_i2-2][pos_j2+1][2];
				pos_i2 = pos_i2-2;
				pos_j2 = pos_j2+1;
				continue;
			}
		}
		if(pos_i2-2>=0 && pos_j2-1>=0){
			if (chessBoard[pos_i2-2][pos_j2-1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2-2][pos_j2-1] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2-2][pos_j2-1][0];
				stepPositions[stepBack][1] = positions[pos_i2-2][pos_j2-1][1];
				stepPositions[stepBack][2] = positions[pos_i2-2][pos_j2-1][2];
				pos_i2 = pos_i2-2;
				pos_j2 = pos_j2-1;
				continue;
			}
		}
		if(pos_i2-1>=0 && pos_j2-2>=0){
			if (chessBoard[pos_i2-1][pos_j2-2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2-1][pos_j2-2] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2-1][pos_j2-2][0];
				stepPositions[stepBack][1] = positions[pos_i2-1][pos_j2-2][1];
				stepPositions[stepBack][2] = positions[pos_i2-1][pos_j2-2][2];
				pos_i2 = pos_i2-1;
				pos_j2 = pos_j2-2;
				continue;
			}
		}
		if(pos_i2+1<8 && pos_j2-2>=0){
			if (chessBoard[pos_i2+1][pos_j2-2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2+1][pos_j2-2] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2+1][pos_j2-2][0];
				stepPositions[stepBack][1] = positions[pos_i2+1][pos_j2-2][1];
				stepPositions[stepBack][2] = positions[pos_i2+1][pos_j2-2][2];
				pos_i2 = pos_i2+1;
				pos_j2 = pos_j2-2;
				continue;
			}
		}
		if(pos_i2+2<8 && pos_j2-1>=0){
			if (chessBoard[pos_i2+2][pos_j2-1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2+2][pos_j2-1] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2+2][pos_j2-1][0];
				stepPositions[stepBack][1] = positions[pos_i2+2][pos_j2-1][1];
				stepPositions[stepBack][2] = positions[pos_i2+2][pos_j2-1][2];
				pos_i2 = pos_i2+2;
				pos_j2 = pos_j2-1;
				continue;
			}
		}
		if(pos_i2+2<8 && pos_j2+1<8){
			if (chessBoard[pos_i2+2][pos_j2+1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i][0]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i2+2][pos_j2+1] == stepBack){
				stepPositions[stepBack][0] = positions[pos_i2+2][pos_j2+1][0];
				stepPositions[stepBack][1] = positions[pos_i2+2][pos_j2+1][1];
				stepPositions[stepBack][2] = positions[pos_i2+2][pos_j2+1][2];
				pos_i2 = pos_i2+2;
				pos_j2 = pos_j2+1;
				continue;
			}
		}
	}
	while (stepBack > 0);
	return 0;//на всякий случай
}
