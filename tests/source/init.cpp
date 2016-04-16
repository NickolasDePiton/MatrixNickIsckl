#include <matrix.h>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Matrix init", "[init]") {

	GIVEN("The number of rows and columns") {

		auto rows = 5;
		auto columns = 5;

		WHEN("Create instansce of Matrix") {
			Matrix matrix(rows, columns);
			THEN("The number of rows and columns must be preserved") {

				REQUIRE(matrix.getnumstr() == rows);
				REQUIRE(matrix.getnumcol() == columns);
			}
		}
	}
}

SCENARIO("Iscl_set", "[set]"){
	int O=0;
	Matrix matrix(5,5);
	try{
	matrix.set_matrix("3.txt");
	}
	catch(...){O++;}
	REQUIRE(O==1);
}

SCENARIO("Matrix +", "[summ]") {
	Matrix matrix(5, 5);
	matrix.set_matrix("1.txt");
	Matrix matrixg(5, 5);
	matrixg.set_matrix("2.txt");
	Matrix expected(5, 5);
	expected.set_matrix("1+2.txt");
	Matrix result = matrix + matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Iscl_martrix +","[summ]"){
	int O=0;
	Matrix matrix(4, 5);
	matrix.set_matrix("1.txt");
	Matrix matrixg(5, 5);
	matrixg.set_matrix("2.txt");	
	try{
		matrix+matrixg;
	}
	catch (...) {O++;}
	REQUIRE(O==1);
}

SCENARIO("Matrix *", "[mult]") {
	Matrix matrix(5, 5);
	matrix.set_matrix("1.txt");
	Matrix matrixg(5, 5);
	matrixg.set_matrix("2.txt");
	Matrix expected(2, 2);
	expected.set_matrix("1_2.txt");
	Matrix result = matrix * matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Iscl_martrix *","[mult]"){
	int O=0;
	Matrix matrix(5, 5);
	matrix.set_matrix("1.txt");
	Matrix matrixg(4, 5);
	matrixg.set_matrix("2.txt");	
	try{
		matrix*matrixg;
	}
	catch (...) {O++;}
	REQUIRE(O==1);
}

SCENARIO("Matrix: operator ==", "[equal]") {
	Matrix matrix, matrixg;
	matrix.set_matrix("1.txt");
	matrixg.set_matrix("1.txt");
	bool f = (matrix == matrixg);
	REQUIRE(f);
}

SCENARIO("Matrix operator [](int)", "[s]") 
{
	Matrix matrix(5,5);
	matrix.set_matrix("1.txt");
	int* s = matrix[1];
	REQUIRE(s[0]==6);

}

SCENARIO("Iscl_[]", "[s]"){
	int O=0;
	Matrix matrix(5,5);
	matrix.set_matrix("1.txt");
	try{
		int* s = matrix[5];
	}
	catch(...){O++;}
	REQUIRE(O==1);
}

SCENARIO("samoprisv", "="){
	int O=0;
	Matrix matrix(5,5);
	matrix.set_matrix("1.txt");
	try{
		matrix=matrix;
	}
	catch(...){O++;}
	REQUIRE(O==1);
}
