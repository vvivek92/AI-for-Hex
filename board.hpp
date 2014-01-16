//class to represent hex board
//board.hpp


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
	    char ** board;              //2D vector to represent board
		const int sevenOrEleven;                  //size of board
	public:
	    Board(const Board& b);
		~Board();
	    Board(int n);                            //constructor  
		void printBoard() ;                     // prints the board
		bool set(int & rowArg, int & colArg);
		bool setX(int & rowArg, int & colArg);
		bool set(string inputString, string player, int & rowArg, int & colArg);
		char getValue(int row, int col);              
};
#endif