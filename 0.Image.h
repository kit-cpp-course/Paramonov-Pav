#pragma once
#include <atlimage.h>
#include <iostream>
using namespace std;

class Image {
private:
	CImage image;
public:
	short rows;
	short columns;

	Image(short GRows, short GColumns) {
		rows = GRows;
		columns = GColumns;
	}
};

