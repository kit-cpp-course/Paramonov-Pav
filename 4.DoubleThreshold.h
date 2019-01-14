#pragma once

#include "3.Non-Maximum.h"
#ifndef DOB_H
#define DOB_H

class DThres :public NonMax {
private:
	float const down = 0.55 * 255;
	float const up = 0.60 * 255;
protected:
	double** DoubleThresholdMat;
public:
	/*
	����������� ������ 
	���������� :
	- ������������� ������������� �������
	- ���������� �����
	*/
	DThres(Mat ImgMat);

	/*
	���������� �����
	*/
	void CalculateDoubleThreshold();
	/*
	��������� ���������� �����
	*/
	Mat GetDoubleThresholdResult();
	~DThres() {
		for (int i = 0; i < rows; i++) {
			delete[]  DoubleThresholdMat[i];
		}
		delete[]  DoubleThresholdMat;
	}
};


#endif DOB_H