a.out: libChessSquare.so libChessBoard.so main.cpp
	g++ main.cpp -L. -lChessSquare -lChessBoard -o a.out
libChessSquare.so: ChessSquare.cpp ChessSquare.h
	g++ -shared -fPIC ChessSquare.cpp -o libChessSquare.so
libChessBoard.so: ChessBoard.cpp ChessBoard.h
	g++ -shared -fPIC ChessBoard.cpp -o libChessBoard.so
clean:
	rm -rf *.so a.out
