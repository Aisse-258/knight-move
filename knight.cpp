#include <iostream>
#include <QString>
#include <QTextStream>
using namespace std;
QTextStream out(stdout);
const int chessBoardSize = 8;
int chessBoard [chessBoardSize][chessBoardSize] = {0};
const QString positions [chessBoardSize][chessBoardSize] = {
	{"a1","b1","c1","d1","e1","f1","g1","h1"},
	{"a2","b2","c2","d2","e2","f2","g2","h2"},
	{"a3","b3","c3","d3","e3","f3","g3","h3"},
	{"a4","b4","c4","d4","e4","f4","g4","h4"},
	{"a5","b5","c5","d5","e5","f5","g5","h5"},
	{"a6","b6","c6","d6","e6","f6","g6","h6"},
	{"a7","b7","c7","d7","e7","f7","g7","h7"},
	{"a8","b8","c8","d8","e8","f8","g8","h8"}
};
QString *stepPositions;
int knight (QString pos1, QString pos2) {
	int step = 0;
	if (QString::compare(pos1, pos2) == 0) return step;
	int i,j;
	int pos_i, pos_j;
	for (i=0;i<chessBoardSize;i++){//отметили начальную и конечную позиции на доске
		for (j=0; j<chessBoardSize; j++){
			if (QString::compare(pos1, positions[i][j]) == 0) {
				chessBoard[i][j] = 0;
			}
			else if (QString::compare(pos2, positions[i][j]) == 0) {
				chessBoard[i][j] = 9999;
				pos_i = i;//запоминаем, где конец, чтобы строить то него путь обратно
				pos_j = j;
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
	stepPositions = new QString[step + 1];
	stepPositions[0] = pos1;
	stepPositions[step] = pos2;
	if (step == 1) {
		return step;
	}
	int stepBack = step;
	do{
		stepBack--;
		if(pos_i+1<8 && pos_j+2<8){//ищем возможный предыдущий шаг
			if (chessBoard[pos_i+1][pos_j+2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i+1][pos_j+2] == stepBack){
				stepPositions[stepBack] = positions[pos_i+1][pos_j+2];//если нашли, помещаем его в список шагов
				pos_i = pos_i+1;//следующий будем искать с этой точки
				pos_j = pos_j+2;
				continue;
			}
		}
		if(pos_i-1>=0 && pos_j+2<8){
			if (chessBoard[pos_i-1][pos_j+2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i-1][pos_j+2] == stepBack){
				stepPositions[stepBack] = positions[pos_i-1][pos_j+2];
				pos_i = pos_i-1;
				pos_j = pos_j+2;
				continue;
			}
		}
		if(pos_i-2>=0 && pos_j+1<8){
			if (chessBoard[pos_i-2][pos_j+1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i-2][pos_j+1] == stepBack){
				stepPositions[stepBack] = positions[pos_i-2][pos_j+1];
				pos_i = pos_i-2;
				pos_j = pos_j+1;
				continue;
			}
		}
		if(pos_i-2>=0 && pos_j-1>=0){
			if (chessBoard[pos_i-2][pos_j-1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i-2][pos_j-1] == stepBack){
				stepPositions[stepBack] = positions[pos_i-2][pos_j-1];
				pos_i = pos_i-2;
				pos_j = pos_j-1;
				continue;
			}
		}
		if(i-1>=0 && pos_j-2>=0){
			if (chessBoard[pos_i-1][pos_j-2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i-1][pos_j-2] == stepBack){
				stepPositions[stepBack] = positions[pos_i-1][pos_j-2];
				pos_i = pos_i-1;
				pos_j = pos_j-2;
				continue;
			}
		}
		if(pos_i+1<8 && pos_j-2>=0){
			if (chessBoard[pos_i+1][pos_j-2] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i+1][pos_j-2] == stepBack){
				stepPositions[stepBack] = positions[pos_i+1][pos_j-2];
				pos_i = pos_i+1;
				pos_j = pos_j-2;
				continue;
			}
		}
		if(pos_i+2<8 && pos_j-1>=0){
			if (chessBoard[pos_i+2][pos_j-1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i+2][pos_j-1] == stepBack){
				stepPositions[stepBack] = positions[pos_i+2][pos_j-1];
				pos_i = pos_i+2;
				pos_j = pos_j-1;
				continue;
			}
		}
		if(pos_i+2<8 && pos_j+1<8){
			if (chessBoard[pos_i+2][pos_j+1] == 0) {
				for(i=0;i<=step;i++){
					out<<stepPositions[i]<<"\t";
				}
				out<<endl;
				return step;
			}
			else if (chessBoard[pos_i+2][pos_j+1] == stepBack){
				stepPositions[stepBack] = positions[pos_i+2][pos_j+1];
				pos_i = pos_i+2;
				pos_j = pos_j+1;
				continue;
			}
		}
	}
	while (stepBack > 0);
	return 0;//на всякий случай
}
