#pragma once
/*
����� �������� ����� ���������� �������
*/
class TArray {
private:
	size_t rows, cols;
public:
	/*
	��������� ������ ���������
	*/
	double** Array;
	/*
	����������� ������ ��� ��������� ��������� ���������� �������
	@param double** GArray - ������ �������
	@param size_t Grows - ���-�� ����� � ��������� �������(������)
	@param size_t Gcols - ���-�� �������� � ��������� �������(������)
	*/
	TArray(double**GArray, size_t Grows, size_t Gcols) :Array(GArray), rows(Grows), cols(Gcols) {}
	
	//TArray(size_t Grows, size_t Gcols);
	TArray& operator=(TArray& Source);
	/*
	-������� ���������� ��������� ������
	@param size_t Grows - ���-�� ����� � ��������� �������(������)
	@param size_t Gcols - ���-�� �������� � ��������� �������(������)
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
	�������� ���-�� ����� � �������(������)
	*/
	size_t GetRows() {
		return rows;
	}
	/*
	�������� ���-�� �������� � �������(������)
	*/
	size_t GetCols() {
		return cols;
	}
};

