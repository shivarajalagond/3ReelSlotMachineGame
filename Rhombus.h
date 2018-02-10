#ifndef ROHMBUS_H
#define ROHMBUS_H
#include "Shape.h"
#include<iostream>
#include<string>
using namespace std;

class Rohmbus : public Shape {
private:
	int diagonal;
public:
	Rohmbus() = default;
	int getDiagonal() const;
	Rohmbus(int,string dname = "Generic Rohmbus");
	virtual int scale(int) override;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') const override;
	virtual double geoArea() override;
	virtual double geoperimeter() override;
	virtual double screenArea() override;
	virtual double screenPerimeter() override;
	virtual vector<vector<char>> boundingbox()const override;
	virtual string toString() override;
	friend ostream & operator<<(ostream & out, Rohmbus &);	
};
#endif // !ROHMBUS_H

