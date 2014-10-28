#include <vector>

#include "agent.h"




//http://mnemstudio.org/path-finding-q-learning-example-1.htm
int main(int argc, char *argv[])
{
	int qSize = 6;
	Agent agent(qSize);
	
	std::vector<std::vector<int>> R = {
		{-1, -1, -1, -1, 0, -1},
		{-1, -1, -1, 0, -1, 100},
		{-1, -1, -1, 0, -1, -1},
		{-1, 0, 0, -1, 0, -1},
		{0, -1, -1, 0, -1, 100},
		{-1, 0, -1, -1, 0, 100}
	};
	
	agent.setRMatrix(R);
	
	int iterations = 10;
	int episodeNumber = 10;
	int initialStates[episodeNumber];
	
	for(int i = 0; i < episodeNumber; i++)
	{
		initialStates[i] = std::rand() % 6;
	}
	
	for(int i = 0; i < iterations; i++)
	{
		for(int j = 0; j < episodeNumber; j++)
		{
			agent.episode(initialStates[j]);
		}
		std::cout "Q Matrix after iteration #" << i < ":\n";
		agent.printQMatrix();
	}

	return 0;
}