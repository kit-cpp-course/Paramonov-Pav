#pragma once
#include "0.Image.h"
#include "1.Smothing.h"
#include <math.h>

class GradientSearch :public Smoothed {
private:
	double ** SubArr;
protected:
	double ** MagArr; 
	double ** VMapArr;
public:
	const short SobelArr = 3;

	GradientSearch(Mat ImgMat) : Smoothed(ImgMat) {
		MagArr = new double *[rows];    // ������ ���������� (2)
		for (int i = 0; i < rows; i++) {   // (3)
			MagArr[i] = new double[columns];     // ������������� ����������
		}

		
		VMapArr = new double *[rows];    // ������ ���������� (2)
		for (int i = 0; i < rows; i++) {   // (3)
			VMapArr[i] = new double[columns];     // ������������� ����������
		}

		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				VMapArr[j][i] = 0;
				MagArr[j][i] = 0;
			}
		}

		SubArr = new double *[3];    // ������ ���������� (2)
		for (int i = 0; i < 3; i++) {   // (3)
			SubArr[i] = new double[3];     // ������������� ����������
		}
		FindGradient();
		CopyArrays(MagArr, RGBMat);
	}
	void FindGradient() {
		for (int i = 1; i < columns - 1; i++) {
			for (int j = 1; j < rows - 1; j++) {
				float SGx = 0;//����� ���������� ������ ���������� �� �������
				float SGy = 0;//����� ���������� ������ ���������� �� �������


				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						SubArr[j][i] = 0;//��������� ���������� �������
					}
				}


				//��������� ������� 3x3 ��������� ����������� ��� ���������� 
				SubArr[0][0] = RGBMat[j - 1][i - 1];
				SubArr[1][0] = RGBMat[j][i - 1];
				SubArr[2][0] = RGBMat[j + 1][i - 1];

				SubArr[0][1] = RGBMat[j - 1][i];
				SubArr[1][1] = RGBMat[j][i];
				SubArr[2][1] = RGBMat[j + 1][i];

				SubArr[0][2] = RGBMat[j - 1][i + 1];
				SubArr[1][2] = RGBMat[j][i + 1];
				SubArr[2][2] = RGBMat[j + 1][i + 1];


				for (int Mj = 0; Mj < 3; Mj++) { //j - (j - 1)
					for (int Mi = 0; Mi < 3; Mi++) {
						SGx = SGx + SubArr[Mj][Mi] * Gx[Mj][Mi];//����� ������ 
						SGy = SGy + SubArr[Mj][Mi] * Gy[Mj][Mi];
					}
				}
				MagArr[j][i] = sqrt(pow(SGx, 2) + pow(SGy, 2));
				VMapArr[j][i] = (round(pi*atan2f(SGx, SGy) / 4)* pi / 4) - (pi / 2);
			}
		}
		
	}
	~GradientSearch();

	Mat GetGradientSearchResult() {
		Parasite::SArrToMat(MagArr);
		return Parasite::ProducedImage;
	}
	
private:
	short Gx[3][3] = { {-1,0,1}, {-2,0,2}, {-1,0,1 } };//������� ��������� ������
	short Gy[3][3] = { {-1,-2,-1},{0,0,0},{ 1, 2, 1} };//������� ��������� ������
	double pi = atan(1) * 4; //��
};


GradientSearch::~GradientSearch() {
	for (int i = 0; i < rows; i++) {
		delete[] MagArr[i];
		delete[] VMapArr[i];
	}
	delete[] MagArr;
	delete[] VMapArr;
}