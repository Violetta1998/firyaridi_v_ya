#include "opencv2/opencv.hpp"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
using namespace cv;

class Annotator {
public:
	Annotator()
		:circleRadius(10),
		rectRadius(20),
		file(fileName,ios_base::app),
		rFile(fileName, ios_base::in),
		coordMass(2),
		framesCount(0.0),
		matImg(100, 100),
		windowName("target video"),
		wait((char)waitKey(30000))
	{
		namedWindow(windowName, 1);
		setMouseCallback(windowName, mouseCallback, this);
	}
	~Annotator() = default;
	void drawTarget(const Mat& img, int x, int y, int radius);
	void deleteTarget(const Mat& img, int x, int y, int radius);
	void drawExistedTargets(const Mat& img);
	string getWinName();
	void checkCoordinatesInFile();
	cv::Mat3b matImg;
	double framesCount;
	char wait;

private:
	static void mouseCallback(int event, int x, int y, int, void* param)
	{
		if (0 != param) {
			Annotator& app(*reinterpret_cast<Annotator*>(param));
			switch (event) {
			case EVENT_MOUSEMOVE:
				break;
			case EVENT_LBUTTONDOWN:
			{
				app.drawTarget(app.matImg, x, y, app.circleRadius);
			}

			case CV_EVENT_LBUTTONUP:
				break;

			case CV_EVENT_RBUTTONDOWN:
			{
				app.deleteTarget(app.matImg, x, y, app.rectRadius);
			}
			default:
				break;
			}
		}
	}
private:
	String windowName;
	static String fileName;
	ofstream file;
	ifstream rFile;
	std::vector<int> coordMass;
	int circleRadius;
	int rectRadius;
};

String Annotator::fileName("targetCoordinates.txt");

int main(int argc, const char* argv[]) {
	Annotator app;
	app.checkCoordinatesInFile();
	const string keys =
		"{@video1|Donate.mov| input video}"
		"{@video2|Vesh.mov| input video}"
		"{@message|none| no videos are available}";

	int j = 0;
	CommandLineParser parser(argc, argv,keys);
	string filename = parser.get<string>(j);
	
	printf("fileName: %s\n", filename.c_str());
	VideoCapture capture(filename);

	for (int i = 0; i < capture.get(CAP_PROP_FRAME_COUNT);i++) {
		Mat frame;
		capture >> app.matImg;
		frame = app.matImg;
		imshow(app.getWinName(), frame);
		app.framesCount = capture.get(CAP_PROP_POS_FRAMES);
		printf("number of the frame: %.0f\n", app.framesCount);
		app.drawExistedTargets(app.matImg);
		if (waitKey(30) == 's') {
			app.wait = (char)waitKey(30000);
		}
		if (waitKey(30) == 'f') {
			app.wait = (char)waitKey(3000);
		}
		if (waitKey(30) == 27) {
			break;
		}
		if (capture.get(CAP_PROP_FRAME_COUNT) == i+1) {
			j++;
			filename = parser.get<string>(j);//если больше нет file, то break
			capture.open(filename);
			i = 0;
		}
	}

	capture.release();
	destroyAllWindows();
	//app.file.close();
	return 0;
}

void Annotator::drawTarget(const Mat & img, int x, int y, int radius)
{
	circle(img, Point(x, y), radius, Scalar(74, 92, 255), 2, 8);
	line(img, Point(x - radius / 2, y - radius / 2), cvPoint(x + radius / 2, y + radius / 2), Scalar(74, 92, 255), 2, 8);
	line(img, Point(x - radius / 2, y + radius / 2), cvPoint(x + radius / 2, y - radius / 2), Scalar(74, 92, 255), 2, 8);
	printf("%d x %d\n", x, y);
	file << framesCount << " : " << x << " ; " << y << endl;
	coordMass.insert(coordMass.begin(), x);
	coordMass.insert(coordMass.begin() + 1, y);
	coordMass.insert(coordMass.begin() + 2, framesCount);
	Mat imagewithDraws(img.clone());
	imshow(windowName, imagewithDraws);
}

void Annotator::deleteTarget(const Mat & img, int x, int y, int radius)
{
	rectangle(img, Point(x - 30, y + 30), Point(x + 30, y - 30), (0, 255, 0), 3);
	for (int i = 0; i < coordMass.size() - 2; i++) {
		int xCoord = abs(x - coordMass[i]);
		int yCoord = abs(coordMass[i + 1] - y);
		if (pow((pow(xCoord, 2) + pow(yCoord, 2)), 0.5) <= 30 && framesCount == coordMass[i + 2]) {
			printf("The target with coordinates %d x %d  was deleted\n", coordMass[i], coordMass[i + 1]);
			file << framesCount << " ! " << coordMass[i] << " ; " << coordMass[i + 1] << endl;
			coordMass.erase(coordMass.begin() + i);
			coordMass.erase(coordMass.begin() + i);
			coordMass.erase(coordMass.begin() + i);
			break;
		}
		i++;
	}
	Mat imagewithDraws(img.clone());
	imshow(windowName, imagewithDraws);
}

void Annotator::drawExistedTargets(const Mat & img)
{
	int radius = circleRadius;
	for (int i = 0; i < coordMass.size() - 2; i++) {
		if (framesCount == coordMass[i + 2]) {
			int x = coordMass[i];
			int y = coordMass[i + 1];
			circle(img, Point(x, y), radius, Scalar(74, 92, 255), 2, 8);
			line(img, Point(x - radius / 2, y - radius / 2), cvPoint(x + radius / 2, y + radius / 2), Scalar(74, 92, 255), 2, 8);
			line(img, Point(x - radius / 2, y + radius / 2), cvPoint(x + radius / 2, y - radius / 2), Scalar(74, 92, 255), 2, 8);
			printf("%d x %d\n", x, y);
			i = i + 3;
		}
		Mat imagewithDraws(img.clone());
		imshow(windowName, imagewithDraws);
	}
}

string Annotator::getWinName() {
	return this->windowName;
}

void Annotator::checkCoordinatesInFile()
{
	int i = 0;
	string s;
	int getCapture(0);
	int getX(0);
	int getY(0);
	char toch1(' : ');
	char toch2(' ; ');
	int k = 0;
	while (!rFile.eof()) {
		rFile >> getCapture >> toch1 >> getX >> toch2 >> getY;
		if (toch1 == '!') {
			for (int j = 0; j < coordMass.size() - 2; j++) {
				if (coordMass[j + k] == getX && coordMass[j + k + 1] == getY && coordMass[j + k + 2] == getCapture) {
					coordMass.erase(coordMass.begin() + j);
					coordMass.erase(coordMass.begin() + j);
					coordMass.erase(coordMass.begin() + j);
					i=i-3;
				}
			}
			getline(rFile, s, '\n');
		}
		else {
			coordMass.insert(coordMass.begin() + i, getX);
			coordMass.insert(coordMass.begin() + i + 1, getY);
			coordMass.insert(coordMass.begin() + i + 2, getCapture);
			i = i + 3;
		}
	}
	rFile.close();
}
