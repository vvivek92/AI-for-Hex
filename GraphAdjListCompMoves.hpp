#include<vector>
#include<list>
#include "GraphAdt.hpp"
#include<iostream>
#include<algorithm>
#include<stack>
#include<cassert>
#include "GraphAdt.hpp"
#include<cstring>
using namespace std;
//GraphAdjListCompMoves.hpp
#ifndef GRAPHADJLISTCOMPMOVES
#define GRAPHADJLISTCOMPMOVES

template<class Elem>
class GraphAdjListCompMoves {
    private:
        struct node {
     	    int vertex;
	    Elem e;
	};
	vector<list<node> > adjListCompMoves;
	Elem defElem;
    public:
	GraphAdjListCompMoves(int size,Elem defElem):adjListCompMoves(size, list<node>()) {
	    this->defElem= defElem;
	}
	GraphAdjListCompMoves (const GraphAdjListCompMoves<Elem> &g):adjListCompMoves(g.adjListCompMoves) {
	    this->defElem= g.defElem;
	}
	~GraphAdjListCompMoves() {}
        bool isConnected(int &a, int& b) {
		    //cout<<"here";	
            int size=adjListCompMoves.size();
	    char explored[size];
	    memset(explored,0,size* sizeof(char));
	    int stck[adjListCompMoves.size()];
	    int stckptr=0;
	    typename list<node>::iterator itr;
	    stck[stckptr++]=a;
	    while(stckptr!=0) {
	        int temp=stck[--stckptr];
                explored[temp]=1;
	        if(explored[b]==1) return true;
	        for(itr=adjListCompMoves[temp].begin();itr!= adjListCompMoves[temp].end();itr++) {
	            if(explored[(*itr).vertex]==0) 
	            stck[stckptr++]=((*itr).vertex);
	        }
	    }
	return false;		
        }		
	void printGraph() {
	    int vertex=0;
	    typename list<node>::const_iterator itrIn;
	    typename vector<list<node> >::const_iterator itrOut;
            for(itrOut= adjListCompMoves.begin();itrOut!=adjListCompMoves.end();itrOut++) {
                 cout<<vertex++<<"   ";
	        for(itrIn=(*itrOut).begin();itrIn!=(*itrOut).end();itrIn++) {
                    cout<<(*itrIn).vertex<<"->"; 				
                }
	        cout<<"NULL"<<endl;
	        cout<<"val ";
	        for(itrIn=(*itrOut).begin();itrIn!=(*itrOut).end();itrIn++) {
                    cout<<(*itrIn).e<<"->"; 				
                }
	        cout<<"NULL"<<endl;
            }
        }			
	void setEdge(int from, int to, Elem e ) {
	    node n1,n2;
	    n2.e=n1.e=e;
	    n1.vertex=to;
	    adjListCompMoves[from].push_back(n1);
	    n2.vertex=from;
	    adjListCompMoves[to].push_back(n2);
	} 
	Elem getEdge(int from, int to) {
	    typename list<node>::const_iterator itr;
	    for( itr= adjListCompMoves[from].begin();itr!=adjListCompMoves[from].end();itr++) {
	        if( (*itr).vertex == to) return (*itr).e;
	    }
	    return defElem;
	}
        int size() {
	    return adjListCompMoves.size();
	}
};

#endif

