#include "Path.hpp"

int main(int argc, char *argv[])
{
	Point start,dir,ball,gl,gr;
	Point ob1,ob2,ob3;
	dir.x = 10;		dir.y = 0;
	start.x = -50;	start.y = 50;
	ball.x = 100;	ball.y = -20;
	gl.x = 80;		gl.y = -80;
	gr.x = 100;		gr.y = -80;
	ob1.x = -50;	ob1.y = -50;
	ob2.x = -100;	ob2.y = 50;
	ob3.x = 100;	ob3.y = 100;
	PathStructure ps{ start, dir, ball, gl, gr, {ob1, ob2, ob3}, 3};
	Path p(ps);
	while(true)
	{
		p.update();
		p.generate_tree();
		p.draw();
	}
	return 0;
}
