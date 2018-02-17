#include "Isosceles.h"

//To get the height the of the isosceles
int Isosceles::getHeight() const
{
	return this->height;
}

//to get the base of the isosceles
int Isosceles::getBase() const
{
	return this->base;
}

//Constructor to set the base and Descriptive name
Isosceles::Isosceles(int base, string dname): Traingle("Isosceles", dname)
{
	if(base>=1){
		if (base % 2 == 0) {
			this->base = base + 1;
			this->height = (this->base + 1) / 2;
		}
		else {
			this->base = base ;
			this->height = (base + 1) / 2;
		}
	}
	else
		cout << "Base should be greater than 1" << endl;

}

//To set the height, base for the passed scale 
int Isosceles::scale(int scale)
{
	if ((base + 2 * scale) >= 1) {
		this->base = this->getBase() + 2 * scale;
		this->height = (this->base + 1) / 2;
	}
	return 0;
}

//To draw into the grid
vector<vector<char>> Isosceles::draw(char penChar, char fillChar) const
{
	vector<vector<char>> grid;
	grid = this->boundingbox();

	//for the no of rows in the first half
	for (int i = 0; i < grid.size(); i++) {
		//for fillchar in the left half of diagonal
		for (int k = 0; k < (((grid[i].size() + 1) / 2) - i - 1); k++) {
			grid[i][k] = fillChar;
		}

		int j = i;
		int r = i;
		int l = 1;
		//for penchar at the left half of diagonal
		while (r >= 1) {
			grid[i][((grid[i].size() + 1) / 2) - 1 - l] = penChar;
			r--;
			l++;
		}

		//penchar at the diagonal
		grid[i][((grid[i].size() + 1) / 2) - 1] = penChar;

		//penchar at the right half of the diagonal
		while (j >= 1) {
			grid[i][((grid[j].size() + 1) / 2) + j - 1] = penChar;
			j--;
		}

		//to fill the right half with the fillchar
		for (int m = (((grid[i].size() + 1) / 2) + i); m <= grid[i].size() - 1; m++) {

			grid[i][m] = fillChar;
		}

	}
	return grid;
}

//To calculate the geoArea 
double Isosceles::geoArea()
{
	return (height * base) / 2;
}

//To calculate the GeoPerimeter
double Isosceles::geoperimeter()
{
	return (base+2*sqrt((0.25*base*base)+(height*height)));
}

//To calculate the ScreenArea
double Isosceles::screenArea()
{
	return height*height;
}
//To calculate the ScreenPerimeter
double Isosceles::screenPerimeter()
{
	return 4*(height-1);
}

//To pass the grid for the given dimension
vector<vector<char>> Isosceles::boundingbox() const
{
	int height = this->getHeight();
	int base = this->getBase();
	vector <vector<char>> grid;
	grid.resize(height);

	for (int i = 0; i < height; i++) {
		grid[i].resize(base);
	}
	return grid;
}

//To Display the Shape information
string Isosceles::toString()
{
	const Shape *p = new Isosceles;
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

//Operator overloading<<
ostream & operator<<(ostream & out, Isosceles &iso)
{
	out << iso.toString();
	return out;
}
