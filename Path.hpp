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

#define OBSTACLE_RADIUS 30
#define ORIENTATION_RADIUS 10

using namespace std;

class Path
{
	private:
		PathStructure ps;
		Point minus,start,ball,goal;
		vector<Segment> final_path;
		Graph tree;
		Drawer dr;
		void shift(Point &p);
		bool split_edge(Point A,Point B);//&A ,&B ?
		bool check_parent(Point a);
	public:
		Path(PathStructure ps) {
			ps = ps;
			dr.ps = ps;
		}
		void update();
		void generate_tree();
		void initialize_tree();
		// vector<Segment> getPath();
		void draw();
};
#endif
