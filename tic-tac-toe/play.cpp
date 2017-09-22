#include "ChessBoard.h"
#include <iostream>
using namespace std;

int main() {
	int choice;
	cout << "\t1. Tic-Tac-Toe" << endl	
			<< "\t2. file-in-a-row" << endl
			<< "\t3. custom" << endl
			<< "Choose game type (1, 2, 3): ";
	cin >> choice;

	int length, width, win_num;
	switch(choice) {
		case 1:
			length=4;
			width=4;
			win_num=3;
			break;
		case 2:
			length=16;
			width=16;
			win_num=5;
			break;
		case 3:
			cout << "Enter win_num: ";
			cin >> win_num;
			cout << "Enter length: ";
			cin >> length;
			cout << "Enter width: ";
			cin >> width;
			break;
		default:
			break;
	}

	ChessBoard cb(win_num, length, width);
	cb.show();

/*
	vector<char> vc;
	for(int i=0; i<cb.getlength()*cb.getwidth(); i++) {
		char c;
		cin >> c;
		vc.push_back(c);	
	}

	cb.set(vc);
	cb.show();
*/

	int step=0;
	while (1) {
		step++;

		if (step % 2) cout << "x turn: ";
		else cout << "o turn: ";

		int i, j;
		char c=(step % 2) ? 'x':'o';

		cin >> i >> j;

		if(cb.setone(i, j, c)) {
			cb.show();
			cout << c << " win!" << endl;
			break;
		} else 
			cb.show();
	}

	return 0;
}
