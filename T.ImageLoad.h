#pragma once
#include <atlimage.h>
#include <iostream>
#include "0.Image.h"
using namespace std;

class ImageLoad:public Image {
private:
	CImage image;
public:
	short ** RGBArr;
	ImageLoad(); //Конструктор без параметров

	ImageLoad(LPCTSTR Path) {
		image.Load(Path); // just change extension to load jpg
		rows = image.GetHeight();
		columns = image.GetWidth();

		RGBArr = new short *[rows];    // массив указателей (2)
		for (int i = 0; i < rows; i++) {   // (3)
			RGBArr[i] = new short[columns];     // инициализация указателей
		}
	}

	short ** GetRGBArr() {
		for (size_t y = 0; y < image.GetHeight(); ++y)
		{
			for (size_t x = 0; x < image.GetWidth(); ++x)
			{
				RGBArr[y][x] = image.GetPixel(x, y);
			}
		}
		return RGBArr;
	}

	~ImageLoad() {
		for (int i = 0; i < rows; i++) {
			delete[] RGBArr[i];
		}
		delete[] RGBArr;
	}
};

