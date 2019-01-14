#include "pch.h"
#include "Parasite.h"

void Parasite::MatToSArr(uchar *ImageArray) {
	ImgData = ImageArray;

	RGBMat = new double *[rows];
	for (int i = 0; i < rows; i++) {
		RGBMat[i] = new double[columns];
	}

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			for (int ch = 0; ch < ichnl; ch++) {
				RGBMat[r][c] = ImgData[(ichnl*Step*r) + (ichnl*c) + ch];
			}
		}
	}
}
void Parasite::SArrToMat(double ** Array) {
	//RGBMat = Array;

	ImgData = new uchar[rows*columns];
	for (int i = 0; i < rows*columns; i++) {
		ImgData[i] = 0;
	}

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			for (int ch = 0; ch < ichnl; ch++) {
				ImgData[(ichnl*Step*r) + (ichnl*c) + ch] = Array[r][c];
			}
		}
	}

	ProducedImage.rows = rows;
	ProducedImage.cols = columns;
	ProducedImage.step = Step;
	ProducedImage.data = ImgData;
}

void Parasite::CopyArrays(double **Source, double **Target) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			Target[r][c] = Source[r][c];
		}
	}
}