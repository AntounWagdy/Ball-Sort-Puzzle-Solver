#include "Tube.h"

bool Tube::push(Ball b)
{
	if (isFull()) {
		return false;
	}
	tube.push(b);
	return true;
}

Ball Tube::top() const
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

int Tube::size() const
{
	return this->tube.size();
}

bool Tube::isFull() const
{
	return tube.size() == TUBESIZE;
}

bool Tube::isHomogenous() const
{
	if (tube.size() == 0) {
		return true;
	}
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

bool Tube::isEmpty() const
{
	return tube.empty();
}

bool Tube::operator!=(const Tube& t)
{
	return this->tube != t.tube;
}

