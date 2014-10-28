#ifndef AGENT_H
#define AGENT_H

class Agent
{
public:
	Agent(int qSize);
	
	void episode(int initState);
	void chooseAction();
	int getRandomAction(int upper, int lower);
	
	void setQMatrix(std::vector<std::vector<int>>& Q);
	void setRMatrix(std::vector<std::vector<int>>& R);

	
	//void printE
private:
	double reward_;
	double gamma_;
	int currentState_;
	int qSize_;
	
	std::vector<std::vector<int>> R_;
	std::vector<std::vector<int>> Q_;
}
#endif // AGENT_H