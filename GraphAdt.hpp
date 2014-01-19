
//GraphAdt.hpp

//GraphAdt.hpp
#ifndef GRAPHADT
#define GRAPHADT

template<class Elem>
class GraphAdt {
    public:
        GraphAdt(){}
	//GraphAdt(Graph)
	virtual ~GraphAdt() {}
	virtual void printGraph() =0;	
	virtual void setEdge(int from, int to, Elem e )=0;
	virtual Elem getEdge(int from, int to)=0;
        virtual int size()=0;
	virtual bool isConnected(int a, int b, char C)=0;
};
#endif

