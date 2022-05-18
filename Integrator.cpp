// Adam Geppert, Piotr Bodnar Grupa 7

#include "Integrator.h"

Integrator::Integrator() : status(Integrator::Status::IDLE), step(0.0)
{
}

void Integrator::ThreadRoutine()
{
	while (isRunning())
	{
		if (this->GetStatus() == Status::WORKING)
		{
			double res = 0.0;
			for (size_t i = 0; i < data.size(); i++)
			{
				res += data[i] * step;
			}

			resultMutex.lock();
			result = res;
			resultMutex.unlock();

			SetStatus(Status::IDLE);
		}

		std::this_thread::yield();
	}
}

Integrator::Status Integrator::GetStatus()
{
	Status actual;
	statusMutex.lock();
	actual = status;
	statusMutex.unlock();

	return actual;
}

void Integrator::SetStatus(Status status)
{
	statusMutex.lock();
	this->status = status;
	statusMutex.unlock();
}

double Integrator::GetResult()
{
	double res;
	resultMutex.lock();
	res = result;
	resultMutex.unlock();

	return res;
}

void Integrator::Count(const std::vector<double>& data, const double step)
{
	dataMutex.lock();
	this->step = step;
	this->data = data;
	dataMutex.unlock();
	SetStatus(Integrator::Status::WORKING);
}