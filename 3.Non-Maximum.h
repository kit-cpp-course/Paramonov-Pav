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
	NonMax(Mat ImgMat) :GradientSearch(ImgMat) {
		RMatrix = new double *[rows];    // массив указателей (2)
		for (int i = 0; i < rows; i++) {   // (3)
			RMatrix[i] = new double[columns];     // инициализация указателей
		}
		
		
		CopyArrays(MagArr, RMatrix);

		NonMaxSupr();
		CopyArrays(RMatrix, RGBMat);
	}
	void NonMaxSupr();
	Mat GetNonMaxSuprResult();
	~NonMax() {
		for (int i = 0; i < rows; i++) {
			delete[] RMatrix[i];
		}
		delete[] RMatrix;
	}
};

void NonMax::NonMaxSupr() {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			di = sgn(cos(VMapArr[j][i]));
			dj = -sgn(sin(VMapArr[j][i]));
			if ((j + dj > 0 && j + dj < rows) & (i + di > 0 && i + di < columns)) {
				if (MagArr[j + dj][i + di] <= MagArr[j][i]) {
					RMatrix[j + dj][i + di] = 0;
				}
			}

			if ((j - dj > 0 && j - dj < rows) & (i - di > 0 && i - di < columns)) {
				if (MagArr[j - dj][i - di] <= MagArr[j][i]) {
					RMatrix[j - dj][i - di] = 0;
				}
			}
		}
	}
}

Mat NonMax::GetNonMaxSuprResult() {
	Parasite::SArrToMat(RMatrix);
	return Parasite::ProducedImage;
}