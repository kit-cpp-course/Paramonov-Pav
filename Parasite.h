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
	void MatToSArr(uchar *ImageArray) {
		ImgData = ImageArray;

		RGBMat = new double *[rows];
		for (int i = 0; i < rows; i++) {
			RGBMat[i] = new double[columns];
		}

		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < columns; c++) {
				for (int ch = 0; ch < ichnl; ch++) {
					RGBMat[r][c] = ImgData[(ichnl*Step*r) + (ichnl*c) + ch];
				}
			}
		}
	}
	void SArrToMat(double ** Array) {
		//RGBMat = Array;

		ImgData = new uchar[rows*columns];
		for (int i = 0; i < rows*columns; i++) {
			ImgData[i] = 0;
		}

		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < columns; c++) {
				for (int ch = 0; ch < ichnl; ch++) {
					ImgData[(ichnl*Step*r) + (ichnl*c) + ch] = Array[r][c];
				}
			}
		}

		ProducedImage.rows = rows;
		ProducedImage.cols = columns;
		ProducedImage.step = Step;
		ProducedImage.data = ImgData;
	}

	void CopyArrays(double **Source, double **Target) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < columns; c++) {
				Target[r][c] = Source[r][c];
			}
		}
	}
};