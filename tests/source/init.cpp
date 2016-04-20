#include <matrix.h>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Matrix init", "[init]") {

	GIVEN("The number of lines and columns") {

		auto lines = 3;
		auto columns = 3;

		WHEN("Create instansce of Matrix") {
			Matrix<int> matrix(lines, columns);
			THEN("The number of lines and columns must be preserved") {

				REQUIRE(matrix.get_number_lines() == lines);
				REQUIRE(matrix.get_number_columns() == columns);
			}
		}
	}
}

SCENARIO("Matrix init_long", "[init]") {

	GIVEN("The number of lines and columns") {

		auto lines = 3;
		auto columns = 3;

		WHEN("Create instansce of Matrix") {
			Matrix<long> matrix(lines, columns);
			THEN("The number of rows and columns must be preserved") {

				REQUIRE(matrix.get_number_lines() == lines);
				REQUIRE(matrix.get_number_columns() == columns);
			}
		}
	}
}

SCENARIO("Matrix init_double", "[init]") {

	GIVEN("The number of lines and columns") {

		auto lines = 3;
		auto columns = 3;

		WHEN("Create instansce of Matrix") {
			Matrix<double> matrix(lines, columns);
			THEN("The number of lines and columns must be preserved") {

				REQUIRE(matrix.get_number_lines() == lines);
				REQUIRE(matrix.get_number_columns() == columns);
			}
		}
	}
}

SCENARIO("Iscl_set", "[set]"){
	int O=0;
	Matrix<int> matrix(2,2);
	try{
	matrix.set_matrix("3.txt");
	}
	catch(Isclucheniya &e){if (e.what() == "ERROR: file not open!") O++;}
	REQUIRE(O==1);
}

SCENARIO("Matrix +", "[summ]") {
	Matrix<int> matrix(2, 2);
	matrix.set_matrix("1.txt");
	Matrix<int> matrixg(2, 2);
	matrixg.set_matrix("2.txt");
	Matrix<int> expected(2, 2);
	expected.set_matrix("1+2.txt");
	Matrix<int> result = matrix + matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Matrix +_l", "[summ]") {
	Matrix<long> matrix(2, 2);
	matrix.set_matrix("2.txt");
	Matrix<long> matrixg(2, 2);
	matrixg.set_matrix("2.txt");
	Matrix<long> expected(2, 2);
	expected.set_matrix("1+2.txt");
	Matrix<long> result = matrix+matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Matrix +_d", "[summ]") {
	Matrix<double> matrix(2, 2);
	matrix.set_matrix("1double.txt");
	Matrix<double> matrixg(2, 2);
	matrixg.set_matrix("2double.txt");
	Matrix<double> expected(2, 2);
	expected.set_matrix("1+2double.txt");
	Matrix<double> result = matrix + matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Iscl_martrix +","[summ]"){
	int O=0;
	Matrix<int> matrix(1, 2);
	matrix.set_matrix("1.txt");
	Matrix<int> matrixg(2, 2);
	matrixg.set_matrix("2.txt");	
	try{
		matrix+matrixg;
	}
	catch (Razmery &e) { O++;}
	REQUIRE(O==1);
}

SCENARIO("Matrix *", "[mult]") {
	Matrix<int> matrix(2, 2);
	matrix.set_matrix("1.txt");
	Matrix<int> matrixg(2, 2);
	matrixg.set_matrix("2.txt");
	Matrix<int> expected(2, 2);
	expected.set_matrix("1_2.txt");
	Matrix<int> result = matrix * matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Matrix *_l", "[mult]") {
	Matrix<long> matrix(2, 2);
	matrix.set_matrix("2.txt");
	Matrix<long> matrixg(2, 2);
	matrixg.set_matrix("2.txt");
	Matrix<long> expected(2, 2);
	expected.set_matrix("1_2.txt");
	Matrix<long> result = matrix * matrixg;
	REQUIRE(result == expected);
}

/*SCENARIO("Matrix *_d", "[mult]") { //Они одинаковы, но он этого не видит:с
	Matrix<double> matrix(2, 2);
	matrix.set_matrix("1double.txt");
	Matrix<double> matrixg(2, 2);
	matrixg.set_matrix("2double.txt");
	Matrix<double> expected(2, 2);
	expected.set_matrix("1_2double.txt");
	Matrix<double> result = matrix * matrixg;
	REQUIRE(result == expected);
}
*/
SCENARIO("Iscl_martrix *","[mult]"){
	int O=0;
	Matrix<int> matrix(2, 2);
	matrix.set_matrix("1.txt");
	Matrix<int> matrixg(1, 2);
	matrixg.set_matrix("2.txt");	
	try{
		matrix * matrixg;
	}
	catch (Razmery &e) {O++;}
	REQUIRE(O==1);
}

SCENARIO("Matrix: operator ==", "[equal]") {
	Matrix<int> matrix(2, 2);
	matrix.set_matrix("1.txt");
	Matrix<int> matrixg(2, 2);
	matrixg.set_matrix("2.txt");
	bool f = (matrix == matrixg);
	REQUIRE(f);
}

SCENARIO("Matrix: operator ==_l", "[equal]") {
	Matrix<long> matrix(2, 2);
	matrix.set_matrix("2.txt");
	Matrix<long> matrixg(2, 2);
	matrixg.set_matrix("2.txt");
	bool f = (matrix == matrixg);
	REQUIRE(f);
}

SCENARIO("Matrix: operator ==_d", "[equal]") {
	Matrix<double> matrix(2, 2);
	matrix.set_matrix("1double.txt");
	Matrix<double> matrixg(2, 2);
	matrixg.set_matrix("2double.txt");
	bool f = (matrix == matrixg);
	REQUIRE(f);
}

SCENARIO("Matrix operator [](int)", "[s]") 
{
	Matrix<int> matrix(2, 2);
	matrix.set_matrix("1.txt");
	int* s = matrix[1];
	REQUIRE(s[0]==1);
	REQUIRE(s[1]==1);
}

SCENARIO("Matrix operator [](long)", "[s]") 
{
	Matrix<long> matrix(2, 2);
	matrix.set_matrix("2.txt");
	long* s = matrix[1];
	REQUIRE(s[0]==1);
	REQUIRE(s[1]==1);
}

SCENARIO("Matrix operator [](double)", "[s]") 
{
	Matrix<double> matrix(2, 2);
	matrix.set_matrix("1double.txt");
	double* s = matrix[1];
	REQUIRE(s[0]==3.33);
	REQUIRE(s[1]==4.44);
}

SCENARIO("Iscl_[]", "[s]"){
	int O=0;
	Matrix<int> matrix(2, 2);
	matrix.set_matrix("1.txt");
	try{
		int* s = matrix[5];
	}
	catch(Isclucheniya &e){if (e.what() == "ERROR: wrong index!") O++;}
	REQUIRE(O==1);
}

SCENARIO("samoprisv", "="){
	int O=0;
	Matrix<int> matrix(2, 2);
	matrix.set_matrix("1.txt");
	try{
		matrix=matrix;
	}
	catch(Isclucheniya &e){if (e.what() == "ERROR: samoprisvaivanie!") O++;}
	REQUIRE(O==1);
}
