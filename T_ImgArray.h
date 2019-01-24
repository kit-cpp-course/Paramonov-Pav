#pragma once
/*
Класс является видом двумерного массива
*/
class TArray {
private:
	size_t rows, cols;
public:
	/*
	Двумерный массив Элементов
	*/
	double** Array;
	/*
	Конструктор класса при известных значениях двумерного массива
	@param double** GArray - данные массива
	@param size_t Grows - кол-во рядов в двумерном массиве(высота)
	@param size_t Gcols - кол-во столбцов в двумерном массиве(ширина)
	*/
	TArray(double**GArray, size_t Grows, size_t Gcols) :Array(GArray), rows(Grows), cols(Gcols) {}
	
	//TArray(size_t Grows, size_t Gcols);
	TArray& operator=(TArray& Source);
	/*
	-Создает обнуленный двумерный массив
	@param size_t Grows - кол-во рядов в двумерном массиве(высота)
	@param size_t Gcols - кол-во столбцов в двумерном массиве(ширина)
	*/
	TArray();
	void Init(size_t Grows, size_t Gcols);
	~TArray() {
		for (int i = 0; i < rows; i++) {
			delete[]  Array[i];
		}
		delete[]  Array;
	}
	/*
	Получить кол-во рядов в массиве(высоту)
	*/
	size_t GetRows() {
		return rows;
	}
	/*
	Получить кол-во столбцов в массиве(ширину)
	*/
	size_t GetCols() {
		return cols;
	}
};

