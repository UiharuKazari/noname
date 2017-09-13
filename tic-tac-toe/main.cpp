#include "ChessBoard.h"
#include <iostream>
using namespace std;

int main() {
	ChessBoard cb;
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
