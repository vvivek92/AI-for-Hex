#include<vector>
#include<list>
#include "GraphAdt.hpp"

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
		~GraphAdjList() {}
		void printGraph() {
		    
        }		
		void setEdge(int from, int to, Elem e ) {
		    node n1,n2;
			n2.e=n1.e=e;
			n1.vertex=to;
			adjList[from].push_back(n1);
			n2.vertex=from;
			adjList[to].push_back(n2);
		} 
		Elem& getEdge(int from, int to) {
		    typename list<node>::const_iterator itr;
			for( itr= adjList[from].begin();itr!=adjList[from].end();itr++) {
			    if( (*itr).vertex == to) return Elem;
			return defElem;
		    }
		}
        int size() {
		    return adjList.size();
		}
};
#endif

