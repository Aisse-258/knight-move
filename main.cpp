#include <iostream>
using namespace std;
const int chessBoardSize = 8;
int chessBoard [chessBoardSize][chessBoardSize] = {0};
const string positions [chessBoardSize][chessBoardSize] = {
	{"a1\0","b1\0","c1\0","d1\0","e1\0","f1\0","g1\0","h1\0"},
	{"a2\0","b2\0","c2\0","d2\0","e2\0","f2\0","g2\0","h2\0"},
	{"a3\0","b3\0","c3\0","d3\0","e3\0","f3\0","g3\0","h3\0"},
	{"a4\0","b4\0","c4\0","d4\0","e4\0","f4\0","g4\0","h4\0"},
	{"a5\0","b5\0","c5\0","d5\0","e5\0","f5\0","g5\0","h5\0"},
	{"a6\0","b6\0","c6\0","d6\0","e6\0","f6\0","g6\0","h6\0"},
	{"a7\0","b7\0","c7\0","d7\0","e7\0","f7\0","g7\0","h7\0"},
	{"a8\0","b8\0","c8\0","d8\0","e8\0","f8\0","g8\0","h8\0"}
};
int knight (std::string pos1, std::string pos2) {
	if (pos1 == pos2) return 0;
	int i,j;
	for (i=0;i<chessBoardSize;i++){
		for (j=0; j<chessBoardSize; j++){
			if (pos1 == positions[i][j]) {
				chessBoard[i][j] = 0;
			}
			else if (pos2 == positions[i][j]) {
				chessBoard[i][j] = 9999;
			}
			else {
				chessBoard[i][j] = -1;
			}
		}
	}
}
int main(){
	string Pos1, Pos2;
	cout<<"Start position:\n";
	do {
		cin>>Pos1;
	}
	while (Pos1.length() != 2 || Pos1[1]<'1' || Pos1[1]>'8' || Pos1[0]<'a' || Pos1[0]>'h');
	cout<<"End position:\n";
	do {
		cin>>Pos2;
	}
	while (Pos2.length() != 2 || Pos2[1]<'1' || Pos2[1]>'8' || Pos2[0]<'a' || Pos2[0]>'h');

	knight(Pos1, Pos2);
	int i, j;
	for (i=0; i<chessBoardSize; i++){
		for (j=0; j<chessBoardSize; j++){
			cout<<chessBoard[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
