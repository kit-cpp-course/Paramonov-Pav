#pragma once
#include "0.Image.h"
#include <math.h>
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
class NonMax :public Image {
private:
	short di;
	short dj;
	double ** RMatrix;
public:
	NonMax(short GRows, short GColumns, double** RGBMat) :Image(GRows, GColumns) {
		RMatrix = RGBMat;
	}
	double** NonMaxSupr(double** RGBMat, double** VMapArr);
};

double** NonMax::NonMaxSupr(double** RGBMat, double** VMap) {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			di = sgn(cos(VMap[j][i]));
			dj = -sgn(sin(VMap[j][i]));
			if ((j + dj > 0 && j + dj < rows) & (i + di > 0 && i + di < columns)) {
				if (RGBMat[j + dj][i + di] <= RGBMat[j][i]) {
					RMatrix[j + dj][i + di] = 0;
				}
			}

			if ((j - dj > 0 && j - dj < rows) & (i - di > 0 && i - di < columns)) {
				if (RGBMat[j + dj][i + di] <= RGBMat[j][i]) {
					RMatrix[j - dj][i - di] = 0;
				}
			}
		}
	}
	return RMatrix;
}