#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

template <class T>
class Matrix;

class Isclucheniya {
	char* err;
public:
	Isclucheniya(char* _err) : err(_err) {}
	virtual char* what() { return err; }
};

class Razmery : public Isclucheniya{
	char* err;
public:
	Razmery() : Isclucheniya("ERROR: nevernye razmery!") {};
	char* what() { return err; };
};

class WrongIndex : public Isclucheniya{
	char* err;
public:
	WrongIndex() : Isclucheniya("ERROR: wrong index!") {};
	char* what() { return err; };
};

class FileNotOpen : public Isclucheniya{
	char* err;
public:
	FileNotOpen() : Isclucheniya("ERROR: file not open!") {};
	char* what() { return err; };
};

class Samoprisvaivanie: public Isclucheniya{
	char* err;
public:
	Samoprisvaivanie() : Isclucheniya("ERROR: samoprisvaivanie!") {};
	char* what() { return err; };
};

template <class T>
ostream & operator<<(ostream & output, const Matrix<T> &);

template <class T>
istream & operator>>(istream & input, Matrix<T> &);

template <class T>

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
	int get_lines() const;
	int get_columns() const;
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
