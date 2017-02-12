#include "Path.hpp"

int main(int argc, char *argv[])
{
	Point ball,gl,gr;
	Point ob1,ob2,ob3;
	ball.x = 100;	ball.y = -20;
	gl.x = 80;		gl.y = -80;
	gl.x = 100;		gr.y = -100;
	ob1.x = -50;	ob1.y = -50;
	ob1.x = -100;	ob1.y = 50;
	ob1.x = 100;	ob1.y = 100;
	PathStructure ps{ ball, gl, gr, {ob1, ob2, ob3}, 3};
	Path p(ps);	
	while(true)
	{
		p.draw();
	}
	return 0;
}