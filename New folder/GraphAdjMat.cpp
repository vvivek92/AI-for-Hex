//Graph ADT as 2 D vector
//GraphAdjMat.hpp
#include "GraphAdjMat.hpp"
#include<cassert>
#include<vector>
#include<iostream>

using namespace std;

template<class Elem>
GraphAdjMat<Elem>::GraphAdjMat(int size):Graph(size, vector<Elem>(size,Elem())) {}

template<class Elem>
GraphAdjMat<Elem>::~GraphAdjMat() {}

template<class Elem>
void GraphAdjMat<Elem>::printGraph() {
    cout<<endl<<"Printing the graph represented as adjacency matrix"<<endl;
    typename vector<vector<Elem> >::const_iterator itrRow;
	typename vector<Elem>::const_iterator itrCol;
	for(itrRow= Graph.begin();itrRow!= Graph.end();itrRow++) {
	    for(itrCol= (*itrRow).begin();itrCol!= (*itrRow).end();itrCol++)
            cout<<*itrCol<<" ";
	cout<<endl;
	}
}	

template<class Elem> 
void GraphAdjMat<Elem>::setEdge(int from, int to, Elem e ) {
    assert(from<Graph.size() && from >=0 && to >=0 && to< Graph.size());
	Graph[from][to]=e;
	Graph[to][from]=e;
}

template<class Elem>
Elem& GraphAdjMat<Elem>::getEdge(int from, int to) {
    assert(from<Graph.size() && from >=0 && to >=0 && to< Graph.size());
	return Graph[from][to];
}

template<class Elem>
int GraphAdjMat<Elem>::size() {
    return Graph.size();
}
/*
int main() {
    clr::Color C;
    GraphAdjMat<clr::Color> G(5);
	G.printGraph();
}
*/

