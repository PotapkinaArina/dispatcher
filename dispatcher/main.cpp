#include <iostream>
#include <vector>
#include "Airplane.h"
#include "LevelManager.h"

int main()
{
	vector<Airplane* > planes;
	planes.push_back(new SmallPlane());
	planes.push_back(new MediumPlane());
	planes.push_back(new TrainingPlane());

	for (int i = 0; i < planes.size(); i++)
	{
		planes[i]->printInfo();
		cout << endl;
	}
}