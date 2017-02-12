#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "commondefs.hpp"

#define OBSTACLE_RADIUS 30
#define ORIENTATION_RADIUS 30

using namespace std;

class Obstacle
{
	private:
		int id;
		double x,y;
		double obstacle_radius;

		// void tangent_points(Point source, Point &p1, Point &p2);
		// void extreme_points(Point source, Point &p1, Point &p2);
		// void dct_points(Obstacle target_obstacle, Point &p1a, Point &p1b, Point &p2a, Point &p2b);
		// void tct_points(Obstacle target_obsacle, Point &p1a, Point &p1b, Point &p2a, Point &p2b);
		// bool is_valid_angle(Point source_point, Point target_point, Orientation w);
		// bool is_blocking(Point source_point, Point target_point);
		// bool is_touching(Obstacle target_obstacle);
	public:
		static int NO_OF_OBSTACLES;
		Obstacle(double xt,double yt,double rt = OBSTACLE_RADIUS)	{
			id = NO_OF_OBSTACLES++;
			x = xt;
			y = yt;
			obstacle_radius = rt;
		}
};
#endif
