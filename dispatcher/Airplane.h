#pragma once
#include <iostream>
using namespace std;

enum class PlaneState{WAITING_TAKEOFF, WAITING_LANDING, ON_HOLD, IN_OPERATION, COMPLETED, CRASHED};
enum class PlaneModel{SMALL, MEDIUM, LARGE, TRAINING, MILITARY, CARGO, EXTRA};

class Airplane
{
public:
	Airplane(PlaneModel m, int t, int c, double p, int l) :
		model(m), operationTime(t), maxCircles(c), penalty(p), trackLenght(l) {
		state = PlaneState::WAITING_LANDING;
	}
	virtual ~Airplane() = default;
	virtual double getPenalty() const { return penalty; }

	PlaneModel getModel() const { return model; }
	PlaneState getState() const { return state; }
	int getTrackLenght() const { return trackLenght; }
	int getOperationTime() const { return operationTime; }
	int getMaxCircles() const { return maxCircles; }
	void changeState(PlaneState s) { state = s; }
	void printInfo() const;
	
private:
	PlaneModel model;
	PlaneState state;
	int operationTime;
	int maxCircles;
	double penalty;
	int trackLenght;
};

class SmallPlane : public Airplane
{
public:
	SmallPlane() : Airplane(PlaneModel::SMALL, 2, 4, 0.5, 800) {}
};

class MediumPlane : public Airplane
{
public:
	MediumPlane() : Airplane(PlaneModel::MEDIUM, 3, 3, 0.5, 2000) {}
};

class LargePlane : public Airplane
{
public:
	LargePlane() : Airplane(PlaneModel::LARGE, 6, 2, 0.5, 3000) {}
};

class TrainingPlane : public Airplane
{
public:
	TrainingPlane() : Airplane(PlaneModel::TRAINING, 6, 4, 0.5, 1000) {}
	double getPenalty() const override { if (this->getState() == PlaneState::ON_HOLD) return 0.5; else return 0; }
};

class MilitaryPlane : public Airplane
{
public:
	MilitaryPlane() : Airplane(PlaneModel::MILITARY, 1, 1, 2.5, 800){}
};

class CargoPlane : public Airplane
{
public:
	CargoPlane() : Airplane(PlaneModel::CARGO, 3, 2, 0.5, 2000){}
	double getPenalty() const override { if (this->getState() == PlaneState::ON_HOLD) return 0.5; else return -1; } 
};

class ExtraPlane : public Airplane
{
public:
	ExtraPlane() : Airplane(PlaneModel::EXTRA, 1, 0, 2.5, 2000) {}
};