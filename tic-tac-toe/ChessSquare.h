/* declaration of Class ChessSquare */

enum chessman {NONE, X, O};

class ChessSquare {
public:
	ChessSquare(): cm(NONE) { }
	ChessSquare(int x, int y, chessman z): row(x), col(y), cm(z) { }
	ChessSquare(int x, int y): row(x), col(y), cm(NONE) { }
	void show();
	int getrow() { return row; }
	int getcol() { return col; }
	char getcm() { 
		switch(cm) {
			case NONE:
				return '.';
			case X:
				return 'X';
			case O:
				return 'O';
		}
	}
	void setcm(char c) {
		switch(c) {
			case '.':
				cm = NONE;
				break;
			case 'X':
				cm = X;
				break;
			case 'O':
				cm = O;
				break;
			default:
				break;
		}
	}
private:
	int row;
	int col;
	chessman cm; 
};
