// Adam Geppert, Piotr Bodnar Grupa 7

#pragma once
#include "Producer.h"
#include "Consumer.h"
#include <iostream>

/*int main()
{
	const size_t numberOfConsumers = 2;

	Producer* producer = new Producer();
	producer->Start();

	vector<Consumer*> consumers;
	for (size_t i = 0; i < numberOfConsumers; i++)
	{
		consumers.push_back(new Consumer(producer));
		consumers.back()->Start();
	}

	while (true)
	{
		char key = getchar();

		if (key == 'q')
		{
			break;
		}
		else if (key == '\n')
		{
			cout << endl;
			cout << "Producer data size: " << producer->GetData().size() << endl;
			for (size_t i = 0; i < numberOfConsumers; i++)
			{
				cout << "Consumer [" << i << "] avarage: " << consumers[i]->GetAvarage() << endl;
			}
			cout << endl;
		}
	}

	for (auto consumer : consumers)
	{
		consumer->Stop();
		delete consumer;
	}

	producer->Stop();
	delete producer;

}*/