#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "Isosceles.h"
#include "SlotMachine.h"
#include <iostream>
#include <string>
#include<ctime>
using namespace std;

int main() {

	//Rectangle rect(10,10);
	//cout << rect.toString();
//	rect.draw();
//	cout << rect.draw() ;
//	cout << rect.draw('.', '!');
//	rect.draw_on_screen(' ', '1');
//    rect.scale(-1);
//	rect.write_image_to_stream(cout, '1');
//	rect.scale(10);
//	rect.write_image_to_stream(cout, 'A', '.');
//   Rectangle r1(9,10);
//    r1.scale(-4);
//    r1.draw_on_screen();	
//	Isosceles iso(10);
//	iso.scale(-4);
//	iso.write_image_to_stream(cout,'1');

	SlotMachine slot_machine;
    slot_machine.run();

    return 0;
} 