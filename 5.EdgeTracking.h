#pragma once
#pragma once
#include "0.Image.h"
class EdgeTrack :public Image {
private:
	short movdir[2][8] = { {-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1} };
	short High = 255;
	short Low = 127;
public:
	EdgeTrack(short GRows, short GColumns) : Image(GRows, GColumns) {

	}
	double** GetEdgeTrackMat(double** RGBMat);
};

double** EdgeTrack::GetEdgeTrackMat(double** RGBMat) {
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			if (RGBMat[j][i] <= Low) {
				RGBMat[j][i] = 0;
			}
			else {
				if (RGBMat[j][i] >= High) {
					RGBMat[j][i] = 255;
				}
				else {
					if ((RGBMat[j + 1][i] > High) || (RGBMat[j - 1][i] > High) || (RGBMat[j][i + 1] > High) || (RGBMat[j][i - 1] > High)) {
						RGBMat[j][i] = 255;
					}
				}
			}
		}
	}
	return RGBMat;
}