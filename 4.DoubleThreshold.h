#pragma once
#include "0.Image.h"
class DThres :public Image {
private:
	float const down = 0.55 * 255;
	float const up = 0.60 * 255;
public:
	DThres(short GRows, short GColumns) : Image(GRows, GColumns) {};
	double** GetDThresMat(double** RGBMat);
};

double** DThres::GetDThresMat(double** RGBMat) {
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
	return RGBMat;
}