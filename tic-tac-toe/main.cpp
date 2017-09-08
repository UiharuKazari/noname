#include "ChessBoard.h"
#include <iostream>
using namespace std;

int main() {
	ChessBoard cb;
	cb.show();

	vector<char> vc;
	for(int i=0; i<cb.getlength()*cb.getwidth(); i++) {
		char c;
		cin >> c;
		vc.push_back(c);	
	}

	cb.set(vc);
	cb.show();

	return 0;
}
