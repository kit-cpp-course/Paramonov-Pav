#include "pch.h"
#include "5.EdgeTracking.h"
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


