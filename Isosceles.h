#ifndef ISOSCELES_H
#define ISOCELES_H
#include "Triangle.h"

class Isosceles : public Traingle {
	int base;
	int height;
public:
	int getHeight() const;
	int getBase() const;
	Isosceles() = default;
	Isosceles(int, string dname = "Generic Isosceles");
	virtual int scale(int) override;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') const override;
	virtual double geoArea() override;
	virtual double geoperimeter() override;
	virtual double screenArea() override;
	virtual double screenPerimeter() override;
	virtual vector<vector<char>> boundingbox() const override;
	virtual string toString() override;
	friend ostream & operator<<(ostream & out, Isosceles &);

};
#endif // !ISOSCELES_H

