#include "pch.h"
#include "3.Non-Maximum.h"
NonMax::NonMax(Mat ImgMat) :GradientSearch(ImgMat) {
	RMatrix.Init(rows, columns);
	RMatrix = MagArr;
	NonMaxSupr();
	CopyArrays(RMatrix.Array, RGBMat);
}

void NonMax::NonMaxSupr() {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			di = sgn(cos(VMapArr.Array[j][i]));
			dj = -sgn(sin(VMapArr.Array[j][i]));
			if ((j + dj > 0 && j + dj < rows) & (i + di > 0 && i + di < columns)) {
				if (MagArr.Array[j + dj][i + di] <= MagArr.Array[j][i]) {
					RMatrix.Array[j + dj][i + di] = 0;
				}
			}

			if ((j - dj > 0 && j - dj < rows) & (i - di > 0 && i - di < columns)) {
				if (MagArr.Array[j - dj][i - di] <= MagArr.Array[j][i]) {
					RMatrix.Array[j - dj][i - di] = 0;
				}
			}
		}
	}
}

Mat NonMax::GetNonMaxSuprResult() {
	Parasite::SArrToMat(RMatrix.Array);
	return Parasite::ProducedImage;
}