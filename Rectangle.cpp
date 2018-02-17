#include "Rectangle.h"
#include<typeinfo>
#include "Rhombus.h"

//To get the Height of the Rectangle
int Rectangle::getHeight() const
{
	return height;
}

//To get the Width of the Rectangle
int Rectangle::getWidth() const
{
	return width;
}

//Constructor to set the Width, height and Dname of the Rectangle
Rectangle::Rectangle(int width, int height, string dname) : Shape ( "Rectangle" , dname)
{
	if (height >= 1 && width >= 1) {
		this->height = height;
		this->width = width;

	}
	else cout << "Width and Height should be greater than or equal to 1" << endl;
}

//To scale the Rectangle of the given value
int Rectangle::scale(int scale)
{
	if (height + scale >= 1 && width + scale >= 1) {
		height = height + scale;
		width = width + scale;
	}
	return 0;
}

//To calculate the GeoArea
double Rectangle::geoArea()
	{
		return height * width;
	}

//To calculate the ScreenArea
double Rectangle::screenArea()
{
	return height * width;
}

//To calculate the ScreenPerimeter
double Rectangle::screenPerimeter()
{
	return  (2 * (height + width)) - 4;
}

//To pass the Grid for the given dimensions
vector<vector<char>> Rectangle::boundingbox() const
{
	int height = this->getHeight() ;
	int width = this->getWidth();
	vector <vector<char>> grid;
	grid.resize(height);

	for (int i = 0; i < height; i++) {
		grid[i].resize(width);
	}
	return grid;
}

//To display the Shape information
string Rectangle::toString()
{
	const Shape *p = new Rectangle;
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
	info.append(to_string(this->getWidth()));
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

//to calculate the GeoPerimeter
double Rectangle::geoperimeter()
	{
		return 2 * (height + width);
	}

//To Draw in the grid
vector<vector<char>> Rectangle::draw(char penChar, char fillChar) const
{
	vector<vector<char>> grid;
	grid = this->boundingbox();
	for (int r = 0; r < height; r++) {
		for (int k = 0; k < width; k++) {
			grid[r][k] = penChar;
		}
	}

	return grid;
}

//operator overloading<<
ostream & operator<<(ostream & out, Rectangle &rect)
{
	out << rect.toString();
	return out;
}
