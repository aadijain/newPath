path: Drawer.o Obstacle.o Path.o Graph.o Testpath.o
	g++ -o path Drawer.o Obstacle.o Path.o Graph.o Testpath.o `pkg-config opencv --cflags --libs`

Drawer.o: commondefs.hpp Drawer.cpp Drawer.hpp
	g++ -c Drawer.cpp

Obstacle.o: commondefs.hpp Obstacle.cpp Obstacle.hpp
	g++ -c Obstacle.cpp

Path.hpp: commondefs.hpp Drawer.hpp Obstacle.hpp

Path.o: Path.cpp Path.hpp
	g++ -c Path.cpp

Graph.o: Graph.hpp Graph.cpp
	g++ -c Graph.cpp

Testpath.o: Testpath.cpp Path.hpp
		g++ -c -std=c++11 Testpath.cpp
clean:
	@rm -f *.o
	@rm -f path
	@rm -f *~
