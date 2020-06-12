#pragma once
#include<stack>

// This is the maximum Balls the tube can hold.
#define TUBESIZE 4
typedef char Ball;

/**
 * This class is responsible for controlling the tube actions. 
 * Like push and pop and check for emptiness and homogenousity.
 */
class Tube {
private:
	// the stack holding the balls
	std::stack<Ball> tube;
public:
	// push a ball into stack
	// returns false if the stack is full.
	bool push(Ball);
	// returns the last element from the tube
	Ball top() const;
	// pop a ball from the stack
	// returns true if the stack is empty.
	bool pop(Ball &b);
	// Get size of the tube
	int size() const;
	// returns true if the stack is full
	bool isFull() const;
	// returns true if the stack is homogenous with one color
	bool isHomogenous() const;
	// returns true if the stack is empty
	bool isEmpty() const;
	// operator ==
	bool operator!=(const Tube& t);
};