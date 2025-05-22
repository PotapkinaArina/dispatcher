#include <iostream>
#include <vector>
#include "Airplane.h"

int main()
{
	vector<Airplane* > planes;
	planes.push_back(new SmallPlane(Direction::EAST));
	planes.push_back(new MediumPlane(Direction::NORTH));
	planes.push_back(new TrainingPlane(Direction::WEST));

	for (int i = 0; i < planes.size(); i++)
	{
		planes[i]->printInfo();
		cout << endl;
	}

}