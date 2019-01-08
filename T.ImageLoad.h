#pragma once
#pragma once
#include <atlimage.h>
#include <iostream>
#include "0.Image.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include "Parasite.h"
using namespace std;
using namespace cv;


class ImageLoad{
protected:
	Mat RGBMat;
public:
	/*
	Произвести загрузку изображения 
	@param Path (string) - Путь к изображению 
	*/
	ImageLoad(string Path){
		RGBMat = imread(Path,IMREAD_GRAYSCALE);
	}
	/*
	Получить Матрицу Изображения 
	*/
	Mat GetMat() {
		return RGBMat;
	}
};

