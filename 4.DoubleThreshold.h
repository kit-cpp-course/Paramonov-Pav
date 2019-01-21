#pragma once

#include "3.Non-Maximum.h"
#include "T_ImgArray.h"
#ifndef DOB_H
#define DOB_H
/*
����� ��������� ��������� ���� ��������� �����(������� ��������� ����������)
*/
class DThres :public NonMax {
private:
	float const down = 0.55 * 255;//������ �����
	float const up = 0.60 * 255;//������� �����
	const size_t rows = GetImgRows();
	const size_t columns = GetImgCols();
protected:
	TArray DoubleThresholdMat;
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
};


#endif DOB_H