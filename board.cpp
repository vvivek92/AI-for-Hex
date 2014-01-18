//class to represent hex board
//board.cpp
#include<vector>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<cassert>
#include "board.hpp"
using namespace std;
#include "GraphAdjList.hpp"
#include<cstring>


Board::Board(const Board& b):board_w(b.board_w),board(b.board) {
}

Board::~Board() {
}

Board::Board(int n):board_w(n),board(n,vector<char>(n,'.')) {
}
void Board::printBoard() {
	char c='A';
	int num =1;
    int tab=0;
	cout<<endl;
	cout<<"Board:"<<endl<<endl;
	for(unsigned int i=0;i<board_w;i++) {
	    cout<<"  "<<c++<<"  ";
	}
	cout<<endl<<endl;
	for(int j=0; j<board_w; j++) {
	    for(int i=0;i != tab;i++) {
            cout<<"  ";
        }
        cout<<num<<"  ";				
	    for( int k = 0; k< board_w;k++) {
		    cout<<"  "<<board[j][k]<<"  ";
		}
		cout<<num++<<"  ";
		tab++;
		cout<<endl<<endl;
    }
	for(int i=0;i != tab;i++) {
        cout<<"  ";
    }
	cout<<"  ";
	c='A';
	for(int i=0;i<board_w;i++) {
	    cout<<"  "<<c++<<"  ";
	}
	cout<<endl;	
}
bool Board::set(const int & rowArg,const int & colArg,const char & c) {
    board[rowArg][colArg]=c;
    return true;
}

bool Board::processString(string & inputString, int & row, int & col) {
    istringstream iss(inputString);
    string sub;
    iss >> sub;
}
bool Board::set(string inputString, string player, int & rowArg, int & colArg) {
////get first word and first integer from a stream
    char c;
    int i;
    istringstream iss(inputString);
    iss >> c;
    if(iss.fail()) return false;
    iss >> i;
    if(iss.fail()) return false;
    if(i<1 && i > board_w ) return false;
    if((c>='a' && c <='a'+board_w-1)) {
        colArg=c-'a';
    }
    else if (c>='A' && c <='A'+board_w-1) {
        colArg=c-'A';            
    }
    else return false;
    rowArg=i-1;
    return true;
}    
const char & Board::getValue(const int & row,const int & col) {              
    assert(row >=0 && col >=0 && row < board_w && col < board_w);
    return board[row][col];    
}
