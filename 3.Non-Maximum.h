#pragma once
#include "0.Image.h"
#include "2.GradientsSearch.h"
#include "T_ImgArray.h"
#include <math.h>
#include <iostream>

// Шаблон математической фукнции sign
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
/*
Класс реализует третий этап алгоритма Кэнни(Подавление Не максимумов)
*/
class NonMax :public GradientSearch{
private:
	short di;//Переменные отвечающие за смещение 
	short dj;//Переменные отвечающие за смещение
	const size_t rows = GetImgRows(); //Размеры изображения постоянные
	const size_t columns = GetImgCols(); //Размеры изображения постоянные
protected:
	TArray RMatrix;//Матрица Этапа 
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
};

