#pragma once
#include "T_ImgArray.h"
#include "1.Smothing.h"
#include <math.h>
using namespace std;
/*
����� ��������� ������ ���� ��������� �����(����� ���������� �����������)
*/
class GradientSearch :public Smoothed {
private:
	TArray SubArr; //���������� (�������� �� ������� �����������)
	short Gx[3][3] = { {-1,0,1}, {-2,0,2}, {-1,0,1 } };//������� ��������� ������
	short Gy[3][3] = { {-1,-2,-1},{0,0,0},{ 1, 2, 1} };//������� ��������� ������
	double pi = atan(1) * 4; //��
	double SGx = 0;//����� ���������� ������ ���������� �� �������
	double SGy = 0;//����� ���������� ������ ���������� �� �������
	const size_t rows = GetImgRows();
	const size_t columns = GetImgCols();
protected:
	TArray MagArr;//��������� ������ ���������� ��������� �����������
	TArray VMapArr;//��������� ������ ���������� ���� �������� �������� �����������

public:
	const short SobelArr = 3;//������ ������� ��������� ������
	/*
	����������� ������
	����������:
	- �������� ������������ ��������
	- ����� ����������
	*/
	GradientSearch(Mat ImgMat);
	/*
	��������� ����������� �����
	������������ �������� Mat
	*/
	Mat GetGradientSearchResult() {
		Parasite::SArrToMat(MagArr.Array);
		return Parasite::ProducedImage;
	}
private:
	/*
	����� ���������� ����� ����������
	*/
	void FindGradient();
};


