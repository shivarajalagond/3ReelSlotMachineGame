#include "Shape.h"
using namespace std;

//Constructor to set the Generic name and Descriptive name
Shape::Shape(string gname, string dname)
{
	static int id = 1;
	identityNumber = id;
	genericName = gname;
	descriptiveName = dname;
	id++;
}

//To return the ID of the shape
int Shape::getIdentityNumber()
{
	return identityNumber;
}
//To return thr Genereic name
string Shape::getgenericName()
{
	return genericName;
}

//To pass the Desciptive name
string Shape::getdescriptiveName()
{
	return descriptiveName;
}

//operator overloading<<
ostream & operator<<(ostream & out, const vector<vector<char>>& grid)
{
	for (size_t r = 0; r < grid.size(); ++r) {
	
		for (size_t k = 0; k < grid[r].size(); ++k) {

			out << grid[r][k];
		}
		
			out << endl;
		
	}
	return out;
}
//To write the image to screen, that calls draw
void Shape::write_image_to_stream(ostream & coutt, char penChar, char fillChar)
{
	coutt << this->draw(penChar, fillChar);
}

//To draw the image on screen, that calls draw
void Shape::draw_on_screen(char penChar, char fillChar)
{
	cout << this->draw(penChar, fillChar);

}
