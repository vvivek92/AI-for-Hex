#include<vector>
#include<list>
#include "GraphAdt.hpp"
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;
//GraphAdjList.hpp
#ifndef GRAPHADJLIST
#define GRAPHADJLIST

template<class Elem>
class GraphAdjList:public GraphAdt<Elem> {
    private:
        struct node {
            int vertex;
	    Elem e;
	};
	vector<list<node> > adjList;
	Elem defElem;
    public:
	GraphAdjList(int size,Elem defElem):adjList(size, list<node>()) {
	    this->defElem= defElem;
	}
	GraphAdjList (const GraphAdjList<Elem> &g):adjList(g.adjList) {
	    this->defElem= g.defElem;
	}
	~GraphAdjList() {}
	bool isConnected(int a, int b, char C) {
	    vector<int> explored(adjList.size(),0);
	    stack<int> q;
	    typename list<node>::iterator itr;
	    q.push(a);
	    while(q.size()!=0) {
	        int temp=q.top();
	 	explored[temp]=1;
		q.pop();
		if(explored[b]==1) return true;
		for(itr=adjList[temp].begin();itr!= adjList[temp].end();itr++) {
		    if((*itr).e==C && explored[(*itr).vertex]==0) 
		    q.push((*itr).vertex);
	        }
	    }
	if( explored[b]==0) return false;
	else return true;		
	}		
	void printGraph() {
	    int vertex=0;
	    typename list<node>::const_iterator itrIn;
	    typename vector<list<node> >::const_iterator itrOut;
            for(itrOut= adjList.begin();itrOut!=adjList.end();itrOut++) {
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
	void setEdge(int  from, int to, Elem e ) {
	    node n1,n2;
	    n2.e=n1.e=e;
	    n1.vertex=to;
	    adjList[from].push_back(n1);
	    n2.vertex=from;
	    adjList[to].push_back(n2);
	} 
	Elem getEdge(int from, int to) {
	    typename list<node>::const_iterator itr;
	    for( itr= adjList[from].begin();itr!=adjList[from].end();itr++) {
	    if( (*itr).vertex == to) return (*itr).e;
	    }
	    return defElem;
	}
        int size() {
	    return adjList.size();
	}
};

#endif

