#pragma once
#include "0.Image.h"
#include "1.Smothing.h"
#include <math.h>

class GradientSearch :public Smoothed {
private:
	double ** SubArr;
protected:
	double ** MagArr; 
	double ** VMapArr;
public:
	const short SobelArr = 3;
	/*
	����������� ������
	����������:
	- �������� ������������ �������� 
	- ����� ���������� 
	*/
	GradientSearch(Mat ImgMat); 
	/*
	����� ���������� ����� ����������
	*/
	void FindGradient();
	~GradientSearch();
	/*
	��������� ����������� �����
	������������ �������� Mat
	*/
	Mat GetGradientSearchResult() {
		Parasite::SArrToMat(MagArr);
		return Parasite::ProducedImage;
	}
	
private:
	short Gx[3][3] = { {-1,0,1}, {-2,0,2}, {-1,0,1 } };//������� ��������� ������
	short Gy[3][3] = { {-1,-2,-1},{0,0,0},{ 1, 2, 1} };//������� ��������� ������
	double pi = atan(1) * 4; //��
};


