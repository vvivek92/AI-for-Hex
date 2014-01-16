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


Board::Board(const Board& b):sevenOrEleven(b.sevenOrEleven) {
    board=(char**)malloc(sevenOrEleven*sizeof(char*));
    for(int i=0;i < sevenOrEleven;i++) {
        board[i]=(char*)malloc(sevenOrEleven*sizeof(char));   
	}
    for(int i=0; i < sevenOrEleven;i++)
        for(int j=0; j < sevenOrEleven;j++)
            board[i][j]=b.board[i][j];		
}

Board::~Board() {
    for(int i=0;i<sevenOrEleven;i++)
	    free( board[i]);
	free(board);
}

Board::Board(int n):sevenOrEleven(n) {
    board=(char**)malloc(n*sizeof(char*));
    for(int i=0;i < n;i++) {
        board[i]=(char*)malloc(n*sizeof(char));   
	}
    for(int k=0;k<n;k++)
        for(int j=0;j<n;j++)
            board[k][j]='.';		
}
void Board::printBoard() {
	char c='A';
	int num =1;
    int tab=0;
	cout<<endl;
	cout<<"Board:"<<endl<<endl;
	for(unsigned int i=0;i<sevenOrEleven;i++) {
	    cout<<"  "<<c++<<"  ";
	}
	cout<<endl<<endl;
	for(int j=0; j<sevenOrEleven; j++) {
	    for(int i=0;i != tab;i++) {
            cout<<"  ";
        }
        cout<<num<<"  ";				
	    for( int k = 0; k< sevenOrEleven;k++) {
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
	for(int i=0;i<sevenOrEleven;i++) {
	    cout<<"  "<<c++<<"  ";
	}
	cout<<endl;	
}
bool Board::set( int & row, int & col) {
    board[row][col]='O';
}	

bool Board::setX(int & rowArg, int & colArg) {
    board[rowArg][colArg]='X';
    return true;
}
bool Board::set(string inputString, string player, int & rowArg, int & colArg) {
////get first word and first integer from a stream
    int row, col;
    istringstream iss(inputString);
    string sub;
    iss >> sub;
//cout << "hi"<<sub.size()<<endl;
	if(sevenOrEleven==11) {
        if(sub.size()==1) {
		    if(sub[0] < 'A' || sub[0] > 'K')
		        return false;
		    col=(sub[0]-'A');
		    cout << "hi"<<endl;
		    iss >> sub;
		    if(sub.size()==1) {
			    row=(sub[0]-'0'-1);
				if(row>=sevenOrEleven) return false;
			}
			else if(sub.compare("11")==0)
			    row=10;
			else if(sub.compare("10")==0)
			    row=9;
			else
			    return false;
		}
		
		else {
		    if(sub[0] < 'A' || sub[0] > 'K')
		        return false;
		    col=(sub[0]-'A');
		        sub.erase(0,1);
			    if(sub.size()==1) {
				    row=(sub[0]-'0'-1);
					if(row>=sevenOrEleven) return false;
				}
				else if(sub.compare("11")==0)
				    row=10;
				else if(sub.compare("10")==0)
				    row=9;
				else
				    return false;
		    }
		}
		else {
		    if(sub.size()==1) {
		        if(sub[0] < 'A' || sub[0] > 'G')
		            return false;
		        col=(sub[0]-'A');
			
			    iss >> sub;
			    if(sub.size()==1) {
				    row=(sub[0]-'0'-1);
				    if(row>=sevenOrEleven) return false;
				}
				else return false;
		    }
		
		    else {
		        if(sub[0] < 'A' || sub[0] > 'G')
		            return false;
			    col=(sub[0]-'A');
		        sub.erase(0,1);
			    if(sub.size()==1) {
				    row=(sub[0]-'0'-1);
				    if(row>=sevenOrEleven) return false;
				}
				else return false;
		    }			    
		}
		//cout<<col<<" "<<row<<endl;
		if(board[row][col]=='.' ) {
		    rowArg=row;
			colArg=col;
            if(player.compare("Human")==0)board[row][col]='X';
			else if(player.compare("Computer")==0)board[row][col]='O';
			return true;
	}
    else return false;						
}
char Board::getValue(int row, int col) {
    assert(row >=0 && col >=0 && row < sevenOrEleven && col < sevenOrEleven);
    return board[row][col];    
}
