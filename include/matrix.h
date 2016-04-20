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
public:
	Razmery();
};

class WrongIndex : public Isclucheniya{
public:
	WrongIndex();
};

class FileNotOpen : public Isclucheniya{
public:
	FileNotOpen();
};

class Samoprisvaivanie: public Isclucheniya{
public:
	Samoprisvaivanie();
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
	Matrix operator +(const Matrix &M) const;
	Matrix operator *(const Matrix &M) const;
	T* operator [] (int k) const;
	int get_number_lines() const;
	int get_number_columns() const;
	Matrix& operator = (const Matrix &a);
	bool operator ==(const Matrix &M) const;
	friend ostream & operator<< <>(ostream & output, const Matrix<T> & matrix);
	friend istream & operator>> <>(istream & input, Matrix<T> & matrix);	

private:
	int lines;
	int columns;
	T **massiv;
};
#include "matrix.cpp"
#endif
