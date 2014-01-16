//Hex Game class
//game.cpp
#include<vector>
#include<iostream>
#include<cassert>
#include "board.hpp"
#include "GraphAdjList.hpp"	
#include<algorithm>
#include<string>
#include"game.hpp"
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include "GraphAdjListCompMoves.hpp"


using namespace std;




	    void Game::run() {
		    gameIsOver=false;
			while(gameIsOver==false) {
			    B.printBoard();
				
     			if(playerIsHuman)
			        legal=humanMove();
		        else
			        legal=computerMove();
			
			if(legal==false) continue;
			gameIsOver=gameStatus();
			if(gameIsOver==true)
                printWinner(playerIsHuman);			
			playerIsHuman=!playerIsHuman;
		    }
		}
		bool Game::gameStatus() {
		    int j=sevenOrEleven*sevenOrEleven;
            bool retVal;
			retVal=(edgeColor->isConnected(j,j+1,'B') || edgeColor->isConnected(j+2,j+3,'R'));            
		    return retVal;
		}
		bool Game::humanMove() {
		    vector<int>::iterator itr;
		    int n =sevenOrEleven;
		    string inputHuman;
			int row,col;
			bool setSuccess;
			cout<<"Play your move, Human (eg: A3 or A 3):";cin.sync();
			getline(cin,inputHuman);
			setSuccess=B.set(inputHuman,"Human",row, col);
			
			if(!setSuccess)cout<<endl<<"Illegal move"<<endl;
			else {
			    itr=find(v.begin(), v.end(), rowColToIndex(row,col) );
			    swap(*itr,v.back());
			    v.pop_back();
			    if(row-1>=0)seeNeighbours('B',row-1,col,row,col);
				if(row+1<sevenOrEleven)seeNeighbours('B',row+1,col,row,col);
				if(col-1>=0)seeNeighbours('B',row,col-1,row,col);
				if(col+1<sevenOrEleven)seeNeighbours('B',row,col+1,row,col);
				if(row-1>=0 && col+1<sevenOrEleven)seeNeighbours('B',row-1,col+1,row,col);
				if(row+1 < sevenOrEleven && col-1>=0)seeNeighbours('B',row+1,col-1,row,col);
			}
			return setSuccess;
		}
		bool Game::computerMove() {
		    int row,col;
			vector<int>::iterator itr;
			int bestVertexForMove=v[0];
			int numWins;
			//int numLost;
			int maxWins= 0;
            //for(itr=v.begin();itr!=v.end();itr++)
			//        cout<<" "<<*itr;
			//    cout<<endl;
            int j=0;
            for(itr=v.begin(); itr!=v.end();itr++) {
                b= new Board(B);
				//GraphAdjList<char > * temp= static_cast<GraphAdjList<char > *>(edgeColor);
                tempCompMoves= new GraphAdjListCompMoves<char>(permCompMoves);
				//temp=0;
                vector<int> tempV(v);
				vector<int>::iterator tempItr;
				
				swap(tempV[j],tempV.back());
			    tempV.pop_back();
				numWins=0;
				//numLost=0;
                indexToRowCol(row,col,*itr);
			    b->set(row,col);
			    if(row-1>=0)seeNeighboursDummy(row-1,col,row,col);
			    if(row+1<sevenOrEleven)seeNeighboursDummy(row+1,col,row,col);
			    if(col-1>=0)seeNeighboursDummy(row,col-1,row,col);
			    if(col+1<sevenOrEleven)seeNeighboursDummy(row,col+1,row,col);
			    if(row-1>=0 && col+1<sevenOrEleven)seeNeighboursDummy(row-1,col+1,row,col);
			    if(row+1 < sevenOrEleven && col-1>=0)seeNeighboursDummy(row+1,col-1,row,col);
				//cout<<"here1000 ";
				int a1,b1;
			    for(int i=0;i<1000;i++) {
				//if(i%100==0)cout<<"here100 ";
				    bb=new Board(*b);
					tempCompMovesIn=new GraphAdjListCompMoves<char>(*tempCompMoves);
				    random_shuffle(tempV.begin(), tempV.end());
			/*
            			for(tempItr=tempV.begin();tempItr<tempV.end();tempItr+=2) {
					        indexToRowCol(row,col,*tempItr);
                		    b->setX(row,col);
            			    if(row-1>=0)seeNeighboursDummy('B',row-1,col,row,col);
			                if(row+1<sevenOrEleven)seeNeighboursDummy('B',row+1,col,row,col);
			                if(col-1>=0)seeNeighboursDummy('B',row,col-1,row,col);
			                if(col+1<sevenOrEleven)seeNeighboursDummy('B',row,col+1,row,col);
			                if(row-1>=0 && col+1<sevenOrEleven)seeNeighboursDummy('B',row-1,col+1,row,col);
			                if(row+1 < sevenOrEleven && col-1>=0)seeNeighboursDummy('B',row+1,col-1,row,col);
                    }
			*/
					for(tempItr=tempV.begin()+1;tempItr<tempV.end();tempItr+=2) {
						    indexToRowCol(row,col,*tempItr);
							bb->set(row,col);
							if(row-1>=0)seeNeighboursDummyIn(row-1,col,row,col);
			                if(row+1<sevenOrEleven)seeNeighboursDummyIn(row+1,col,row,col);
			                if(col-1>=0)seeNeighboursDummyIn(row,col-1,row,col);
			                if(col+1<sevenOrEleven)seeNeighboursDummyIn(row,col+1,row,col);
			                if(row-1>=0 && col+1<sevenOrEleven)seeNeighboursDummyIn(row-1,col+1,row,col);
			                if(row+1 < sevenOrEleven && col-1>=0)seeNeighboursDummyIn(row+1,col-1,row,col);
                    }
					//bb->printBoard();
					//tempCompMovesIn->printGraph();
					a1=sevenOrEleven*sevenOrEleven+2;
					b1=a1+1;
					if(tempCompMovesIn->isConnected(a1,b1)) {
                        numWins++;
					}
                    delete tempCompMovesIn;   				
				    delete bb;
				}
				if(numWins>maxWins) {
                    bestVertexForMove=*itr;
					maxWins=numWins;
				}
			j++;
			}
			itr=find(v.begin(), v.end(),bestVertexForMove  );
			swap(*itr,v.back());
			v.pop_back();
			indexToRowCol(row,col,bestVertexForMove);
			B.set(row,col);
			cout<<endl;
			//for(itr=v.begin();itr!=v.end();itr++)
			//    cout<<*itr;
			//cout<<endl;
			
			
			cout<<endl<<"Computer's move"<<endl;
			//cout<<endl<<maxWins<<" " <<bestVertexForMove<<endl;
			if(row-1>=0)seeNeighbours('R',row-1,col,row,col);
			if(row+1<sevenOrEleven)seeNeighbours('R',row+1,col,row,col);
			if(col-1>=0)seeNeighbours('R',row,col-1,row,col);
			if(col+1<sevenOrEleven)seeNeighbours('R',row,col+1,row,col);
			if(row-1>=0 && col+1<sevenOrEleven)seeNeighbours('R',row-1,col+1,row,col);
			if(row+1 < sevenOrEleven && col-1>=0)seeNeighbours('R',row+1,col-1,row,col);
			//B.printBoard();
			//edgeColor->printGraph();
			
			delete b;
			delete tempCompMoves;
			return true;
		}
		
		void Game::seeNeighbours(char C, int row, int col,int actualRow,int actualCol) {
		    char c,ofInterest;
			if(C== 'B') ofInterest='X';
			if(C== 'R') ofInterest='O';
			c=B.getValue(row,col);
			if(c==ofInterest) {
			//    edgeColor[][]
			    edgeColor->setEdge(rowColToIndex(row,col), rowColToIndex(actualRow,actualCol),C);
				//edgeColor->setEdge(rowColToIndex(actualRow,actualCol), rowColToIndex(row,col),C);
				permCompMoves.setEdge(rowColToIndex(row,col), rowColToIndex(actualRow,actualCol),C);
			}
		}
		
				
		void inline Game::seeNeighboursDummy( int row, int col,int actualRow,int actualCol) {
		    
			if((*b).getValue(row,col) =='O') {
			//    edgeColor[][]
			    tempCompMoves->setEdge(rowColToIndex(row,col), rowColToIndex(actualRow,actualCol),'R');
				//tempCompMoves->setEdge(rowColToIndex(actualRow,actualCol), rowColToIndex(row,col),C);
			}
			    			
		}

		void inline Game::seeNeighboursDummyIn( int row, int col,int actualRow,int actualCol) {
		    
			if((*bb).getValue(row,col) =='O') {
			//    edgeColor[][]
			    tempCompMovesIn->setEdge(rowColToIndex(row,col), rowColToIndex(actualRow,actualCol),'R');
				//tempCompMoves->setEdge(rowColToIndex(actualRow,actualCol), rowColToIndex(row,col),C);
			}
			    			
		}
		
		void Game::printWinner(bool playerIsHuman) {
		    if(playerIsHuman==true) 
			    cout<<endl<<"YOU won. Congrats!! "<<endl;
			else
			    cout<<endl<<"You lost. Better luck next time."<<endl;
			B.printBoard();
		}
			
		Game::Game(int num, bool b):sevenOrEleven(num),playerIsHuman(b),B(num),permCompMoves(num*num+4,'B') {
		    edgeColor= new GraphAdjList<char>(num*num+4,'N');
			gameIsOver=false;
			legal=false;
			int n=sevenOrEleven;
			srand(time(NULL));
			for(int j=0; j< num*num ;j++)
			    v.push_back(j);
			
			//edgeColor= new GraphAdjMat<char>(n*n+4); 
		//if vertex is A6--ID is (6-1)*7+(A-A)  last 4 -- west east north south
        //so A1---is 0 and for n vertices max is (n-1)*n+(n-1)
/*        
		for(int temp = 0; temp <= (n*n+3); temp++) {
			    //vertexchar[temp]='N';
				for(int temp2 = 0; temp2 <= (n*n+3); temp2++) {
				edgeColor->setEdge(temp,temp2,'N');
		        }
			}
*/
			int row,col;
			
			for(col=0;col<n;col++) {
			    row=0;
			    edgeColor->setEdge(n*n+2,rowColToIndex(row,col),'R');
				permCompMoves.setEdge(n*n+2,rowColToIndex(row,col),'R');
				row=n-1;
				edgeColor->setEdge(n*n+3,rowColToIndex(row,col), 'R');
				permCompMoves.setEdge(n*n+3,rowColToIndex(row,col),'R');
			}
			
			for(row=0;row<n;row++) {
			    col=0;
			    edgeColor->setEdge(n*n,rowColToIndex(row,col), 'B');
				col=n-1;
				edgeColor->setEdge(n*n+1,rowColToIndex(row,col),'B');
			}
		}
        inline int Game::rowColToIndex(int row,int col) {
            assert(row >=0 && col >=0 && row < sevenOrEleven && col < sevenOrEleven);
			return (row * sevenOrEleven + col);
		}
		Game::~Game() {delete edgeColor;}

        inline void Game::indexToRowCol(int & row , int&  col, int index) {
		    row= index/ sevenOrEleven;
			col= index % sevenOrEleven;
		}
	

