#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Shape {
private:
	int identityNumber;
	string genericName;
	string descriptiveName;
public:
	Shape()=default;
	Shape(string, string);
	int getIdentityNumber();
	string getgenericName();
	string getdescriptiveName();
	virtual double geoArea() = 0;
	virtual double geoperimeter() = 0;
	virtual int scale(int) = 0;
	virtual double screenArea() = 0;
	virtual double screenPerimeter() = 0;
	virtual vector<vector<char>> boundingbox()const = 0;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') const = 0;
	virtual string toString() = 0;
	friend ostream & operator<<(ostream & out, const vector<vector<char>> &);
	void write_image_to_stream(ostream & cout, char penChar = '*', char fillChar = ' ');
	void draw_on_screen(char penChar = '*', char fillChar = ' ');
};
#endif // !SHAPE_H
