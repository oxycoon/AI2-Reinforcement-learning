#include "agent.h"

Agent::Agent(int qSize)
{
	qSize_ = qSize;
	
	for(int i = 0; i < qSize_; i++)
	{
		for(int j = 0; j < qSize_; j++)
		{
			Q_[i].push_back(0);
		}
	}
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
	
	//printQMatrix();
}

void Agent::chooseAction()
{
	int possibleAction;
	
	possibleAction = getRandomAction(qSize_, 0);
	
	if(R_[currentState_][possibleAction] >= 0)
	{
		Q_[currentState_][possibleAction] = updateReward(possibleAction);
		currentState_ = possibleAction;
	}
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

int Agent::updateReward(int newState)
{
	return (int)(R_[currentState_][newState] + (gamma_ * maximum(newState, false)));
}

/**
 *	@parm {number} state 
 *	@parm {bool} returnIndex is the function should return the index or element
 *		of the Q matrix.
 *
 *	@return {number} returns index of Q matrix if returnIndex is true
 *		returns element of Q matrix if returnIndex is false
 */
int Agent::maximum(int state, bool returnIndex)
{
	int winner;
	bool foundNewWinner;
	bool done = false;
	
	winner = 0;
	
	do
	{
		foundNewWinner = false;
		for(int i = 0; i <= (qSize_ - 1); i++)
		{
			if((i < winner) || (i > winner))
			{
				if(Q_[state][i] > Q_[state][winner])
				{
					winner = i;
					foundNewWinner = true;
				}
			}
		}
		if(foundNewWinner == false)
		{
			done = true;
		}
	}while(done = false);
	
	if(returnIndex)
		return winner;
	else
		return Q_[state][winner];
}

void Agent::setQMatrix(std::vector<std::vector<int>>& Q)
{
	Q_ = Q;
}

void Agent::setRMatrix(std::vector<std::vector<int>>& R)
{
	R_ = R;
}

void Agent::printQMatrix()
{
	for(int i = 0; i < qSize_; i++)
	{
		for(int j = 0; j < qSize_; j++)
		{
			std::cout << Q_[i][j];
			if(j < qSize_ - 1)
				std::cout << ", ";
		}
		std::cout << "/n";
	}
	std::cout << "/n";
}