
final : game.cpp game.hpp GraphAdjListCompMoves.hpp GraphAdjList.hpp GraphAdt.hpp Main.cpp board.cpp board.hpp
	g++ -std=c++0x -o out -O2 game.cpp game.hpp GraphAdjListCompMoves.hpp GraphAdjList.hpp GraphAdt.hpp Main.cpp board.cpp board.hpp
clean:
	rm -rf out

