#ifndef GRAPH_H
#define GRAPH_H

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "commondefs.hpp"
#include "Obstacle.hpp"
using namespace std;

class Graph
{
	private:
		vector<vector<bool> > edge;
		vector<int> previous;
		vector<Point> points;
		vector<Obstacle> obstacles;
		// Point createPoint(double x,double y);
		// void addPoint(Point p, Object o, Orientation w);
		// // void deletePoint(Point p, Object o);
		// void addEdge(Point p1, Point p2);
		// void removeEdge(Point p1,Point p2);

		// double lineLen(Point p1, Point p2);
		// double arcLen(Point p1, Point p2);
		// double cost(Point p1, Point p2, Point p3);
		// void dijkstra()
	public:
		static int NO_OF_POINTS;

};
#endif
