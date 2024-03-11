#pragma once
#include <string>
#include <exception>

using namespace std;

class MyExc :public exception {

	string comm;

public:
	MyExc(string);
	string what() { return comm; }
};

