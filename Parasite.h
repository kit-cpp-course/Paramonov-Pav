#pragma once
#include <atlimage.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
/*
 ласс содержит методы дл€:
-преобразовани€ двумерных массивов в Mat и обратно
-копирование элементов массивов 
*/
class Parasite{
private:
	size_t rows; //высота изображени€(число р€дов матрицы)
	size_t columns;//ширина изображени€(число колонн матрицы)
	size_t ichnl;//число каналов изображени€
	size_t Step; //шаг в массиве данных OpenCV
public:
	uchar *ImgData; //массив данных OpenCV
	double **RGBMat; //ћатрица »зображени€ 
	Mat ProducedImage; //элмент типа Mat OpenCV
	/*
	 онструктор принимает на вход следующие параметры
	@param Grows - кол-во р€дов в матрице изображени€
	@param Gcolumns - кол-во столбцов в матрице изображени€
	@param Gch - кол-во каналов в изображении
	@param Gstep - размер шага в Opencv (необходимо дл€ преобразовани€  матрицы изображени€ в Mat)
	*/
	Parasite(size_t Grows, size_t Gcols, size_t Gch, size_t Gstep) {
		rows = Grows;
		columns = Gcols;
		ichnl = Gch;
		Step = Gstep;
	}
	/*
	ѕеревод ћатрицы OpenCV в двумерный массив
	@param uchar ImageArray - матрица изображени€ OpenCV 
	*/
	void MatToSArr(uchar *ImageArray);
	/*
	ѕеревод двумерного массива в ћатрицу OpenCV
	@param double ** Array - двумерный массив 
	*/
	void SArrToMat(double ** Array);
	/*
	 опирование данных двумерных массивов
	@param double ** Source - источник копировани€
	@param double ** Target - цель копировани€
	*/
	void CopyArrays(double **Source, double **Target);
	/*
	ѕолучить ¬ысоту изображени€
	*/
	size_t GetImgRows() { return rows; };
	/*
	ѕолучить Ўирину изображени€
	*/
	size_t GetImgCols() { return columns; };
};