#pragma once
#include "T.ImageLoad.h"
#include "Parasite.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class Smoothed:public Parasite{
public :
	Mat SmoothedMat;
	/*
	Конструктор производит размытие изображения с помощью Opencv
	*/
	Smoothed(Mat ImgMat):Parasite(ImgMat.rows, ImgMat.cols, ImgMat.channels(),ImgMat.step) {
		GaussianBlur(ImgMat, SmoothedMat, Size(3, 3), 0, 0);
		Parasite::MatToSArr(SmoothedMat.data);
	}
	/*
	Получить Сглаженное изображение (1-ый этап алгоритма Canny)
	*/
	Mat GetSmoothedMat() {
		return SmoothedMat;
	}
};
