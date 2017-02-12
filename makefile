path: Drawer.o Obstacle.o Path.o Graph.o Testpath.o
	g++ -o path Drawer.o Obstacle.o Path.o Graph.o Testpath.o `pkg-config opencv --cflags --libs`

Drawer.hpp: commondefs.hpp Graph.hpp Graph.cpp
Drawer.o: Drawer.cpp Drawer.hpp
	g++ -c Drawer.cpp

Obstacle.o: commondefs.hpp Obstacle.cpp Obstacle.hpp
	g++ -c Obstacle.cpp

Path.hpp: commondefs.hpp Graph.hpp Graph.cpp Drawer.hpp Drawer.cpp Obstacle.hpp Obstacle.cpp
Path.o: Path.cpp Path.hpp
	g++ -c Path.cpp

Graph.hpp: commondefs.hpp Obstacle.hpp Obstacle.cpp
Graph.o: Graph.hpp Graph.cpp
	g++ -c Graph.cpp

Testpath.o: Testpath.cpp Path.hpp Path.cpp
		g++ -c -std=c++11 Testpath.cpp
clean:
	@rm -f *.o
	@rm -f path
	@rm -f *~
