//Graph ADT as 2 D vector
//GraphAdjMat.hpp
#include "GraphAdt.hpp"
#include<vector>
#include<iostream>
#ifndef GRAPHADJMATHEADER
#define GRAPHADJMATHEADER

using namespace std;


// Graph ADt using adjacency matrix
template<class Elem>
class GraphAdjMat: public GraphAdt<Elem> {
    private:
	    std::vector<std::vector<Elem> > Graph;
		Elem defElem;
    public:
	    bool isConnected(int a, int b, char C) {
		    
			vector<int> insideMst;
			vector<int> neighbourMst;
			//vector<char>::const_iterator itr;
			int i = this->size();
			
			for(int itr=0;itr<i;itr++) {
			    if(this->getEdge(a,itr)==C&& insideMst.end()==find(insideMst.begin(),insideMst.end(),itr) ) {
				    neighbourMst.push_back(itr);
				}
			}
			insideMst.push_back(a);
			while(neighbourMst.size()!=0) {
			    int temp=neighbourMst.back();
				neighbourMst.pop_back();
				for(int itr=0;itr<i;itr++) {
			        if(this->getEdge(temp,itr)==C && insideMst.end()==find(insideMst.begin(),insideMst.end(),itr) ) {
				        neighbourMst.push_back(itr);
				    }
			    }
				insideMst.push_back(temp);
			}
			
			
			if(insideMst.end()==find(insideMst.begin(),insideMst.end(),b)) return false;
			else return true;		
		}
	    GraphAdjMat(int size,Elem defElem):Graph(size, vector<Elem>(size,defElem) {
		    this->defElem=defElem;
		}
		~GraphAdjMat() {}
		void printGraph() {
            cout<<endl<<"Printing the graph represented as adjacency matrix"<<endl;
            typename vector<vector<Elem> >::const_iterator itrRow;
	        typename vector<Elem>::const_iterator itrCol;
	        for(itrRow= Graph.begin();itrRow!= Graph.end();itrRow++) {
	            for(itrCol= (*itrRow).begin();itrCol!= (*itrRow).end();itrCol++)
                cout<<*itrCol<<" ";
	            cout<<endl;
	        }
        }	
		void setEdge(int from, int to, Elem e ){
            assert(from<Graph.size() && from >=0 && to >=0 && to< Graph.size());
	        Graph[from][to]=e;
	        Graph[to][from]=e;
        }

		Elem getEdge(int from, int to){
            assert(from<Graph.size() && from >=0 && to >=0 && to< Graph.size());
	        return Graph[from][to]; 
        }

		int size() {
            return Graph.size();
        }
};
#endif

