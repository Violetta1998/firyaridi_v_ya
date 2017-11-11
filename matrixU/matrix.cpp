#include "matrix.h"
#include <stdexcept>
#include <iostream>
using namespace std;

MatrixU::MatrixU(const int nRow, const int nCol)
	: nRow_(nRow)
	, nCol_(nCol)
{
	if (nRow_ < 0 || nCol_ < 0) {
		throw invalid_argument("Argument cannot be negative");
	}
	pdata_ = new int[nRow * nCol]{0};//заполнение 0
}

/*MatrixU::~MatrixU()
{
	delete[] pdata_;
}*/

ptrdiff_t MatrixU::getRowCount()
{
	return nRow_;
}

ptrdiff_t MatrixU::getColCount()
{
	return nCol_;
}


int& MatrixU::at(ptrdiff_t iRow, ptrdiff_t iCol)
{
	if (iRow < 0 || iCol < 0) {
		throw invalid_argument("Argument cannot be negative");
	}
	if (iRow > nRow_ || iCol > nCol_) {
		throw invalid_argument("Size is more then a size of concrete Matrix");
	}
	return *(pdata_ + nCol_*iRow + iCol);
}

const int & MatrixU::at(ptrdiff_t iRow, ptrdiff_t iCol) const
{
	if (iRow < 0 || iCol < 0) {
		throw invalid_argument("Argument cannot be negative");
	}
	if (iRow > nRow_ || iCol > nCol_) {
		throw invalid_argument("Size is more then a size of concrete Matrix");
	}
	return *(pdata_ + nCol_*iRow + iCol);
}

void MatrixU::set(ptrdiff_t iRow, ptrdiff_t iCol, ptrdiff_t number)
{
	if (iRow < 0 || iCol < 0) {
		throw invalid_argument("Argument cannot be negative");
	}
	if (iRow > nRow_ || iCol > nCol_) {
		throw invalid_argument("Size is more then a size of concrete Matrix");
	}

	*(pdata_ + nCol_*iRow + iCol)=number;
}

void MatrixU::summMatrix(MatrixU matr1, MatrixU matr2)
{
	if (matr1.nCol_ != matr2.nCol_ || matr1.nRow_ != matr2.nRow_) {
		throw invalid_argument("Matrix with different size cannot be summed");
	}
	for (int i = 0; i < (matr1.nCol_*matr1.nRow_); i++) {
		*(matr1.pdata_ + i) = *(i + matr2.pdata_)+*(i+matr1.pdata_);
	}
}

void MatrixU::minusMatrix(MatrixU matr1, MatrixU matr2) {
	if (matr1.nCol_ != matr2.nCol_ || matr1.nRow_ != matr2.nRow_) {
		throw invalid_argument("Matrix with different size cannot be minused");
	}
	for (int i = 0; i < (matr1.nCol_*matr1.nRow_); i++) {
		*(matr1.pdata_ + i) = *(matr1.pdata_ + i) - *(matr2.pdata_ + i);
	}
}

void MatrixU::multiplyOnNumber(MatrixU matr1, ptrdiff_t number)
{
	if (matr1.nCol_<0||matr1.nRow_<0) {
		throw invalid_argument("Matrix's size cannot be negative");
	}
	for (int i = 0; i < (matr1.nCol_*matr1.nRow_); i++) {
		*(matr1.pdata_ + i) = number* *(matr1.pdata_ + i);
	}
}

void MatrixU::consoleMatrix(MatrixU matr) {
	cout << "matix";
	for (int i = 0; i < (matr.nCol_*matr.nRow_); i++) {
		cout << *(matr.pdata_ + i) << " ";
	}
	cout << endl;
}

