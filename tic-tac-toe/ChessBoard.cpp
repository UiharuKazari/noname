#include "ChessBoard.h"
#include <iostream>
using namespace std;

void ChessBoard::show() {
	cout << "length: " << length << endl;
	cout << "width: " << width << endl;
	cout << "win if " << win_num << "-in-a-row" << endl;
	cout << "BOARD STATUS: " << endl;
	for(vector<ChessSquare>::iterator it=css.begin(); it!=css.end(); it++) {
		cout << it->getcm();
		if(it->getcol() == width) cout << endl;
	}	
}

void ChessBoard::set(vector<char> vc) {
	vector<ChessSquare>::iterator vcsit;
	vector<char>::iterator vcit;
	for(vcsit=css.begin(), vcit=vc.begin(); vcsit != css.end(); vcsit++, vcit++)
		vcsit->setcm(*vcit);
}

void ChessBoard::initChessBoard() {
	for(int i=1; i<=width; i++)
		for(int j=1; j<=length; j++) {
			ChessSquare cs(i, j, NONE);
			css.push_back(cs);
		}
}
