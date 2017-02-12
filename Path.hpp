#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "commondefs.hpp"
#include "Obstacle.hpp"
#include "Graph.hpp"
#include "Drawer.hpp"

using namespace std;

class Path
{
	private:
		PathStructure p;
		Point start,ball,goal;
		vector<Segment> final_path;
		Graph tree;
		Drawer dr;
	public:
		Path(PathStructure ps) {
			p = ps;
		}
		void update();
		// vector<Segment> getPath();
		void draw();
};
#endif
