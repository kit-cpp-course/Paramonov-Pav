#pragma once
#include "4.DoubleThreshold.h"
#ifndef EDGE_H
#define EDGE_H
class EdgeTrack :public DThres {
private:
	short movdir[2][8] = { {-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1} };
	short High = 255;
	short Low = 127;
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




