#pragma once
#include "0.Image.h"
#include "3.Non-Maximum.h"
class DThres :public NonMax {
private:
	float const down = 0.55 * 255;
	float const up = 0.60 * 255;
protected:
	double** DoubleThresholdMat;
public:
	DThres(Mat ImgMat) : NonMax(ImgMat) {
		DoubleThresholdMat = new double *[rows];    // массив указателей (2)
		for (int i = 0; i < rows; i++) {   // (3)
			DoubleThresholdMat[i] = new double[columns];     // инициализация указателей
		}

		CalculateDoubleThreshold();
		Parasite::CopyArrays(RGBMat, DoubleThresholdMat);
	};
	void CalculateDoubleThreshold();
	Mat GetDoubleThresholdResult();
	~DThres() {
		for (int i = 0; i < rows; i++) {
			delete[]  DoubleThresholdMat[i];
		}
		delete[]  DoubleThresholdMat;
	}
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