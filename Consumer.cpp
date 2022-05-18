#include "Consumer.h"

Consumer::Consumer(Producer* producer) : producer(producer), avarage(0)
{

}

void Consumer::ThreadRoutine()
{
	while (isRunning())
	{
		vector<double> data = producer->GetData();
		double avg = accumulate(data.begin(), data.end(), 0.0) / data.size();

		avarageMutex.lock();
		avarage = avg;
		avarageMutex.unlock();

		this_thread::sleep_for(chrono::microseconds(100));
	}
}

double Consumer::GetAvarage()
{
	avarageMutex.lock();
	double avarage = this->avarage;
	avarageMutex.unlock();

	return avarage;
}
