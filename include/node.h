#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

class Node
{
public:
	Node();
	
	void updateReward(double newReward);
	void addNeighbour(int index);
	
private:
	int index_;
	double reward_;
	
	std::vector<int> neightbours_;
	std::vector<double> qValues_
	
	
}
#endif // NODE_H