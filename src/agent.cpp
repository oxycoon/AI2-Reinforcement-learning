#include "agent.h"

Agent::Agent(int qSize)
{
	qSize_ = qSize;
}

void Agent::episode(int initState)
{
	currentState_ = initState;
	
	do
	{
		chooseAction()
	}while(currentState_ == 5);
	
	for(int i = 0; i <= (qSize_ - 1); i++)
	{
		chooseAction();
	}
	
	
}

void Agent::chooseAction()
{
	int possibleAction;
	
	possibleAction = getRandomAction(qSize_, 0);
	
}

int Agent::getRandomAction(int upper, int lower)
{
	int action;
	bool isValid = false;
	
	int range = (upper - lower) + 1;
	
	do
	{
		action = lower + int(range * std::rand() / (RAND_MAX + 1.0));
		
		if(R[currentState_][action] > -1)
			isValid = true;
		
	}while(isValid == false);
	
	return action;
}

void Agent::setQMatrix(std::vector<std::vector<int>>& Q)
{
	Q_ = Q;
}

void Agent::setRMatrix(std::vector<std::vector<int>>& R)
{
	R_ = R;
}