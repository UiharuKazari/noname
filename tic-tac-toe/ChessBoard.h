#include "ChessSquare.h"
#include <vector>
using namespace std;

class ChessBoard {
public:
	ChessBoard(): win_num(3), length(4), width(4) { initChessBoard(); }
	ChessBoard(int x, int y, int z): win_num(x), length(y), width(z) { initChessBoard(); }
	void show();
	void set(vector<char>);
	void initChessBoard();
	int getlength() { return length; }
	int getwidth() { return width; }
private:
	int win_num;
	int length;
	int width;
	vector<ChessSquare> css;
};
