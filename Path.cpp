#include "Path.hpp"

void Path::draw()
{
	dr.clear();
	dr.displayPoints(ps);
	dr.displayGraph(tree);
	dr.displaySlider();
	dr.wait();
}

void Path::update()
{
	dr.getMouseData();
	ps = dr.ps;
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
}*/

void Path::generate_tree()
{
	tree = Graph();
	start = tree.createPoint(ps.start.x,ps.start.y);
	ball =  tree.createPoint(ps.ball.x,ps.ball.y);
	goal = tree.createPoint(0.5*(ps.gpleft.x+ps.gpright.x),0.5*(ps.gpleft.y+ps.gpright.y));

	double dx,dy,dl;
	Point p1,p2;
	dx = ps.dir.x;
	dy = ps.dir.y;
	dl = sqrt(dx*dx + dy*dy);
	p1 = tree.createPoint(start.x - ORIENTATION_RADIUS*dy/dl, start.y + ORIENTATION_RADIUS*dx/dl);
	p2 = tree.createPoint(start.x + ORIENTATION_RADIUS*dy/dl, start.y - ORIENTATION_RADIUS*dx/dl);
	//add virtual objects around start
	if(Graph::dist(p1,ball) < Graph::dist(p2,ball))	{
		tree.addObst(p1.x, p1.y, ORIENTATION_RADIUS);
		tree.addPoint(start,0,CLOCKWISE);
	}
	else	{
		tree.addObst(p2.x, p2.y, ORIENTATION_RADIUS);
		tree.addPoint(start,0,ANTICLOCKWISE);
	}
	dx = goal.x - ball.x;
	dy = goal.y - ball.y;
	dl = sqrt(dx*dx + dy*dy);
	p1 = tree.createPoint(ball.x - ORIENTATION_RADIUS*dy/dl, ball.y + ORIENTATION_RADIUS*dx/dl);
	p2 = tree.createPoint(ball.x + ORIENTATION_RADIUS*dy/dl, ball.y - ORIENTATION_RADIUS*dx/dl);
	//add virtual objects around ball
	if(Graph::dist(p1,start) < Graph::dist(p2,start))	{
		tree.addObst(p1.x, p1.y, ORIENTATION_RADIUS);
		tree.addPoint(ball,1,CLOCKWISE);
	}
	else	{
		tree.addObst(p2.x, p2.y, ORIENTATION_RADIUS);
		tree.addPoint(ball,1,ANTICLOCKWISE);
	}
	tree.addPoint(goal,-1,STRAIGHT);
	tree.addEdge(start,ball);
	tree.addEdge(start,goal);
	tree.addEdge(ball,goal);
	tree.removeEdge(start,goal);
	tree.addEdge(goal,start);
}
