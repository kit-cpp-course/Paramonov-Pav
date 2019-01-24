#pragma once

#include "3.Non-Maximum.h"
#include "T_ImgArray.h"
#ifndef DOB_H
#define DOB_H
/*
Класс реализует четвертый этап алгоритма Кэнни(Двойная пороговая фильтрация)
*/
class DThres :public NonMax {
private:
	float const down = 0.55 * 255;//Нижний порог
	float const up = 0.60 * 255;//Верхний порог
	const size_t rows = GetImgRows();
	const size_t columns = GetImgCols();
protected:
	TArray DoubleThresholdMat;
public:
	/*
	Конструктор класса 
	Производит :
	- Инициализацию динамического массива
	- Выполнение этапа
	*/
	DThres(Mat ImgMat);

	/*
	Выполнение Этапа
	*/
	void CalculateDoubleThreshold();
	/*
	Получение результата Этапа
	*/
	Mat GetDoubleThresholdResult();
};


#endif DOB_H