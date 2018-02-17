#include "SlotMachine.h"
#include "SlotMachine.h"
#include <ctime>
#include <time.h>
#include "Shape.h"
#include "Isosceles.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include <iomanip>
using namespace std;

//make shapes reels that point at newly created dynamic shape object
void SlotMachine::make_shapes()
{
	srand(time(NULL));
	Random1 = rand() % 3 + 1;
	make_shape(Random1);
}

//make shapes_reel[r] that point at newly created dynamic shape object
void SlotMachine::make_shape(int r)
{
	string dname;
	srand(time(NULL));
	int lengthrohmbus = 0;
	int lenghtrect = 0;
	int lenghtiso = 0;
	int lengthright = 0;
	int width;
	int xRan1;
	int xRan2;
	Random2 = rand() % 25 + 1;
	if (Random1 == 0) {
		Rohmbus *rohmbus = new Rohmbus(Random2);
		dname = rohmbus->getgenericName();
		output.append("(");
		output.append(dname);
		lengthrohmbus = rohmbus->getDiagonal();
		output.append(",");
		output.append(to_string(lengthrohmbus));
		output.append(",");
		output.append(to_string(lengthrohmbus));
		output.append(")");
		output.append("  ");
		shape_reel[count] = rohmbus;
		count++;
	}

	else if (Random1 == 1) {
		Isosceles *iso = new Isosceles(Random2);
		dname = iso->getgenericName();
		lenghtiso = iso->getBase();
		int height = iso->getHeight();
		shape_reel[count] = iso;
		count++;
		output.append("(");
		output.append(dname);
		output.append(",");
		output.append(to_string(lenghtiso));
		output.append(",");
		output.append(to_string(height));
		output.append(")");
		output.append("  ");

	}

	else if (Random1 == 2) {

		RightTriangle *rt = new RightTriangle(Random2);
		dname = rt->getgenericName();
		lengthright = rt->getBase();
		shape_reel[count] = rt;
		count++;
		output.append("(");
		output.append(dname);
		output.append(",");
		output.append(to_string(lengthright));
		output.append(",");
		output.append(to_string(lengthright));
		output.append(")");
		output.append("  ");
	}

	else
	{
		Random3 = rand() % 25 + 1;
		Rectangle *rect = new Rectangle(Random2, Random3);
		shape_reel[count] = rect;
		count++;
		string gname = rect->getgenericName();
		lenghtrect = rect->getWidth();
		int height = rect->getHeight();
		output.append("(");
		output.append(rect->getgenericName());
		output.append(",");
		output.append(to_string(rect->getWidth()));
		output.append(",");
		output.append(to_string(rect->getHeight()));
		output.append(")");
		output.append("  ");

	}
}

//function that displays outcome, payout and token left for the bet
void SlotMachine::report_status()
{
	if (shape_reel[0]->getgenericName().compare(shape_reel[1]->getgenericName()) == 0 &&
		shape_reel[0]->getgenericName().compare(shape_reel[2]->getgenericName()) == 0
		&& shape_reel[2]->getgenericName().compare(shape_reel[1]->getgenericName()) == 0) {

		if (shape_reel[0]->geoperimeter() == shape_reel[1]->geoperimeter() == shape_reel[1]->geoperimeter()) {

			token = token + (bet * 3);

			cout << "\"" << "Congragulations!! you win your bet!! " << endl;
			cout << "\"" << "you have now " << token << " tokens" << endl;
		}
		else {
			token = token + (bet * 2);
			cout << "\"" << "Congragulations!! you win your bet!! " << token << " tokens!" << endl;
			cout << "\"" << "you have now " << token << " tokens" << endl;
		}
	}
	else if (shape_reel[0]->getgenericName().compare(shape_reel[1]->getgenericName()) == 0 ||
		shape_reel[0]->getgenericName().compare(shape_reel[2]->getgenericName()) == 0
		|| shape_reel[2]->getgenericName().compare(shape_reel[1]->getgenericName()) == 0) {

		cout << "\"" << "you neither win nor loose your bet!! " << endl;
		cout << "\"" << "you have now " << token << " tokens" << endl;
	}
	else {
		token = token - bet;
		cout << "\"" << "Your loose your bet " << endl;
		cout << "\"" << "you have now " << token << " tokens" << endl;
	}
}

//implements the random generation algorithm
void SlotMachine::run()
{
	string dname;
	int lengthrohmbus=0;
	int lenghtrect=0;
	int lenghtiso=0;
	int lengthright=0;
	int width;
	int xRan1;
	int xRan2;
	string output;
	int count = 0;
	srand(time(NULL));
	
	cout << "Welcome to this 3-Reel Slot Machine Game!!" << endl;
	cout << "Each reel will randomly display one of the four shapes, each in 25 shapes " << endl;
	cout << "To win 3 times of your bet you need 3 similar shapes of the same size" << endl;
	cout << "To win 2 times of your bet you need 3 similar shapes " << endl;
	cout << "To win or loose nothing you need 2 similar shapes " << endl;
	cout << "Otherwise, you will ,loose your bet." << endl;
	cout << "you start with free 10 tokens!" << endl;
	cout << endl;

	while (token > 0)
	{
		cout << "How much would you like to bet (Enter 0 to quit)" << endl;
		cin >> bet;
		if (bet > token) {
			cout << "You dont have sufficient tokens to bet, bet less than or equal to current tokens" << endl;
			continue;
		}
		if (bet == 0) {
			
			cout << "\"" << "Game Over. You have " << token << " tokens!" << endl;
				break;
		}
		while (count < 3) {

			Random1 = rand() % 3+1;
			Random2 = rand() % 25 + 1;
			
			if (Random1 == 0) {
				Rohmbus *rohmbus = new Rohmbus(Random2); 
					dname = rohmbus->getgenericName();
					output.append("(");
					output.append(dname);
					lengthrohmbus = rohmbus->getDiagonal();
					output.append(",");
					output.append(to_string(lengthrohmbus));
					output.append(",");
					output.append(to_string(lengthrohmbus));
					output.append(")");
					output.append("  ");
					shape_reel[count] = rohmbus;
					count++;
				}
	
			else if (Random1 == 1) {
					Isosceles *iso =new Isosceles(Random2);
					dname = iso->getgenericName();
					lenghtiso = iso->getBase();
					int height = iso->getHeight();
					shape_reel[count] = iso;
					count++;
					output.append("(");
					output.append(dname);
					output.append(",");
					output.append(to_string(lenghtiso));
					output.append(",");
					output.append(to_string(height));
					output.append(")");
					output.append("  ");
					
				}
		
			else if (Random1 == 2) {

				RightTriangle *rt =new RightTriangle(Random2);
				dname = rt->getgenericName();
				lengthright = rt->getBase();
				shape_reel[count] = rt;
				count++;
				output.append("(");
				output.append(dname);
				output.append(",");
				output.append(to_string(lengthright));
				output.append(",");
				output.append(to_string(lengthright));
				output.append(")");
				output.append("  ");
			}
			
			else
			{
				Random3 = rand() % 25 + 1;
				Rectangle *rect =new Rectangle(Random2, Random3);
				shape_reel[count] = rect;
				count++;
				string gname = rect->getgenericName();
				lenghtrect = rect->getWidth();
				int height = rect->getHeight();
				output.append("(");
				output.append(rect->getgenericName());
				output.append(",");
				output.append(to_string(rect->getWidth()));
				output.append(",");
				output.append(to_string(rect->getHeight()));
				output.append(")");
				output.append("  ");
				
			}		

		}

		display_shapes();
		cout << output << endl;
		report_status();
		
		count = 0;
		output.clear();
	}
}

//Desctructor that frees dynamic objects currently pointed at by the shape reels
SlotMachine::~SlotMachine()
{
	release_shapes();
}

//to display the shape_reels on the sreen
void SlotMachine::display_shapes()
{
		vector<vector<char>> grid;
		vector<vector<char>> grid1;
		vector<vector<char>> grid2;
		vector<vector<char>> grid3;
		
		grid1 = shape_reel[0]->draw();
		grid2 = shape_reel[1]->draw();
		grid3 = shape_reel[2]->draw();
		
		if (grid1.size() > grid2.size()) {

			if (grid1.size() > grid3.size()) {
				grid.resize(grid1.size()+4);
				int len = grid2.size();
				
				grid2.resize(grid1.size());
				int width = grid2[0].size();
				for (int i = 0; i < grid1.size(); i++) {
					grid2[i].resize(width);
				}
				len = grid3.size();
				grid3.resize(grid1.size());
				width = grid3[0].size();
				for (int i = 0; i < grid1.size(); i++) {
					grid3[i].resize(width);
				}
			}
			else {
				grid.resize(grid3.size()+4);
				int len = grid2.size();
				grid2.resize(grid3.size());
				int width = grid2[0].size();
				for (int i = 0; i < grid2.size(); i++) {
					grid2[i].resize(width);
				}
				len = grid1.size();
				grid1.resize(grid3.size());
				width = grid1[0].size();
				for (int i = 0; i < grid1.size(); i++) {
					grid1[i].resize(width);
				}
			}
		}
		else
		{
			if (grid2.size() > grid3.size()) {
				grid.resize(grid2.size()+4);
				
				int len = grid1.size();
				grid1.resize(grid2.size());
				int width = grid1[0].size();
				for (int i = len; i < grid1.size(); i++) {
					grid1[i].resize(width);
				}
				len = grid3.size();
				grid3.resize(grid2.size());
				width = grid3[0].size();
				for (int i = len; i < grid3.size(); i++) {
					grid3[i].resize(width);
				}
				
			}
			else {
				grid.resize(grid3.size()+4);
				int len = grid2.size();
				grid2.resize(grid3.size());
				int width =grid2[0].size();
				for (int i = len; i < grid2.size(); i++) {
					grid2[i].resize(width);
				}
				len = grid1.size();
				grid1.resize(grid3.size());
				width = grid1[0].size();
				for (int i = len; i < grid1.size(); i++) {
					grid1[i].resize(width);
				}
				
			}
		}

		for (int i = 0; i <grid.size(); i++) {
			grid[i].resize(grid1[0].size()+grid2[0].size()+grid3[0].size()+10);
		}

	

		//to fill the border 
		for (int i = 0; i < grid[0].size(); i++) {
			grid[0][i] = '-';
			grid[grid.size()-1][i] = '-';
		}
		//to fill the border 
		for (int i = 0; i < grid.size(); i++) {
			grid[i][0] = '|';
			grid[i][grid[0].size() - 1] = '|';
			grid[i][grid1[0].size() + 3] = '|';
			grid[i][grid1[0].size() + grid2[0].size() + 6] = '|';
		}


		//for the no of rows in the first half
		for (int i = 0; i < grid.size()-4; i++) {
			
			for (int k = 0; k < grid1[0].size() + grid2[0].size() + grid3[0].size(); k++) {
				
				if (k < grid1[i].size()) {
					grid[i + 2][k + 2] = grid1[i][k];
				}
				

				else if (k >= grid1[0].size() && k < grid1[0].size() + grid2[0].size()) {
					grid[i + 2][k + 5] = grid2[i][k - grid1[i].size()];
				}
				else
				{
					grid[i + 2][k + 8] = grid3[i][k - (grid1[i].size() + grid2[i].size())];
				}
			}

			grid[0][0] = '+';
			grid[grid.size() - 1][0] = '+';
			grid[0][grid[0].size() - 1] = '+';
			grid[grid.size() - 1][grid[0].size() - 1] = '+';

			grid[0][grid1[0].size() + 3] = '+';
			grid[grid.size() - 1][grid1[0].size() + 3] = '+';
		
			grid[0][grid1[0].size() + grid2[0].size() + 6] = '+';
			grid[grid.size() - 1][grid1[0].size() + grid2[0].size() + 6] = '+';
		}
		cout << grid;
}

//frees dynamic objects currently pointed at by the shape reels 
void SlotMachine::release_shapes()
{
	for (int i = 0; i <= 2; i++) {
		delete shape_reel[i];
		shape_reel[i] = nullptr;
	}
}
