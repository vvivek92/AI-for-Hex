//main for hex game
//Main.cpp
#include<iostream>
#include"game.hpp"
#include<string>
#include <sstream>
using namespace std;

inline void delimiter(const char& c) {
    for(int i=0;i<25;i++)
	    cout<<c;
    cout<<endl;
}

inline void printInfo() {
    delimiter('*');
	cout<<"Empty location is denoted by ."<<endl;
    delimiter('-');
	cout<< "Human piece is denoted by X and connects east west"<<endl;
	delimiter('-');
	cout<<"Computer piece is denoted by O and connects North south"<<endl;
	delimiter('*');
}
int main() {
    int board_w=0;
    bool playerIsHuman;
    string s;
    int temp;
    cout<< "Application start..."<<endl;
    delimiter('-');
    do {
           cout<<"Enter the width of hex board(legal values 7 or 11) :";
           getline(cin,s);
           stringstream ss(s);
           ss>>board_w;
           temp=ss.fail();
    } while(temp==1 || !(board_w==7 || board_w==11) );     
 
	//assert(sevenOrEleven==7 || sevenOrEleven==11);
    cout<<"Playing with "<<board_w<<"X"<<board_w<<" board"<<endl;
	
    delimiter('-');
	
    do {
           cout<<"Human, do you want to go first(yes/no)";
           getline(cin,s);
           stringstream ss(s);
           string::size_type i;
           if((i=s.find(' ')) != string::npos ) {
               s.erase(i);       
           }
    } while(s.compare("y")&&s.compare("Y")&&s.compare("yes")&&s.compare("n")&&s.compare("N")&&s.compare("no"));     
 
    if(s.compare("y")==0 || s.compare("Y")==0 ||  s.compare("yes")==0)
        playerIsHuman=true;
    else
        playerIsHuman=false;
	
	if(playerIsHuman) cout<<"Human makes the first move"<<endl;
	else cout<<"Computer makes the first move"<<endl;
	printInfo();
	
	
	Game G(board_w, playerIsHuman);
	G.run();
	
	
	return 0;
}

