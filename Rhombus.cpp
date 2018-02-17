#include "Rhombus.h"

//To get the diagonal
int Rohmbus::getDiagonal() const
{
	return diagonal;
}

//Constructor to set the Diagonal, dname of the Rohmbus
Rohmbus:: Rohmbus(int dia, string dname) : Shape("Rohmbus", dname) {
	if (dia >= 1) {
		if (dia % 2 == 0) {
			this->diagonal = dia+1;
		}
		else {
			dia = dia ;
			this->diagonal = dia;
		}
	}
	else {
		cout << "Diagonal has be greater than or equal to 1" << endl;
	}

}

//To scale the Rohmbus for the given scale
int Rohmbus::scale(int scale)
{
	if ((diagonal + 2 * scale) >= 1) {
		diagonal = diagonal + 2 * scale;
	}
	return 0;
}

//To draw in the grid 
vector<vector<char>> Rohmbus::draw(char penChar, char fillChar) const{

	vector<vector<char>> grid;
	grid = this->boundingbox();
	
	//for the no of rows in the first half
	for (int i = 0; i < ((grid.size() + 1) / 2); i++) {
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
	int half = (grid.size() + 1) / 2;
	int b = half;
	b = b - 2;
	while (half < grid.size()) {
		grid[half]= grid[b];
		half++;
		b--;
	}
	
	return grid;
}

//To calculate the GeoArea
double Rohmbus::geoArea()
{
	return ((diagonal*diagonal) / 2);
}

//To calculate the GeoPerimeter
double Rohmbus::geoperimeter()
{
	return ((2 * sqrt(2))*diagonal);
}

//To calculate the ScreenArea
double Rohmbus::screenArea()
{
	double n = (diagonal / 2);
	double area = ((2 * n)*(n + 1) + 1);
	return area;
}

//To calculate the SreenPerimeter
double Rohmbus::screenPerimeter()
{
	return floor((2*(this->getDiagonal()-1)*100)/100);
}

//To pass the grid of the required dimensions
vector<vector<char>> Rohmbus::boundingbox() const
{
	int dia = this->getDiagonal();
	//cout << "diagonal is" << dia << endl;
	vector <vector<char>> grid;
	grid.resize(dia);

	for (int i = 0; i < dia; i++) {
		grid[i].resize(dia);
	}
	return grid;
}

//to get the shape information
string Rohmbus::toString()
{
 const Shape *p = new Rohmbus;
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
	info.append(to_string(this->getDiagonal()));
	info.append("\n");
	info.append("B.box Height:	    	 ");
	info.append(to_string(this->getDiagonal()));
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

//operator overloading<<
ostream & operator<<(ostream & out, Rohmbus & rohmbus)
{
	out << rohmbus.toString();
	return out;
}