#include "RightTriangle.h"
#include <vector>

//Constructor to set the base and dname
RightTriangle::RightTriangle(int basee, string dname ) :Traingle( "RightTriangle", dname)
{
	
	if (basee >= 1) {
		this->base = basee;
		this->height = basee;
	}
	else
		cout << "Base should be greater than 1" << endl;
}

//To get the base of the RightTriangle
int RightTriangle::getBase() const
{
	return base;
}

//to get the height of the RightTriange
int RightTriangle::getHeight() const
{
	return height;
}

//To scale the dimensions of rightTriangle for the given scale
int RightTriangle::scale(int scale)
{
	if ((this->getBase() + scale) >= 1) {
		this->base = this->getBase() + scale;
		this->height = this->getHeight() + scale;
	}
	return 0;
}

//To draw in the grid
vector<vector<char>> RightTriangle::draw(char penChar, char fillChar) const
{
	vector<vector<char>> grid;
	grid = this->boundingbox();
	//for penchar 
	for (int i = 0; i < grid.size(); i++) {
		for (int k = 0; k <= i; k++) {
			grid[i][k] = penChar;

		}
	}

	//for fillchar
	for (int i = 0; i < grid.size()-1; i++) {
		for (int k = 1; k < grid.size()-i; k++) {
			grid[i][k+i] = fillChar;
		}
	}

	return grid;
}

//to calculate the geoArea
double RightTriangle::geoArea()
{
	return ((height*base)/2);
}

//To calculate the GeoPerimeter
double RightTriangle::geoperimeter()
{
	return (2 + sqrt(2)) * height;
}
//To calculate the  screenArea
double RightTriangle::screenArea()
{
	return (height*(height+1))/2 ;
}
//To calculate the  Screen Pereimeter
double RightTriangle::screenPerimeter()
{
	return 3*(height-1);
}
//To pass the grid of the required dimension
vector<vector<char>> RightTriangle::boundingbox() const
{
	int height= this->getHeight();
	int base = this->getBase();
	vector <vector<char>> grid;
	grid.resize(height);

	for (int i = 0; i < height; i++) {
		grid[i].resize(base);
	}
	
	return grid;
}

//to Return the Shape information
string RightTriangle::toString()
{
	const Shape *p = new RightTriangle;
	string info;
	info = "Shape Information";
	info.append("\n");
	info.append("------------------");
	info.append("\n");
	info.append("Static type:		 ");
	info.append(typeid(p).name());
	info.append("\n");
	info.append("Dynamic type:		 ");
	info.append(typeid(*p).name());
	info.append("\n");
	info.append("Generic Name:		 ");
	info.append(this->getgenericName());
	info.append("\n");
	info.append("Description:		 ");
	info.append(this->getdescriptiveName());
	info.append("\n");
	info.append("id:                      ");
	info.append(to_string(this->getIdentityNumber()));
	info.append("\n");
	info.append("B.box Width:		 ");
	info.append(to_string(this->getBase()));
	info.append("\n");
	info.append("B.box Height:	    	 ");
	info.append(to_string(this->getHeight()));
	info.append("\n");
	info.append("Screen Area:		 ");
	info.append(to_string(this->screenArea()));
	info.append("\n");
	info.append("Geo Area:	         ");
	info.append(to_string(this->geoArea()));
	info.append("\n");
	info.append("Screen Perimeter:	 ");
	info.append(to_string(this->screenPerimeter()));
	info.append("\n");
	info.append("Geo Perimeter:		 ");
	info.append(to_string(this->geoperimeter()));
	info.append("\n");
	info.append("\n");

	return info;
}

//Operator Overloading<<
ostream & operator<<(ostream & out, Traingle & rightTriangle)
{
	out << rightTriangle.toString();
	return out;
}
