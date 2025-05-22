#pragma once
#include <iostream>
using namespace std;

enum class PlaneState{WAITING_TAKEOFF, WAITING_LANDING, ON_HOLD, IN_OPERATION, COMPLETED, CRASHED};
enum class PlaneModel{SMALL, MEDIUM, LARGE, TRAINING, MILITARY, CARGO, EXTRA};
enum class Direction {
	NORTH = 0,
	EAST = 90,
	SOUTH = 180,
	WEST = 270
};

class Airplane
{
public:
	Airplane(PlaneModel m, int t, int c, double p, int l, Direction d) :
		model(m), operationTime(t), maxCircles(c), penalty(p), trackLenght(l), direction(d) {
		state = PlaneState::WAITING_LANDING;
	}
	virtual ~Airplane() = default;
	virtual double getPenalty() const { return penalty; }

	PlaneModel getModel() const { return model; }
	PlaneState getState() const { return state; }
	int getTrackLenght() const { return trackLenght; }
	int getOperationTime() const { return operationTime; }
	int getMaxCircles() const { return maxCircles; }
	Direction getDirection() const{ return direction; }
	void changeState(PlaneState s) { state = s; }
	void printInfo() const;
	
private:
	PlaneModel model;
	PlaneState state;
	int operationTime;
	int maxCircles;
	double penalty;
	int trackLenght;
	Direction direction;
};

class SmallPlane : public Airplane
{
public:
	SmallPlane(Direction d) : Airplane(PlaneModel::SMALL, 2, 4, 0.5, 800, d) {}
};

class MediumPlane : public Airplane
{
public:
	MediumPlane(Direction d) : Airplane(PlaneModel::MEDIUM, 3, 3, 0.5, 2000, d) {}
};

class LargePlane : public Airplane
{
public:
	LargePlane(Direction d) : Airplane(PlaneModel::LARGE, 6, 2, 0.5, 3000, d) {}
};

class TrainingPlane : public Airplane
{
public:
	TrainingPlane(Direction d) : Airplane(PlaneModel::TRAINING, 6, 4, 0.5, 1000, d) {}
	double getPenalty() const override { if (this->getState() == PlaneState::ON_HOLD) return 0.5; else return 0; }
};

class MilitaryPlane : public Airplane
{
public:
	MilitaryPlane(Direction d) : Airplane(PlaneModel::MILITARY, 1, 1, 2.5, 800, d){}
};

class CargoPlane : public Airplane
{
public:
	CargoPlane(Direction d) : Airplane(PlaneModel::CARGO, 3, 2, 0.5, 2000, d){}
	double getPenalty() const override { if (this->getState() == PlaneState::ON_HOLD) return 0.5; else return -1; } 
};

class ExtraPlane : public Airplane
{
public:
	ExtraPlane(Direction d) : Airplane(PlaneModel::EXTRA, 1, 0, 2.5, 2000, d) {}
};