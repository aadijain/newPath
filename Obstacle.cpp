#include "Obstacle.hpp"
/*
void Obstacle::extreme_points(Point source, Point target, Point &p1, Point &p2)
{
	double dx = target.x - source.x;
	double dy = target.y - source.y;
	double dl = sqrt(dx*dx + dy*dy);
	p1.x = this->x - this->obstacle_radius*dy/dl;
	p1.y = this->y + this->obstacle_radius*dx/dl;
	p2.x = this->x + this->obstacle_radius*dy/dl;
	p2.y = this->y - this->obstacle_radius*dx/dl;
	p1.orientation = CLOCKWISE;
	P2.orientation = ANTICLOCKWISE;

	p1.parent_id= source.id; // can also be done in addLine fnc
	p1.obstacle_id = this->id;
	p2.obstacle_id = this->id;
	p2.parent_id= source.id;
}

void Obstacle::tangent_points(Point source, Point &p1, Point &p2)
//finds the 2 points on the obstacle for drawing tangents
{
	double x,y,d,l,r;
	r = this->obstacle_radius;
	x = this->x-source.x;
	y = this->y-source.y;
	l = x*x + y*y;
	d = sqrt(l-r*r);
	p1.x = source.x + d*(x*d+y*r)/l;
	p1.y = source.y + d*(y*d-x*r)/l;
	p2.x = source.x + d*(x*d-y*r)/l;
	p2.y = source.y + d*(y*d+x*r)/l;
	p1.orientation = CLOCKWISE;
	P2.orientation = ANTICLOCKWISE;

	p1.parent_id= source.id; // can also be done in addLine fnc
	p1.obstacle_id = this->id;
	p2.obstacle_id = this->id;
	p2.parent_id= source.id;
}

void Obstacle::dct_points(Obstacle target_obstacle, Point &p1a, Point &p1b, Point &p2a, Point &p2b)
//finds the 4 points on the obstacles for drawing direct common tangents
{
	double x,y,r1,r2,l;
	Point m,p1a,p1b,p2a,p2b;
	r = this->obstacle_radius;
	x = target_obsacle.x-this->x;
	y = target_obsacle.y-this->y;
	l = sqrt(x*x+y*y);
	p1a.x=this->x - y*r/l;
	p1a.y=this->y + x*r/l;
	p1b.x=this->x + y*r/l;
	p1b.y=this->y - x*r/l;
	p2a.x=target_obstacle.x - y*r/l;
	p2a.y=target_obstacle.y + x*r/l;
	p2b.x=target_obstacle.x + y*r/l;
	p2b.y=target_obstacle.y - x*r/l;
	p1a.orientation = CLOCKWISE;
	p1b.orientation = ANTICLOCKWISE;
	p2a.orientation = CLOCKWISE;
	p2b.orientation = ANTICLOCKWISE;

	p1a.parent_id = -1;
	p1a.obstacle_id = this->id;
	p1b.parent_id = -1;
	p1b.obstacle_id = this->id;
	p2a.parent_id = -1;
	p2a.obstacle_id = target_obstacle.id;
	p2b.parent_id = -1;
	p2b.obstacle_id = target_obstacle.id;
}

void Obstacle::tct_points(Obstacle target_obsacle, Point &p1a, Point &p1b, Point &p2a, Point &p2b)
//finds the 4 points on the obstacles for drawing transverse common tangents)
{
	Point m;
	m.x= (target_obsacle.x+this->x)/2;
	m.y= (target_obsacle.y+this->y)/2;
	tangent_points(m,p1b,p1a);
	target_obstacle.tangent_points(m,p2a,p2b);
}

bool Obstacle::is_valid_angle(Point source_point, Point target_point, Orientation w)
{
	double x1,x2,y1,y2,res;
	x1=source_point.x-this->x;
	x2=target_point.x-this->x;
	y1=source_point.y-this->y;
	y2=target_point.y-this->y;
	res = y2*x1 - x2*y1;

	if((w == CLOCKWISE && res<0) || (w == ANTICLOCKWISE && res>0))
	//ensure smaller angle is in correct orientation
		return true;
	else
		return false;
}

bool Obstacle::is_blocking(Point source_point, Point target_point)
{
	double dx,dy,xt,yt,xtt,ytt,l;
	dx = target_point.x-source_point.x;
	dy = target_point.y-source_point.y;
	l = sqrt(dx*dx+dy*dy);

	xt = this->x-source_point.x;
	yt = this->y-source_point.y;
	xtt = (xt*dx + yt*dy)/l;
	ytt = (dx*yt - xt*dy)/l;

	if(ytt <= p.obstacle_radius && ytt >= -p.obstacle_radius)
		if(xtt >= 0 && xtt <= l)
			return true;
	return false;
}

bool Obstacle::is_touching(Obstacle target_obstacle)
{
	double dx,dy,dl;
	dy = target_obstacle.y - this->y;
	dx = target_obstacle.x - this->x;
	dl = sqrt(dy*dy + dx*dx);
	return (dl < target_obstacle.obstacle_radius + this->obstacle_radius);
}
*/
