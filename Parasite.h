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
	����������� ��������� �� ���� ��������� ���������
	@param Grows - ���-�� ����� � ������� �����������
	@param Gcolumns - ���-�� �������� � ������� �����������
	@param Gch - ���-�� ������� � �����������
	@param Gstep - ������ ���� � Opencv (���������� ��� ��������������  ������� ����������� � Mat)
	*/
	Parasite(unsigned short Grows, unsigned short Gcols, unsigned short Gch, unsigned short Gstep) {
		rows = Grows;
		columns = Gcols;
		ichnl = Gch;
		Step = Gstep;
	}
	/*
	������� ������� OpenCV � ��������� ������
	@param uchar ImageArray - ������� ����������� OpenCV 
	*/
	void MatToSArr(uchar *ImageArray);
	/*
	������� ���������� ������� � ������� OpenCV
	@param double ** Array - ��������� ������ 
	*/
	void SArrToMat(double ** Array);
	/*
	����������� ������ ��������� ��������
	@param double ** Source - �������� �����������
	@param double ** Target - ���� �����������
	*/
	void CopyArrays(double **Source, double **Target);
};