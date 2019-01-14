#pragma once
#include "0.Image.h"
#include "2.GradientsSearch.h"
#include <math.h>
#include <iostream>
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
class NonMax :public GradientSearch{
private:
	short di;
	short dj;
protected:
	double ** RMatrix;
public:
	/*
	����������� ������ 
	����������:
	- ������������� ������������ ��������
	- ���������� �� ����������
	*/
	NonMax(Mat ImgMat);
	
	/*
	����� ����������� ���������� �� ����������
	*/
	void NonMaxSupr();
	
	/*
	����� ���������� �� ��������� ���������� �����
	*/
	Mat GetNonMaxSuprResult();
	~NonMax() {
		for (int i = 0; i < rows; i++) {
			delete[] RMatrix[i];
		}
		delete[] RMatrix;
	}
};

