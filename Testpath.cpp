#include "Path.hpp"

int main(int argc, char *argv[])
{
	PathStructure ps;
	Path p(ps);
	while(true)
	{
		p.update();
		p.draw();
	}
	return 0;
}
