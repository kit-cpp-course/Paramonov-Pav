#include "pch.h"
#include "4.DoubleThreshold.h"

DThres::DThres(Mat ImgMat) : NonMax(ImgMat) {
	DoubleThresholdMat = new double *[rows];    // массив указателей (2)
	for (int i = 0; i < rows; i++) {   // (3)
		DoubleThresholdMat[i] = new double[columns];     // инициализация указателей
	}

	CalculateDoubleThreshold();
	Parasite::CopyArrays(RGBMat, DoubleThresholdMat);
};
void DThres::CalculateDoubleThreshold() {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			if (RGBMat[j][i] >= up) {
				RGBMat[j][i] = 255;
			}
			else {
				(RGBMat[j][i] <= down) ? RGBMat[j][i] = 0 : RGBMat[j][i] = 127;
			}
		}
	}
}

Mat DThres::GetDoubleThresholdResult() {
	Parasite::SArrToMat(DoubleThresholdMat);
	return Parasite::ProducedImage;
}