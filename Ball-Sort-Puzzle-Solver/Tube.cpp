#include "Tube.h"

bool Tube::push(Ball b)
{
	if (isFull()) {
		return false;
	}
	tube.push(b);
	return true;
}

Ball Tube::top()
{
	return tube.top();
}

bool Tube::pop(Ball& b)
{
	if (isEmpty()) {
		return false;
	}
	b = tube.top();
	tube.pop();
	return true;
}

bool Tube::isFull()
{
	return tube.size() == TUBESIZE;
}

bool Tube::isHomogenous()
{
	std::stack<Ball> temp = tube;
	char color = temp.top();
	temp.pop();
	while (!temp.empty()) {
		if (temp.top() != color) {
			return false;
		}
		temp.pop();
	}
	return true;
}

bool Tube::isEmpty()
{
	return tube.empty();
}

