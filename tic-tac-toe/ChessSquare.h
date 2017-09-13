/* declaration of Class ChessSquare */
#include <cstddef>

enum chessman {NONE, x, o};

class ChessSquare {
public:
	ChessSquare(): cm(NONE), right(NULL), down(NULL), b_right(NULL), u_right(NULL) { }
	ChessSquare(int x, int y, chessman z): row(x), col(y), cm(z), right(NULL), down(NULL), b_right(NULL), u_right(NULL) { }
	ChessSquare(int x, int y): row(x), col(y), cm(NONE), right(NULL), down(NULL), b_right(NULL), u_right(NULL) { }
	void show();
	int getrow() { return row; }
	int getcol() { return col; }
	char getcm() { 
		switch(cm) {
			case NONE:
				return '.';
			case x:
				return 'x';
			case o:
				return 'o';
		}
	}
	void setcm(char c) {
		switch(c) {
			case '.':
				cm = NONE;
				break;
			case 'x':
				cm = x;
				break;
			case 'o':
				cm = o;
				break;
			default:
				break;
		}
	}
private:
	int row;
	int col;
	chessman cm; 
	void *right;
	void *down;
	void *b_right; 		//bottom-right
	void *u_right;		//upper-right
};
