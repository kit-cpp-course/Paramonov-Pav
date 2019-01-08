#pragma once
#include "4.DoubleThreshold.h"
class EdgeTrack :public DThres {
private:
	short movdir[2][8] = { {-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1} };
	short High = 255;
	short Low = 127;
public:
	EdgeTrack(Mat ImgMat) : DThres(ImgMat) {
		CalculateEdgeTrackMat();

	}
	void CalculateEdgeTrackMat();
	Mat GetEdgeTrackingResult();
};

void EdgeTrack::CalculateEdgeTrackMat() {
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
}

Mat EdgeTrack::GetEdgeTrackingResult() {
	Parasite::SArrToMat(RGBMat);
	return Parasite::ProducedImage;
}