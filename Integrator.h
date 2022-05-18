// Adam Geppert, Piotr Bodnar Grupa 7

#pragma once
#include <vector>
#include <mutex>
#include "IThread.h"

class Integrator : public IThread
{
public:

	enum Status
	{
		IDLE,
		WORKING
	};

	Integrator();
	void Count(const std::vector<double>&, const double);
	Status GetStatus();
	double GetResult();

private:
	std::vector<double> data;
	double step;
	double result = 0.0;
	std::mutex dataMutex;
	std::mutex statusMutex;
	std::mutex resultMutex;
	Integrator::Status status;

	void SetStatus(Status);
	virtual void ThreadRoutine() override;
};

