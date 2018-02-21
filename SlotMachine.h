#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include "Shape.h"
#include<array>

class SlotMachine {
private:
	std::array<Shape* , 3> shape_reel{};
	void display_shapes();
	int token =10;
	int bet =0;
	int Random1;
	int Random2;
	int Random3;
	void make_shapes();
	void make_shape(int r);
	int count = 0;
	string output;
	void report_status();
public:
	SlotMachine() = default;
	SlotMachine(const SlotMachine &) = delete;
	SlotMachine & operator=(const SlotMachine &) = delete;
	void run();
	void release_shapes();
	virtual ~SlotMachine();
};

#endif // !SLOTMACHINE_H
