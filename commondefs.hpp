#ifndef COMMONDEFS_H
#define COMMONDEFS_H

#define PI 3.1415
#define TIMESTEP 200

enum Orientation{
    CLOCKWISE, ANTICLOCKWISE, STRAIGHT
};

struct Point {
    double x,y;
    int id,parent_id,obstacle_id;
    Orientation w;
};

struct PathStructure {
    Point start,dir,ball,gpleft,gpright;
    Point obj[10];
    int noofobstacles;
};

struct Segment {
    double d;
    Orientation w;
};
#endif
