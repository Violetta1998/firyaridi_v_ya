#ifndef MATRIX_U
#define MATRIX_U
#include <cstddef>

class MatrixU {
public:
	explicit MatrixU()=default;
	MatrixU(const int nRow, const int nCol);
	//~MatrixU();
	ptrdiff_t getRowCount();
	ptrdiff_t getColCount();

	int& at(ptrdiff_t iRow, ptrdiff_t iCol);
	const int& at(ptrdiff_t iRow, ptrdiff_t iCol) const;

	void set(ptrdiff_t iRow, ptrdiff_t iCol, ptrdiff_t number);
	void summMatrix(MatrixU matr1, MatrixU matr2);
	void minusMatrix(MatrixU matr1, MatrixU matr2);
	void multiplyOnNumber(MatrixU matr1, ptrdiff_t number);
	void consoleMatrix(MatrixU matr);
private:
	ptrdiff_t nRow_{ 0 };
	ptrdiff_t nCol_{ 0 };
	int* pdata_{ nullptr };
};

#endif