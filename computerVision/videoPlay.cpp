//#include "opencv2/opencv.hpp"
//#include <cstdlib>
//#include <cstdio>
//#include <fstream>
//#include <cmath>
//#include <vector>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//const cv::String windowTitle("Video");
//Mat* src = 0;
//cv::Mat3b matImg(100, 100);
//ofstream file("targetCoordinates.txt");
//ifstream rFile("targetCoordinates.txt",ios::app);
//std::vector<int> coordMass(2);
//static double framesCount(0.0);
//
//void drawTarget(const Mat& img, int x, int y, int radius)
//{
//	circle(img, Point(x, y), radius, Scalar(74, 92, 255), 2, 8);
//	line(img, Point(x - radius / 2, y - radius / 2), cvPoint(x + radius / 2, y + radius / 2), Scalar(74, 92, 255), 2, 8);
//	line(img, Point(x - radius / 2, y + radius / 2), cvPoint(x + radius / 2, y - radius / 2), Scalar(74, 92, 255), 2, 8);
//	printf("%d x %d\n", x, y);
//	file  << framesCount<<" : "<< x << " ; " << y << endl;
//	coordMass.insert(coordMass.begin(), x);
//	coordMass.insert(coordMass.begin() + 1, y);
//	coordMass.insert(coordMass.begin() + 2, framesCount);
//	Mat imagewithDraws (img.clone());
//	imshow(windowTitle, imagewithDraws);
//}
//
//void deleteTarget(const Mat& img, int x, int y, int radius) {
//
//	rectangle(img, Point(x-30,y+30),Point(x+30,y-30), (0, 255, 0), 3);
//	for (int i = 0; i < coordMass.size()-2; i++) {
//		int xCoord = abs(x - coordMass[i]);
//		int yCoord = abs(coordMass[i + 1] - y);
//		if (pow((pow(xCoord, 2) + pow(yCoord, 2)), 0.5) <= 30 && framesCount==coordMass[i+2] ) {
//			printf("The target with coordinates %d x %d  was deleted\n", coordMass[i], coordMass[i + 1]);
//			coordMass.erase(coordMass.begin()+i);
//			coordMass.erase(coordMass.begin() + i);
//			coordMass.erase(coordMass.begin() + i);
//			file << coordMass[i] << " ; " << coordMass[i+1] << "!" << framesCount << endl;
//			break;
//		}
//		i++;
//	}
//	
//	Mat imagewithDraws(img.clone());
//	imshow(windowTitle, imagewithDraws);
//	waitKey(1);
//}
//
//static void myMouseCallback(int event, int x, int y, int, void* param)
//{
//	//Mat matImg = *(Mat*)param;
//	switch (event) {
//	case EVENT_MOUSEMOVE:
//		break;
//	case EVENT_LBUTTONDOWN:
//	{
//		drawTarget(matImg, x, y, 10);
//	}
//
//	case CV_EVENT_LBUTTONUP:
//		break;
//	
//	case CV_EVENT_RBUTTONDOWN:
//	{
//		deleteTarget(matImg, x, y, 20);
//	}
//	default:
//		break;
//	}
//}
//
//
//int main(int argc, char* argv[])
//{
//	CommandLineParser parser(argc, argv,
//		"{video v | | show video}{@video|Donate.mov| input video}"
//		//"{video v | | show video}{@video|Vesh.mov| input video}"
//	);
//
//	string filename = parser.get<string>("@video");
//	printf("fileName: %s\n", filename);
//
//	namedWindow(windowTitle, CV_WINDOW_FREERATIO);
//
//	VideoCapture capture(filename);
//	capture.set(CAP_PROP_FPS, 1.0);
//	setMouseCallback(windowTitle, myMouseCallback);
//
//	for (;;) {
//		Mat frame;
//		capture >> matImg;
//		frame = matImg;
//		imshow(windowTitle, frame);
//		waitKey(1);
//
//		framesCount = capture.get(CAP_PROP_POS_FRAMES);
//		printf("number of the frame: %.0f\n", framesCount);
//
//		char c = (char)waitKey(30000);
//		
//		if (waitKey(30)==27) {
//			break;
//		}
//	}
//
//	capture.release();
//	destroyWindow(windowTitle);
//	file.close();
//	return 0;
//}
