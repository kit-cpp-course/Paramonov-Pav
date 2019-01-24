#pragma once
#include "4.DoubleThreshold.h"
#ifndef EDGE_H
#define EDGE_H
/*
Класс реализует последний пятый этап алгоритма Кэнни(Поиск границ)
*/
class EdgeTrack :public DThres {
private:
	short movdir[2][8] = { {-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1} };//массмв для просмотра пикселей вокруг одного 
	short High = 255;//Значения пикселя(max)
	short Low = 127;//Значения пикселя ставищегося под сосмнение(max)
	const size_t rows = GetImgRows();
	const size_t columns = GetImgCols();
public:
	/*
	Констрктор Класса 
	Производит:
	- Вычисление Этапа Алгоритма
	*/
	EdgeTrack(Mat ImgMat) : DThres(ImgMat) {
		CalculateEdgeTrackMat();
	}
	/*
	Метод выполняющий вычисление этапа
	*/
	void CalculateEdgeTrackMat();
	/*
	Метод возвращаяющий результат этапа алгоритма
	*/
	Mat GetEdgeTrackingResult();
};
#endif EDGE_H




