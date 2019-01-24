#include "pch.h"
#include "T_ImgArray.h"

TArray& TArray::operator= (TArray& Source) {
	for (int r = 0; r < Source.rows; r++) {
		for (int c = 0; c < Source.cols; c++) {
			this->Array[r][c] = Source.Array[r][c];
		}
	}
	return *this;
}
TArray::TArray()
{
}
void TArray::Init(size_t Grows, size_t Gcols) {
	rows = Grows;
	cols = Gcols;
	Array = new double *[rows];    // массив указателей (2)
	for (int i = 0; i < rows; i++) {   // (3)
		Array[i] = new double[cols];     // инициализация указателей
	}
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			Array[j][i] = 0;
		}
	}
}