#pragma once
#include "matrix.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
	class Matrix;

	template <class T>
	ostream & operator<<(ostream & output, const Matrix<T> &);

	template <class T>
	istream & operator>>(istream & input, Matrix<T> &);


	Isclucheniya::Isclucheniya(char* _err): err(_err){}
	char* Isclucheniya:: what() {return err;}
	
	Razmery::Razmery(): Isclucheniya("ERROR: nevernye razmery!") {}
	
	FileNotOpen::FileNotOpen(): Isclucheniya("ERROR: file not open!") {}
	
	WrongIndex::WrongIndex(): Isclucheniya("ERROR: wrong index!") {}
	
	Samoprisvaivanie::Samoprisvaivanie(): Isclucheniya("ERROR: samoprisvaivanie!") {}
	
	template <class T>
	Matrix<T>::Matrix() : lines(0), columns(0), massiv(nullptr) {}
	template <class T>
	Matrix<T>::Matrix(int _lines, int _columns) : lines(_lines), columns(_columns){
		massiv = new T*[lines];
		for (int i = 0; i < lines; i++) { massiv[i] = new T[columns]; }
	}
	template <class T>
	Matrix<T>::Matrix(const Matrix &a) : lines(a.lines), columns(a.columns) {
		massiv = new T*[lines];
		for (int i = 0; i < lines; i++){
			massiv[i] = new T[columns];
			for (int j = 0; j < columns; j++)
				massiv[i][j] = a.massiv[i][j];
		}
	}
	
	template <class T>
	Matrix<T> Matrix<T>::operator *(const Matrix &M) const{
		if (columns != M.lines){
			throw Razmery();
	}
		Matrix<T> M_res(lines, M.columns);
		for (int i = 0; i < lines; i++)
		for (int j = 0; j < M.columns; j++)
		{
			M_res.massiv[i][j] = 0;
			for (int k = 0; k < M.columns; k++)
				M_res.massiv[i][j] += (massiv[i][k] * M.massiv[k][j]);
		}
		cout << "M1*M2:\n";  M_res.print();
		return M_res;
	}
	template <class T>
	T* Matrix<T>::operator [] (int k) const{
		if ((k < 0) || (k >= lines)){ throw WrongIndex(); }
		T *r = new T[columns];
		for (int j = 0; j < columns; j++){
			r[j] = massiv[k][j];
		}
		return r;
	}
		template <class T>
	Matrix<T>::~Matrix()
	{
		if (massiv != nullptr)
		{
			for (int i = 0; i < lines; i++)
			{
				delete[] massiv[i];
			}
			delete[] massiv;
		}
	}
	template <class T>
	void Matrix<T>::set_matrix(char* s) const{
		ifstream fin;
		fin.open(s);
		if (!fin.is_open()) {
			throw FileNotOpen();
		}
		for (int i = 0; i < lines; i++){
			for (int j = 0; j < columns; j++)
				fin >> massiv[i][j];
		}
	}
	template <class T>
	void Matrix<T>::print() const{
		for (int i = 0; i < lines; i++){
			for (int j = 0; j < columns; j++)
				cout << massiv[i][j] << " ";
			cout << "\n";
		}
	}
	template <class T>
	Matrix<T> Matrix<T>::operator +(const Matrix &M) const{
		if ((lines != M.lines) || (columns != M.columns)) {
			throw Razmery();
		}
		Matrix<T> M_res(M.lines, M.columns);
		for (int i = 0; i < M.lines; i++)
		for (int j = 0; j < M.columns; j++)
			M_res.massiv[i][j] = massiv[i][j] + M.massiv[i][j];
		cout << "M1+M2:\n";  M_res.print();
		return M_res;
	}
	template <class T>
	int Matrix<T>::get_number_lines() const{
		return lines;
	}
	template <class T>
	int Matrix<T>::get_number_columns() const{
		return columns;
	}
	template <class T>
	Matrix<T>& Matrix<T>::operator = (const Matrix &a) {
		if (this == &a){
		throw Samoprisvaivanie(); 	
		}
			if (massiv != nullptr){
				for (int i = 0; i < lines; i++){
					delete[] massiv[i];
				}
				delete[] massiv;
			}
			lines = a.lines;
			columns = a.columns;
			massiv = new T*[lines];
			for (int i = 0; i < lines; i++){
				massiv[i] = new T[columns];
				for (int j = 0; j < columns; j++) { massiv[i][j] = a.massiv[i][j]; }
			}
			return *this;
	}
	template <class T>
	bool Matrix<T>::operator ==(const Matrix &M) const{
		if (lines != M.lines || columns != M.columns)
			return false; 

		for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
		if (massiv[i][j] != M.massiv[i][j])
			return false;

		return true; 
	}
template <typename T>
	ostream & operator<<(ostream & output, const Matrix<T> & matrix)
	{
		for (int i = 0; i < matrix.lines; i++) {
			output << endl;
			for (unsigned int j = 0; j < matrix.columns; j++) {
				output << matrix.massiv[i][j] << " ";
			}
		}

		return output;
	}

	template <typename T>
	istream & operator>>(istream & input, Matrix<T> & matrix)
	{
		for (unsigned int i = 0; i < matrix.lines; i++) {
			for (unsigned int j = 0; j < matrix.columns; j++) {
				input >> matrix.massiv[i][j];
			}
		}
		return input;
	}
