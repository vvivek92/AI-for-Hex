//class to represent hex board
//board.hpp
#include <utility>

#include<vector>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<cassert>
#ifndef BOARD
#define BOARD
using namespace std;


class Board {
    private:
        vector<vector<char>> board;              //2D vector to represent board
	const int board_w;                  //size of board
    public:
        Board(const Board& b);
        // move semantics?? Board()
	~Board();
	Board(int n);                            //constructor  
	void printBoard() ;                     // prints the board
	bool set(const int & rowArg,const int & colArg,const char & c);
	bool processString(string & inputString, int & row, int & col);
	const char & getValue(const int & row,const int & col);              
};
#endif
