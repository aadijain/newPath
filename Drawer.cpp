#include "Drawer.hpp"

int Drawer::NP = 3;
int Drawer::D0 = 50;

// void Drawer::ifMoved(int v,void* data)
// {
//     Drawer *d = (Drawer*)data;
//     d->NP = Drawer::NP;
//     d->D0 = Drawer::D0;
//     printf("v: %d\n",v);
// }

Drawer::Drawer()
{
    cv::namedWindow("Window",1);
    image = cv::Mat::zeros(WIN_SIZE_X, WIN_SIZE_Y, CV_8UC3 );

}

void Drawer::displayPoints(PathStructure ps)
{
    // cv::circle(image, cv::Point(it->x + WIN_SIZE_X/2, it->y + WIN_SIZE_Y/2),2,cv::Scalar(100,100,100));
    cv::imshow("Window", image);
}

void Drawer::displaySlider()
{
    cv::createTrackbar( "NP:", "Window", &Drawer::NP, 10);
    cv::createTrackbar( "D0:", "Window", &Drawer::D0, 100);
}
void Drawer::wait()
{
    cv::waitKey(TIMESTEP);
}