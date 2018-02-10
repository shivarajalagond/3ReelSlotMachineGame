#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include<iostream>
using namespace std;

class Rectangle : public Shape {
private:
	int height;
	int width;
public:
	Rectangle()=default;
	int getHeight()const;
	int getWidth()const;
	Rectangle(int, int, string dname = "Generic Rectangle");
	virtual int scale(int) override;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = '.')const override;
	friend ostream & operator<<(ostream & out,  Rectangle &);
	virtual double geoArea() override;
	virtual double geoperimeter() override;
	virtual double screenArea() override;
	virtual double screenPerimeter() override;
	virtual vector<vector<char>> boundingbox() const override;
	virtual string toString() override;
	
};

#endif // !RECTANGLE_H
