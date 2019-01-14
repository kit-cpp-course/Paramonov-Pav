#pragma once
#include <atlimage.h>
#include <iostream>
#include "0.Image.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
class Parasite {
public:
	unsigned short rows;
	unsigned short columns;
	unsigned short ichnl;
	unsigned short Step;
	uchar *ImgData;
	double **RGBMat;
	Mat ProducedImage;
	/*
	 онструктор принимает на вход следующие параметры
	@param Grows - кол-во р€дов в матрице изображени€
	@param Gcolumns - кол-во столбцов в матрице изображени€
	@param Gch - кол-во каналов в изображении
	@param Gstep - размер шага в Opencv (необходимо дл€ преобразовани€  матрицы изображени€ в Mat)
	*/
	Parasite(unsigned short Grows, unsigned short Gcols, unsigned short Gch, unsigned short Gstep) {
		rows = Grows;
		columns = Gcols;
		ichnl = Gch;
		Step = Gstep;
	}
	/*
	ѕеревод ћатрицы OpenCV в двумерный массив
	@param uchar ImageArray - матрица изображени€ OpenCV 
	*/
	void MatToSArr(uchar *ImageArray);
	/*
	ѕеревод двумерного массива в ћатрицу OpenCV
	@param double ** Array - двумерный массив 
	*/
	void SArrToMat(double ** Array);
	/*
	 опирование данных двумерных массивов
	@param double ** Source - источник копировани€
	@param double ** Target - цель копировани€
	*/
	void CopyArrays(double **Source, double **Target);
};