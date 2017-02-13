#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "commondefs.hpp"

#define ERR 0.1

using namespace std;

class Obstacle
{
	private:
	public:
		// void tangent_points(Point source, Point &p1, Point &p2);
		void extreme_points(Point source, Point target, Point &p1, Point &p2);
		void shift_point(Point &p, Obstacle o);
		// void dct_points(Obstacle target_obstacle, Point &p1a, Point &p1b, Point &p2a, Point &p2b);
		// void tct_points(Obstacle target_obsacle, Point &p1a, Point &p1b, Point &p2a, Point &p2b);
		// bool is_valid_angle(Point source_point, Point target_point, Orientation w);
		bool is_blocking(Point source_point, Point target_point);
		bool is_touching(Obstacle target_obstacle);
		bool encloses(Point p);
		int id;
		double x,y,obstacle_radius;
		Obstacle(double xt,double yt,double rt)	{
			x = xt;
			y = yt;
			obstacle_radius = rt;
		}
};
#endif
