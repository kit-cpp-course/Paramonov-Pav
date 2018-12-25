#include "0.Image.h"
#include <math.h>

class GradientSearch:public Image {
public:
	const short SobelArr = 3;
	double ** MagArr;
	//double ** VMapArr;
	
	GradientSearch(short GRows, short GColumns) :Image(GRows, GColumns) {
		MagArr = new double *[rows];    // массив указателей (2)
		for (int i = 0; i < rows; i++) {   // (3)
			MagArr[i] = new double[columns];     // инициализация указателей
		}

		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				MagArr[j][i] = 0;
			}
		}
	}
	short ** GetGradientRGBMat(short **RGBMat, double ** &VMapArr) {
		float SGx = 0;//Сумма операторов Собеля умноженных на матрицу
		float SGy = 0;//Сумма операторов Собеля умноженных на матрицу
		for (int i = 1; i < columns; i++) {
			for (int j = 1; j < rows; j++) {

				for (int Mj = j - 1; j < 3; j++) {
					for (int Mi = i - 1; i < 3; i++) {
						SGx = SGx + RGBMat[Mj][Mi] * Gx[Mj][Mi];
						SGy = SGy + RGBMat[Mj][Mi] * Gy[Mj][Mi];
					}
				}
				MagArr[j][i] = sqrt(pow(SGx, 2) + pow(SGy, 2));
				VMapArr[j][i] = round(pi*atan2(SGx, SGy) / 4)* pi / 4 - pi / 2;
			}
		}
	}
	~GradientSearch();

private:
	short Gx[3][3] = { {-1,0,1}, {-2,0,2}, {-1,0,1 } };//Матрицы оператора Собеля
	short Gy[3][3] = { {-1,-2,-1},{0,0,0},{ 1, 2, 1} };//Матрицы оператора Собеля
	double pi = atan(1) * 4; //Пи
};

//GradientSearch::



GradientSearch::~GradientSearch() {
	for (int i = 0; i < rows; i++) {
		delete[] MagArr[i];
	}
	delete[] MagArr;
}