#pragma once
#include "0.Image.h"
class Smoothed{
public :

	Smoothed();
	~Smoothed();
	short ** GetSmothedRGBMat(short ** RGBMat);// ���������� OpenCV (������� ������)
};