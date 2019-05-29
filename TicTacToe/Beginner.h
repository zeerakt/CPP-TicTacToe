#pragma once
#include "tic_tac_toe.h"
class Beginner :public tic_tac_toe
{
public:
	Beginner();
	void computer_move();
	virtual ~Beginner();
};

