play: libChessSquare.so libChessBoard.so play.cpp
	g++ play.cpp -L. -lChessSquare -lChessBoard -o play
libChessSquare.so: ChessSquare.cpp ChessSquare.h
	g++ -shared -fPIC ChessSquare.cpp -o libChessSquare.so
libChessBoard.so: ChessBoard.cpp ChessBoard.h
	g++ -shared -fPIC ChessBoard.cpp -o libChessBoard.so
clean:
	rm -rf *.so play
