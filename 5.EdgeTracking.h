#pragma once
#include "4.DoubleThreshold.h"
#ifndef EDGE_H
#define EDGE_H
/*
����� ��������� ��������� ����� ���� ��������� �����(����� ������)
*/
class EdgeTrack :public DThres {
private:
	short movdir[2][8] = { {-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1} };//������ ��� ��������� �������� ������ ������ 
	short High = 255;//�������� �������(max)
	short Low = 127;//�������� ������� ����������� ��� ���������(max)
	const size_t rows = GetImgRows();
	const size_t columns = GetImgCols();
public:
	/*
	���������� ������ 
	����������:
	- ���������� ����� ���������
	*/
	EdgeTrack(Mat ImgMat) : DThres(ImgMat) {
		CalculateEdgeTrackMat();
	}
	/*
	����� ����������� ���������� �����
	*/
	void CalculateEdgeTrackMat();
	/*
	����� ������������� ��������� ����� ���������
	*/
	Mat GetEdgeTrackingResult();
};
#endif EDGE_H




