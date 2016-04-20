#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

template <class T>
	class Matrix;

	template <class T>
	ostream & operator<<(ostream & output, const Matrix<T> &);

	template <class T>
	istream & operator>>(istream & input, Matrix<T> &); 
	
class Isclucheniya {
public:
	Isclucheniya(char* _err);
	char* what();
private:
	char* err;
};

class Razmery : public Isclucheniya{
	char* err;
public:
	Razmery();
	char* what();
};

class WrongIndex : public Isclucheniya{
	char* err;
public:
	WrongIndex();
	char* what();
};

class FileNotOpen : public Isclucheniya{
	char* err;
public:
	FileNotOpen();
	char* what();
};

class Samoprisvaivanie: public Isclucheniya{
	char* err;
public:
	Samoprisvaivanie();
	char* what();
};


template <class T>
class Matrix{
	
public:
	Matrix();
	Matrix(int _lines, int _columns);
	Matrix(const Matrix &a);
	~Matrix();
	void set_matrix(char* s) const;
	void print() const;
	Matrix operator +(const Matrix &array) const;
	Matrix operator *(const Matrix &array) const;
	T* operator [] (int k) const;
	int get_number_lines() const;
	int get_number_columns() const;
	Matrix& operator = (const Matrix &a);
	bool operator ==(const Matrix &array) const;
	friend ostream & operator<< <>(ostream & output, const Matrix<T> & matrix);
	friend istream & operator>> <>(istream & input, Matrix<T> & matrix);	

private:
	int lines;
	int columns;
	T **massiv;
};
#include "matrix.cpp"
#endif
