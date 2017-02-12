#include "Drawer.hpp"

int Drawer::NP = 3;
int Drawer::D0 = 50;
PathStructure Drawer::ps;

// void Drawer::ifMoved(int v,void* data)
// {
//     Drawer *d = (Drawer*)data;
//     d->NP = Drawer::NP;
//     d->D0 = Drawer::D0;
//     printf("v: %d\n",v);
// }
void Drawer::callBack(int event, int x, int y, int flags, void* userdata)
{
    //right click shows context menu so not used
    switch(flags)
    {
        case cv::EVENT_FLAG_LBUTTON:
            ps.gpleft.x = x - WIN_SIZE_X/2 - 10;
    		ps.gpleft.y = y - WIN_SIZE_Y/2;
            ps.gpright.x = x - WIN_SIZE_X/2 + 10;
            ps.gpright.y = y - WIN_SIZE_Y/2;
            break;
        case cv::EVENT_FLAG_MBUTTON:
            ps.ball.x = x - WIN_SIZE_X/2;
    		ps.ball.y = y - WIN_SIZE_Y/2;
            break;
        case cv::EVENT_FLAG_CTRLKEY + cv::EVENT_FLAG_LBUTTON:
            ps.obj[0].x = x - WIN_SIZE_X/2;
    		ps.obj[0].y = y - WIN_SIZE_Y/2;
            break;
        case cv::EVENT_FLAG_CTRLKEY + cv::EVENT_FLAG_MBUTTON:
            ps.obj[1].x = x - WIN_SIZE_X/2;
    		ps.obj[1].y = y - WIN_SIZE_Y/2;
            break;
        case cv::EVENT_FLAG_SHIFTKEY + cv::EVENT_FLAG_LBUTTON:
            // ps.obj[3].x = x - WIN_SIZE_X/2;
    		// ps.obj[3].y = y - WIN_SIZE_Y/2;
            // break;
        case cv::EVENT_FLAG_SHIFTKEY + cv::EVENT_FLAG_MBUTTON:
            ps.obj[2].x = x - WIN_SIZE_X/2;
    		ps.obj[2].y = y - WIN_SIZE_Y/2;
            break;
    }
    ps.noofobstacles = 3;
}

Drawer::Drawer()
{
    cv::namedWindow("Window",1);
    image = cv::Mat::zeros(WIN_SIZE_X, WIN_SIZE_Y, CV_8UC3 );
}
void Drawer::clear()
{
    image = cv::Mat::zeros(WIN_SIZE_X, WIN_SIZE_Y, CV_8UC3 );
    cv::imshow("Window", image);
}

void Drawer::displayPoints(PathStructure ps)
{
    cv::circle(image, cv::Point(WIN_SIZE_X/2,WIN_SIZE_Y/2),2,cv::Scalar(100,255,100));
    cv::circle(image, cv::Point(ps.ball.x + WIN_SIZE_X/2, ps.ball.y + WIN_SIZE_Y/2),2,cv::Scalar(100,255,100));
    cv::circle(image, cv::Point(ps.gpleft.x + WIN_SIZE_X/2, ps.gpleft.y + WIN_SIZE_Y/2),2,cv::Scalar(100,255,100));
    cv::circle(image, cv::Point(ps.gpright.x + WIN_SIZE_X/2, ps.gpright.y + WIN_SIZE_Y/2),2,cv::Scalar(100,255,100));
    cv::line(image, cv::Point(ps.gpleft.x + WIN_SIZE_X/2, ps.gpleft.y + WIN_SIZE_Y/2),
                    cv::Point(ps.gpright.x + WIN_SIZE_X/2, ps.gpright.y + WIN_SIZE_Y/2),
                    cv::Scalar(100,255,100));
    for(int i=0; i < ps.noofobstacles; i++)
        cv::circle(image, cv::Point(ps.obj[i].x + WIN_SIZE_X/2, ps.obj[i].y + WIN_SIZE_Y/2),30,cv::Scalar(100,100,255));
    cv::imshow("Window", image);
}

void Drawer::displayGraph(Graph &G)
{
    // printf("Size: %ld\n",G.points.size());
    for(int i = 0; i < G.edges.size(); i++)
    {
        for(int j = 0; j < G.edges[i].size(); j++)
        {
            int k = G.edges[i][j];
            cv::line(image, cv::Point(G.points[i].x + WIN_SIZE_X/2,G.points[i].y + WIN_SIZE_Y/2),
                            cv::Point(G.points[k].x + WIN_SIZE_X/2,G.points[k].y + WIN_SIZE_Y/2),
                            cv::Scalar(255,100,100));
        }
    }
    cv::imshow("Window", image);
}

void Drawer::displaySlider()
{
    cv::createTrackbar( "NP:", "Window", &Drawer::NP, 10);
    cv::createTrackbar( "D0:", "Window", &Drawer::D0, 100);
}
void Drawer::getMouseData()
{
    cv::setMouseCallback("Window", Drawer::callBack, this);
}
void Drawer::wait()
{
    cv::waitKey(TIMESTEP);
}
