#include "pch.h"
#include "4.DoubleThreshold.h"

DThres::DThres(Mat ImgMat) : NonMax(ImgMat) {
	DoubleThresholdMat.Init(rows, columns);
	CalculateDoubleThreshold();
	Parasite::CopyArrays(RGBMat, DoubleThresholdMat.Array);
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
	Parasite::SArrToMat(DoubleThresholdMat.Array);
	return Parasite::ProducedImage;
}