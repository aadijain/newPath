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
/*void Path::validate()
{
	//check for objects on top of ball
	//check for objects on top of start
	//check if very close to ball
	//check if very far from ball
	//side walk, back walk, etc
}*/

void Path::initialize_tree()
{
	double dx,dy,dl;
	Point p1,p2;
	tree = Graph();	//clear tree
	start = tree.createPoint(ps.start.x,ps.start.y);
	ball =  tree.createPoint(ps.ball.x,ps.ball.y);
	goal = tree.createPoint(0.5*(ps.gpleft.x+ps.gpright.x),0.5*(ps.gpleft.y+ps.gpright.y));
	minus = tree.createPoint(ps.start.x - ps.dir.x, ps.start.y - ps.dir.y);
	dx = ps.dir.x;
	dy = ps.dir.y;
	dl = sqrt(dx*dx + dy*dy);
	p1 = tree.createPoint(start.x - ORIENTATION_RADIUS*dy/dl, start.y + ORIENTATION_RADIUS*dx/dl);
	p2 = tree.createPoint(start.x + ORIENTATION_RADIUS*dy/dl, start.y - ORIENTATION_RADIUS*dx/dl);
	//add virtual objects around start
	if(Graph::dist(p1,ball) < Graph::dist(p2,ball))	{
		tree.addObst(p1.x, p1.y, ORIENTATION_RADIUS);
		tree.addPoint(start,0,ANTICLOCKWISE);
	}
	else	{
		tree.addObst(p2.x, p2.y, ORIENTATION_RADIUS);
		tree.addPoint(start,0,CLOCKWISE);
	}
	dx = goal.x - ball.x;
	dy = goal.y - ball.y;
	dl = sqrt(dx*dx + dy*dy);
	p1 = tree.createPoint(ball.x - ORIENTATION_RADIUS*dy/dl, ball.y + ORIENTATION_RADIUS*dx/dl);
	p2 = tree.createPoint(ball.x + ORIENTATION_RADIUS*dy/dl, ball.y - ORIENTATION_RADIUS*dx/dl);
	//add virtual objects around ball
	if(Graph::dist(p1,start) < Graph::dist(p2,start))	{
		tree.addObst(p1.x, p1.y, ORIENTATION_RADIUS);
		tree.addPoint(ball,1,ANTICLOCKWISE);
	}
	else	{
		tree.addObst(p2.x, p2.y, ORIENTATION_RADIUS);
		tree.addPoint(ball,1,CLOCKWISE);
	}
	tree.addPoint(goal,-1,STRAIGHT);
	tree.addPoint(minus,-1,STRAIGHT);
	//add other obstacles
	for(int i = 0; i < ps.noofobstacles; i++)
		tree.addObst(ps.obj[i].x, ps.obj[i].y, OBSTACLE_RADIUS);
}

void Path::shift(Point &p)
{
	int ctr = 0;
	while(ctr != tree.obstacles.size())
	{
		if(ctr != p.obstacle_id && tree.obstacles[ctr].encloses(p))
		{
			tree.obstacles[ctr].shift_point(p, tree.obstacles[p.obstacle_id]);
			ctr = -1;
		}
		ctr++;
	}
}

void Path::generate_tree()
{
	tree.addEdge(start,ball);
	int id, jd, kd;
	id = 0;
	while(id<tree.edges.size())
	{
		jd = 0;
		while(jd < tree.edges[id].size())
		{
			kd = tree.edges[id][jd];
			if(!split_edge(tree.points[id],tree.points[kd]))
				jd++;
		}
		id++;
	}
	tree.addEdge(ball,goal);
	tree.addEdge(minus,start);
}

bool Path::check_parent(Point a)
{
	printf("\n%d ",a.id);
	if(a.parent_id == -1)
		return false;
	printf("%d-",a.parent_id);
	Point pa = tree.points[a.parent_id];
	printf("%d ",pa.id);
	if(pa.parent_id == -1)
		return false;
		// return false;
	printf("%d-",pa.parent_id);
	if(a.w != pa.w)
		return false;
	Point ppa = tree.points[pa.parent_id];
	printf("%d",ppa.id);
	double res = (a.y-ppa.y)*(pa.x-ppa.x) > (pa.y-ppa.y)*(a.x-ppa.x);
	if(res > 0 && a.w == CLOCKWISE)
	 	return true;
	if(res < 0 && a.w == ANTICLOCKWISE)
		return true;
	return false;
}

bool Path::split_edge(Point A, Point B)
{
	Point p1, p2;
	for(int ctr = 2; ctr < tree.obstacles.size(); ctr++)
	{
		if(tree.obstacles[ctr].is_blocking(A,B))
		{
			tree.obstacles[ctr].extreme_points(A,B,p1,p2);
			shift(p1);
			shift(p2);
			// bool status = false;
			if(p1.obstacle_id != A.obstacle_id && p1.obstacle_id != B.obstacle_id)  {
				if(p1.w == A.w || !tree.obstacles[A.obstacle_id].is_touching(tree.obstacles[p1.obstacle_id]))	{
					if(p1.w == B.w || !tree.obstacles[B.obstacle_id].is_touching(tree.obstacles[p1.obstacle_id]))	{
						// status = true;
						tree.addPoint(p1);
						tree.addEdge(A,p1);
						tree.addEdge(p1,B);
						// if(check_parent(p1))	{
						// 	printf("!!!");
						// 	tree.addEdge(tree.points[A.parent_id],p1);
						// }
					}
				}
			}
			if(p2.obstacle_id != A.obstacle_id && p2.obstacle_id != B.obstacle_id)  {
				if(p2.w == A.w || !tree.obstacles[A.obstacle_id].is_touching(tree.obstacles[p2.obstacle_id]))	{
					if(p2.w == B.w || !tree.obstacles[B.obstacle_id].is_touching(tree.obstacles[p2.obstacle_id]))	{
						// status = true;
						tree.addPoint(p2);
						tree.addEdge(A,p2);
						tree.addEdge(p2,B);
						// if(check_parent(p2))	{
						// 	printf("@@@");
							// tree.addEdge(tree.points[A.parent_id],p2);
						// }
					}
				}
			}
			// if(status)
				tree.removeEdge(A,B);
			return true;
		}
	}
	return false;
}
