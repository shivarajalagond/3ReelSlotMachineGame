#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include"Triangle.h"
#include<iostream>
using namespace std;

class RightTriangle : public Traingle {
private:
	int height;
	int base;
public:
	int getBase() const;
	int getHeight() const;
	RightTriangle() = default;
	RightTriangle(int, string dname = "Generic RightTraingle");
	virtual int scale(int) override ;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ')const override;
	virtual double geoArea() override ;
	virtual double geoperimeter() override ;
	virtual double screenArea() override;
	virtual double screenPerimeter() override;
	virtual vector<vector<char>> boundingbox() const override ;
	virtual string toString() override ;
	friend ostream & operator<<(ostream & out, Traingle &) ;
};



#endif // !RIGHTTRIANGLE_H

