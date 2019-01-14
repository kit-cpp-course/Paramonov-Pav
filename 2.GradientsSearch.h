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
	Констркутор Класса
	Производит:
	- Создание динамический массивов 
	- Поиск Градиентов 
	*/
	GradientSearch(Mat ImgMat); 
	/*
	Метод проводящий поиск градиентов
	*/
	void FindGradient();
	~GradientSearch();
	/*
	Получение результатов этапа
	Возвращаемое значение Mat
	*/
	Mat GetGradientSearchResult() {
		Parasite::SArrToMat(MagArr);
		return Parasite::ProducedImage;
	}
	
private:
	short Gx[3][3] = { {-1,0,1}, {-2,0,2}, {-1,0,1 } };//Матрицы оператора Собеля
	short Gy[3][3] = { {-1,-2,-1},{0,0,0},{ 1, 2, 1} };//Матрицы оператора Собеля
	double pi = atan(1) * 4; //Пи
};


