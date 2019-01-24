#pragma once
#include "0.Image.h"
#include "2.GradientsSearch.h"
#include "T_ImgArray.h"
#include <math.h>
#include <iostream>

// ������ �������������� ������� sign
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
/*
����� ��������� ������ ���� ��������� �����(���������� �� ����������)
*/
class NonMax :public GradientSearch{
private:
	short di;//���������� ���������� �� �������� 
	short dj;//���������� ���������� �� ��������
	const size_t rows = GetImgRows(); //������� ����������� ����������
	const size_t columns = GetImgCols(); //������� ����������� ����������
protected:
	TArray RMatrix;//������� ����� 
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
};

