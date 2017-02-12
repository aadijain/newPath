#include "Graph.hpp"

Point Graph::createPoint(double x, double y)
{
    Point p;
    p.x = x;    p.y = y;
    p.id = -1;  p.parent_id = -1;   p.obstacle_id = -1;
    p.w = STRAIGHT;
    return p;
}

void Graph::addObst(double x, double y, double r)
{
    Obstacle o(x,y,r);
    o.id = obstacles.size();
    obstacles.push_back(o);
}
void Graph::addPoint(Point &p, int obst_id, Orientation w)
{
    p.id = points.size();
    p.obstacle_id = obst_id;
    p.w = w;
    points.push_back(p);
    vector<int> v;
    edges.push_back(v);
}

void Graph::addEdge(Point &a, Point &b)
{
    b.parent_id = a.id;
    edges[a.id].push_back(b.id);
    // edges[b.id].push_back(a.id);
}

void Graph::removeEdge(Point &a, Point &b)
{
    b.parent_id = -1;
    for(int i = 0; i < edges[a.id].size(); i++)
    {
        if(edges[a.id][i] == b.id)
        {
            edges[a.id].erase(edges[a.id].begin()+i);
            return;
        }
    }
}

double Graph::dist(Point a, Point b)
{
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dr = sqrt(dx*dx + dy*dy);
    return dr;
}
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
