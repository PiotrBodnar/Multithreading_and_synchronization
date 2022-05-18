// Adam Geppert, Piotr Bodnar Grupa 7

#include "Producer.h"

void Producer::ThreadRoutine()
{
	while(isRunning())
	{
		double randomElement = rand() % 100;

		dataMutex.lock();
		data.push_back(randomElement);
		dataMutex.unlock();

		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
}

vector<double> Producer::GetData()
{
	vector<double> outData;
	dataMutex.lock();
	outData = data;
	dataMutex.unlock();

	return outData;
}
