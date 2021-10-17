#include <iostream>
using namespace std;
#include "knight.h"
#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <QLabel>

int main(int argc, char *argv[])
{
	/*string resume;
	do {
		cout<<"Enter knight's positions in algebraic notation (for example, \"b2\"). Use letters a-h and numbers 1-8.\n";
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

		cout<<"Minimum steps required:\n"<<knight(Pos1, Pos2)<<endl;
		cout<<"Enter any symbol to restart. Enter \"exit\" to exit.\n";
		cin>>resume;
	}
	while (resume != "exit\0");
	return 0;*/
	QApplication a(argc, argv);
	MainWindow w;
	//w.resize(300, 320);
	w.setWindowTitle("Knight's move");
	w.setWindowIcon(QIcon("knight-icon.png"));
	w.show();

	return a.exec();
}
