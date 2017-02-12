#ifndef DRAWER_H
#define DRAWER_H

#include "commondefs.hpp"
#include "Graph.hpp"

#include <stdio.h>
#include <vector>
#include <opencv2/opencv.hpp>
// #include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
// #include <opencv2/imgcodecs.hpp>
#define WIN_SIZE_X 500
#define WIN_SIZE_Y 500

using namespace std;
// using namespace cv;
class Drawer
{
    private:
        cv::Mat image;
        // static void ifMoved(int v,void* data);
        static void callBack(int event, int x, int y, int flags, void *userdata);
    public:
        static int NP,D0;
        static PathStructure ps;
        Drawer();
        void clear();
        void displayPoints(PathStructure ps);
        void displayGraph(Graph &G);
        // void displayPath(vector<Segment> p);
        void displaySlider();
        void getMouseData();
        void wait();
};
#endif
