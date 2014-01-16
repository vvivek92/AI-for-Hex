//main for hex game
//Main.cpp
#include<iostream>
#include"game.hpp"
#include<cassert>
#include "color.hpp"
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
    int sevenOrEleven;
	bool playerIsHuman;
	char yOrn;
    cout<< "Application start..."<<endl;
	
	delimiter('-');
	
	cout<<"Enter the number of hexes on one side:";
    cin>>sevenOrEleven;
	//assert(sevenOrEleven==7 || sevenOrEleven==11);
	cout<<"Playing with "<<sevenOrEleven<<"X"<<sevenOrEleven<<" board"<<endl;
	
	delimiter('-');
	
	cout<<"Human, do you want to go first(press Y to go first)";
	cin>>yOrn;
	
	if(yOrn=='Y' || yOrn=='y')
	    playerIsHuman=true;
	else
	    playerIsHuman=false;
	
	if(playerIsHuman) cout<<"Human makes the first move"<<endl;
	else cout<<"Computer makes the first move"<<endl;
	printInfo();
	
	
	Game G(sevenOrEleven, playerIsHuman);
	G.run();
	
	
	return 0;
}

