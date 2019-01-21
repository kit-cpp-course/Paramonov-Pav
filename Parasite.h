#pragma once
#include <atlimage.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
/*
����� �������� ������ ���:
-�������������� ��������� �������� � Mat � �������
-����������� ��������� �������� 
*/
class Parasite{
private:
	size_t rows; //������ �����������(����� ����� �������)
	size_t columns;//������ �����������(����� ������ �������)
	size_t ichnl;//����� ������� �����������
	size_t Step; //��� � ������� ������ OpenCV
public:
	uchar *ImgData; //������ ������ OpenCV
	double **RGBMat; //������� ����������� 
	Mat ProducedImage; //������ ���� Mat OpenCV
	/*
	����������� ��������� �� ���� ��������� ���������
	@param Grows - ���-�� ����� � ������� �����������
	@param Gcolumns - ���-�� �������� � ������� �����������
	@param Gch - ���-�� ������� � �����������
	@param Gstep - ������ ���� � Opencv (���������� ��� ��������������  ������� ����������� � Mat)
	*/
	Parasite(size_t Grows, size_t Gcols, size_t Gch, size_t Gstep) {
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
	/*
	�������� ������ �����������
	*/
	size_t GetImgRows() { return rows; };
	/*
	�������� ������ �����������
	*/
	size_t GetImgCols() { return columns; };
};