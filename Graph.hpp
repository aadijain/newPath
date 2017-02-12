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
		// double arcLen(Point p1, Point p2);
		// double cost(Point p1, Point p2, Point p3);
		// void dijkstra()
	public:
		vector<vector<int> > edges;
		vector<Point> points;
		vector<Obstacle> obstacles;
		Point createPoint(double x,double y);
		void addObst(double x,double y,double r);
		void addPoint(Point &p, int obst_id, Orientation w);
		void addEdge(Point &p1, Point &p2);
		void removeEdge(Point &p1,Point &p2);
		static double dist(Point p1, Point p2);
};
#endif
