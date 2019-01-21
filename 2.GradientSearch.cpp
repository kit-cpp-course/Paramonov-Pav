#include "pch.h"
#include "2.GradientsSearch.h"


GradientSearch::GradientSearch(Mat ImgMat) : Smoothed(ImgMat) {
	
	MagArr.Init(rows, columns);
	VMapArr.Init(rows, columns);
	SubArr.Init(rows, columns);
	
	FindGradient();
	CopyArrays(MagArr.Array, RGBMat);
}


void GradientSearch::FindGradient() {
	for (int i = 1; i < columns - 1; i++) {
		for (int j = 1; j < rows - 1; j++) {
			SGx = 0;//Сумма операторов Собеля умноженных на матрицу
			SGy = 0;//Сумма операторов Собеля умноженных на матрицу

			//Получение матрицы 3x3 исходного изображения для вычислений 
			SubArr.Array[0][0] = RGBMat[j - 1][i - 1];
			SubArr.Array[1][0] = RGBMat[j][i - 1];
			SubArr.Array[2][0] = RGBMat[j + 1][i - 1];

			SubArr.Array[0][1] = RGBMat[j - 1][i];
			SubArr.Array[1][1] = RGBMat[j][i];
			SubArr.Array[2][1] = RGBMat[j + 1][i];

			SubArr.Array[0][2] = RGBMat[j - 1][i + 1];
			SubArr.Array[1][2] = RGBMat[j][i + 1];
			SubArr.Array[2][2] = RGBMat[j + 1][i + 1];


			for (int Mj = 0; Mj < 3; Mj++) { //j - (j - 1)
				for (int Mi = 0; Mi < 3; Mi++) {
					SGx = SGx + SubArr.Array[Mj][Mi] * Gx[Mj][Mi];//Здесь ошибка 
					SGy = SGy + SubArr.Array[Mj][Mi] * Gy[Mj][Mi];
				}
			}
			MagArr.Array[j][i] = sqrt(pow(SGx, 2) + pow(SGy, 2));
			VMapArr.Array[j][i] = (round(pi*atan2f(SGx, SGy) / 4)* pi / 4) - (pi / 2);
		}
	}

}