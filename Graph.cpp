#include "Graph.hpp" 

// double Obstacle::line_cost(Point p1, Point p2)
// {
// 	double x,y,l;
// 	x = p2.x-p1.x;
// 	y = p2.y-p1.y;
// 	l = sqrt(x*x+y*y);
// 	return LINEWEIGHT*l;
// }
// double Obstacle::arc_cost(Point p1, Point p2)
//  {
//  	//orientation doesnt matter as always smaller angle is to be taken
//  	double m,m1,m2;
//  	m1 = (p1.y-this->y)/(p1.x-this->x);
//  	m2 = (p2.y-this->y)/(p2.x-this->x);
//  	m = (m2-m1)/(1+m1*m2);
//  	return ARCWEIGHT*atan(abs(m));
//  }