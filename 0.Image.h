#pragma once
#include <atlimage.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class Image {
private:
	Mat Srcimg;
public:
	short rows;
	short columns;

	Image(short GRows, short GColumns) {
		rows = GRows;
		columns = GColumns;
	}
};

