#include "pch.h"
#include "3.Non-Maximum.h"
NonMax::NonMax(Mat ImgMat) :GradientSearch(ImgMat) {
	RMatrix = new double *[rows];    // массив указателей (2)
	for (int i = 0; i < rows; i++) {   // (3)
		RMatrix[i] = new double[columns];     // инициализация указателей
	}


	CopyArrays(MagArr, RMatrix);

	NonMaxSupr();
	CopyArrays(RMatrix, RGBMat);
}

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