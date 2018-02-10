#ifndef TRAINGLE_H
#define TRAINGLE_H
#include "Shape.h"
#include <iostream>
using namespace std;

class Traingle :public Shape {
	string genericName;
public:
	Traingle() = default;
	Traingle(string gname, string dname);
	virtual int scale(int) override=0;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') const override=0;
	virtual double geoArea() override =0;
	virtual double geoperimeter() override =0;
	virtual double screenArea() override =0;
	virtual double screenPerimeter() override=0;
	virtual vector<vector<char>> boundingbox() const override = 0;
	virtual string toString() override = 0;
};

#endif // !TRAINGLE_H

