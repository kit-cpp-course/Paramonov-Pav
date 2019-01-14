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
	Конструктор класса 
	Производит:
	- Инициализацию динамических массивов
	- Подавление не максимумов
	*/
	NonMax(Mat ImgMat);
	
	/*
	Метод выполняющий подавление не максимумов
	*/
	void NonMaxSupr();
	
	/*
	Метод отвечающий за получение результата Этапа
	*/
	Mat GetNonMaxSuprResult();
	~NonMax() {
		for (int i = 0; i < rows; i++) {
			delete[] RMatrix[i];
		}
		delete[] RMatrix;
	}
};

