#include "ChessBoard.h"
#include <iostream>
using namespace std;

void ChessBoard::show() {
//	cout << "length: " << length << endl;
//	cout << "width: " << width << endl;
//	cout << "win if " << win_num << "-in-a-row" << endl;
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

/* true - win, false - continue */
bool ChessBoard::setone(int i, int j, char c) {
	int subscript=(i-1)*length+j-1;
	css[subscript].setcm(c);

	int tj, ti;

	/* find leftmost */
	tj = j;
	ti = i;
	ChessSquare *leftmost=&css[subscript];
	while(tj-1 >= 1 && (leftmost-1)->getcm() == c) {
		leftmost--;
		tj--;
	}

	int right_length=1;
	while((leftmost+1)->getcm() == c) {
		right_length++;
		leftmost++;
	}

	if(right_length >= win_num)
		return true;

	/* upmost */
	tj = j;
	ti = i;
	ChessSquare *upmost=&css[subscript];
	while (ti-1 >=1 && (upmost-length)->getcm() == c) {
		upmost-=length;
		ti--;
	}
	
	int down_length=1;
	while((upmost+length)->getcm() == c) {
		down_length++;
		upmost+=length;
	}

	if(down_length >= win_num)
		return true;

	/* d_leftmost */
	tj = j;
	ti = i;
	ChessSquare *d_leftmost=&css[subscript];
	while (ti+1 <= width && tj-1 >= 1 && (d_leftmost+length-1)->getcm() == c) {
		d_leftmost+=length-1;
		ti++;
		tj--;
	}

	int u_right_length=1;
	while((d_leftmost-length+1)->getcm() == c) {
		u_right_length++;
		d_leftmost+=1-length;	
	}

	if(u_right_length >= win_num)
		return true;

	/* u_leftmost */
	tj = j;
	ti = i;
	ChessSquare *u_leftmost=&css[subscript];
	while (ti-1 >=1 && tj-1 >= 1 && (u_leftmost-length-1)->getcm() == c) {
		u_leftmost-=length+1;
		ti--;
		tj--;
	}

	int d_right_length=1;
	while((u_leftmost+length+1)->getcm() == c) {
		d_right_length++;
		u_leftmost+=length+1;
	}

	if(d_right_length >= win_num)
		return true;

	return false;
}

void ChessBoard::initChessBoard() {
	for(int i=1; i<=width; i++)
		for(int j=1; j<=length; j++) {
			ChessSquare cs(i, j, NONE);
			css.push_back(cs);
		}
}
