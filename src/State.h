#ifndef STATE_H
#define STATE_H

class Buildings;

class State {

protected:
	Buildings* building;

public:
	virtual void handle() = 0;
	virtual void changeState() = 0;
};

#endif
