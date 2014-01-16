//Graph as ADT
//GraphAdt.hpp
//#include "color.hpp"
#ifndef GRAPHADTHEADER
#define GRAPHADTHEADER
template<class Elem>
class GraphAdt {
    public:
	    GraphAdt() {}
		virtual ~GraphAdt();
		virtual void printGraph()=0;
		virtual void setEdge(int from, int to, Elem e )=0;
		virtual Elem& getEdge(int from, int to)=0;
		virtual int size()=0;
};
#endif
		
		