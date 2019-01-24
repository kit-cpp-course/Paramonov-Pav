#pragma once
#include "T_ImgArray.h"
#include "1.Smothing.h"
#include <math.h>
using namespace std;
/*
Класс реализует второй этап алгоритма Кэнни(Поиск градиентов изображения)
*/
class GradientSearch :public Smoothed {
private:
	TArray SubArr; //ПодМатрица (выделена из матрицы изображения)
	short Gx[3][3] = { {-1,0,1}, {-2,0,2}, {-1,0,1 } };//Матрицы оператора Собеля
	short Gy[3][3] = { {-1,-2,-1},{0,0,0},{ 1, 2, 1} };//Матрицы оператора Собеля
	double pi = atan(1) * 4; //Пи
	double SGx = 0;//Сумма операторов Собеля умноженных на матрицу
	double SGy = 0;//Сумма операторов Собеля умноженных на матрицу
	const size_t rows = GetImgRows();
	const size_t columns = GetImgCols();
protected:
	TArray MagArr;//Двумерный массив содержащий магнитуду изображения
	TArray VMapArr;//Двумерный массив содержащий углы наклонов векторов изображения

public:
	const short SobelArr = 3;//Размер массива оператора Собеля
	/*
	Констркутор Класса
	Производит:
	- Создание динамический массивов
	- Поиск Градиентов
	*/
	GradientSearch(Mat ImgMat);
	/*
	Получение результатов этапа
	Возвращаемое значение Mat
	*/
	Mat GetGradientSearchResult() {
		Parasite::SArrToMat(MagArr.Array);
		return Parasite::ProducedImage;
	}
private:
	/*
	Метод проводящий поиск градиентов
	*/
	void FindGradient();
};


