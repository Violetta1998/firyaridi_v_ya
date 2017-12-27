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
#include <thread>

using namespace std;
using namespace cv;

class Annotator {
public:
	Annotator();
	~Annotator() = default;
	void drawTarget(const Mat& img, int x, int y, int radius);
	void deleteTarget(const Mat& img, int x, int y, int radius);
	void drawExistedTargets(const Mat& img);
	string getWinName();
	void createNewFile(string name);
	void checkCoordinatesInFile();
	void insertFramesIntoVector(Mat& img);
	void readSettingsFromConfig();
	void getVideoPaths(string pathToFile);
	cv::Mat3b matImgG;
	cv::Mat3b matImgB;
	string keys;
	int countVideosNumber;
	double framesCount;
	char wait;
	std::vector<string> filePaths;
	vector<Mat> framesVideo;
	ofstream file;
	ifstream rFile;

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
				app.drawTarget(app.matImgG, x, y, app.circleRadius);
			}

			case CV_EVENT_LBUTTONUP:
				break;

			case CV_EVENT_RBUTTONDOWN:
			{
				app.deleteTarget(app.matImgG, x, y, app.delRadius);
			}
			case CV_EVENT_RBUTTONUP:
				break;
			default:
				break;
			}
		}
	}
private:
	String windowName;
	ofstream configFile;
	ifstream configFileR;
	std::vector<int> coordMass;
	int circleRadius;
	int delRadius;
};


int main(int argc, const char* argv[]) {
	Annotator app;
	app.readSettingsFromConfig();
	app.getVideoPaths("C:\\temp\\proga\\bin.win64.vc2015.dbg\\paths.txt");//argv[1]
	int countVideos = 0;
	CommandLineParser parser(argc, argv, app.keys);
	string filename = parser.get<string>(countVideos);
	std::size_t found = filename.find_last_of("/\\");
	string name = filename.substr(found + 1);
	app.rFile.open(name+".txt");
	app.checkCoordinatesInFile();
	app.createNewFile(name+".txt");

	printf("fileName: %s\n", name.c_str());
	VideoCapture capture(filename);
	Mat frame;
	char c, c2(0);

	for (int i = 0; i < capture.get(CAP_PROP_FRAME_COUNT);i++) {
		capture >> app.matImgG;
		frame = app.matImgG;
		app.matImgB = frame;

		if (capture.get(CAP_PROP_FRAME_COUNT) == i+1) {
			countVideos++;
			if (app.countVideosNumber <= countVideos) break;
			else {
				filename = parser.get<string>(countVideos);
				found = filename.find_last_of("/\\");
				name = filename.substr(found + 1);
				printf("fileName: %s\n", name.c_str());
				app.rFile.close();
				app.rFile.open(name + ".txt");
				app.checkCoordinatesInFile();
				app.createNewFile(name + ".txt");
				capture.open(filename);
				i = 0;
			}
		}

		app.insertFramesIntoVector(frame);
		//imshow(app.getWinName(), frame);
		app.drawExistedTargets(frame);

		if (c2 > 0) {
			c = c2;
			c2 = 0;
		}
		else c = waitKey(30);
		
		if (c > 0) {
			if (c == 27) {
				break;
			}
			if ('s' == c) {
				while (c2 == 0) {
					c2 = waitKey(0);
				}
			}
			if ('1' == c) {
					if (app.framesCount != 1) {
						app.framesCount = app.framesCount - 1;
						app.drawExistedTargets(app.framesVideo[app.framesCount]);
					}
					while (c2 == 0) {
						c2 = waitKey(0);
					}
				}

			if ('2' == c) {
					if (app.framesVideo[app.framesCount+2].rows != 0)
					{
					app.framesCount = app.framesCount + 2;
					app.drawExistedTargets(app.framesVideo[app.framesCount]);
					}
					while (c2 == 0) {
						c2 = waitKey(0);
				}	
			}
		}
		if(c<0) app.framesCount = capture.get(CAP_PROP_POS_FRAMES);
	}

	capture.release();
	cv::destroyAllWindows();
	return 0;
}

Annotator::Annotator()
	:circleRadius(10),
	delRadius(35),
	configFile("config.txt",ios_base::app),
	configFileR("config.txt", ios_base::in),
	coordMass(2),
	filePaths(1),
	framesVideo(2),
	framesCount(0.0),
	matImgG(100, 100),
	matImgB(100, 100),
	windowName("target video"),
	wait((char)waitKey(30000)),
	countVideosNumber(0)
{
	namedWindow(windowName, CV_WINDOW_KEEPRATIO);
	setMouseCallback(windowName, mouseCallback, this);
}

void Annotator::drawTarget(const Mat& img, int x, int y, int radius)
{
	circle(matImgB, Point(x, y), radius, Scalar(74, 92, 255), 2, 8);
	line(matImgB, Point(x - radius / 2, y - radius / 2), cvPoint(x + radius / 2, y + radius / 2), Scalar(74, 92, 255), 2, 8);
	line(matImgB, Point(x - radius / 2, y + radius / 2), cvPoint(x + radius / 2, y - radius / 2), Scalar(74, 92, 255), 2, 8);
	printf("%d x %d\n", x, y);
	file << framesCount << " : " << x << " ; " << y << endl;
	coordMass.insert(coordMass.begin(), x);
	coordMass.insert(coordMass.begin() + 1, y);
	coordMass.insert(coordMass.begin() + 2, framesCount);
	imshow(windowName, matImgB);
}

void Annotator::deleteTarget(const Mat& img, int x, int y, int radius)
{
	int xCoord, yCoord;
	for (int i = 0; i < coordMass.size() - 2; i++) {
		xCoord = abs(x - coordMass[i]);
		yCoord = abs(coordMass[i + 1] - y);
		if (pow((pow(xCoord, 2) + pow(yCoord, 2)), 0.5) <= delRadius && framesCount == coordMass[i + 2]) {
			printf("The target with coordinates %d x %d  was deleted\n", coordMass[i], coordMass[i + 1]);
			file << framesCount << " ! " << coordMass[i] << " ; " << coordMass[i + 1] << endl;
			coordMass.erase(coordMass.begin() + i);
			coordMass.erase(coordMass.begin() + i);
			coordMass.erase(coordMass.begin() + i);
			break;
		}
		i++;
	}
	drawExistedTargets(img);
}

void Annotator::drawExistedTargets(const Mat& img)
{
	int radius = circleRadius;
	int x, y,j=0;
	Mat imagewithDraws(img.clone());
	for (j = 0; j < coordMass.size() - 2; j++) {
		if (framesCount == coordMass[j + 2]) {
		    x = coordMass[j];
			y = coordMass[j + 1];
			circle(imagewithDraws, Point(x, y), radius, Scalar(74, 92, 255), 2, 8);
			line(imagewithDraws, Point(x - radius / 2, y - radius / 2), cvPoint(x + radius / 2, y + radius / 2), Scalar(74, 92, 255), 2, 8);
			line(imagewithDraws, Point(x - radius / 2, y + radius / 2), cvPoint(x + radius / 2, y - radius / 2), Scalar(74, 92, 255), 2, 8);
			j = j +2;
		}
	}
	matImgB = imagewithDraws.clone();
	imshow(windowName, imagewithDraws);
}

string Annotator::getWinName() {
	return this->windowName;
}

void Annotator::createNewFile(string name)
{
	file.close();
	rFile.close();
	file.open(name, ios_base::app);
	rFile.open(name, ios_base::in);
	printf("file with %s was created", name.c_str());
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

void Annotator::insertFramesIntoVector(Mat & img)
{
	Mat img2 = img.clone();
	framesVideo.insert(framesVideo.begin()+framesCount, img2);
}

void Annotator::readSettingsFromConfig()
{
	string s;
	string cR("circleRadius ");
	string dR("delRadius ");
			
	if (configFileR.peek() == EOF) {
		configFile << cR << circleRadius << endl;
		configFile << dR << delRadius;
	}
	
	while (!configFileR.eof()) {
		configFileR >> cR >> circleRadius;
		configFileR >> dR >> delRadius;
		getline(configFileR, s, '\n');
	}
	printf("CircleRadius : %d\n", delRadius);
	printf("DeleteRadius : %d\n", delRadius);
	configFile.close();
	configFileR.close();
}

void Annotator::getVideoPaths(string pathToFile)
{
	ifstream filePathsR;
	ofstream filePaths;
	string s;
	string k;
	string name;
	string path;
	std::size_t found;
	filePaths.open(pathToFile, ios_base::app);
	filePathsR.open(pathToFile, ios_base::in);
	while (!filePathsR.eof()) {
		filePathsR >> s;
		found = s.find_last_of("/\\");
		name = s.substr(found + 1);
		keys.insert(0, "{@" + name + "|" + s + " |input video}");
		countVideosNumber++;
		getline(filePathsR, s, '\n');
	}
	filePaths.close();
	filePathsR.close();

}

