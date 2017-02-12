#include "Path.hpp"

void Path::draw()
{
	dr.clear();
	dr.displayPoints(p);
	dr.displaySlider();
	dr.wait();
}

void Path::update()
{
	dr.getMouseData();
	p = dr.ps;
}

/*Path::initialize()// create special points and obstacles
{
	start = tree.createPoint(0,0);
	ball = tree.createPoint(ps.ball.x,ps.ball.y);
	goal = tree.createPoint(0.5*(ps.gpleft.x+ps.gpright.x),0.5*(ps.gpleft.y+ps.gpright.y);
	//add virtal onjects around start
	obstacle_list.push_back(Obstacle(0,OBSTACLE_RADIUS));
	obstacle_list.push_back(Obstacle(0,-OBSTACLE_RADIUS));
	double dx,dy,dl;
	dx = goal.x - ball.x;
	dy = goal.y - ball.y;
	dl = sqrt(dx*dx + dy*dy);
	//add virtual objects around ball
	obstacle_list.push_back(Obstacle(ball.x - OBSTACLE_RADIUS*dy/dl,ball.y + OBSTACLE_RADIUS*dx/dl));
	obstacle_list.push_back(Obstacle(ball.x + OBSTACLE_RADIUS*dy/dl,ball.y - OBSTACLE_RADIUS*dx/dl));
	//add other objects
	for(int i=0;i<ps.noofobstacles;i++)
	{
		obstacle_list.push_back(Obstacle(ps.obj[i][0],ps.obj[i][1]));
	}
}*/

/*void Path::validate()
{
	//check for objects on top of ball
	//check for objects on top of start
	//check if very close to ball
	//check if very far from ball
	//side walk, back walk, etc
}

void Path::generate_tree()
{

} */
