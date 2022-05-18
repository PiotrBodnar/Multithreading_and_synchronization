#pragma once
#include "IThread.h"
#include "Producer.h"
#include <numeric>

class Consumer :
    public IThread
{
private:
    Producer* producer;
    double avarage;
    mutex avarageMutex;

    void ThreadRoutine() override;

public:
    Consumer(Producer* producer);

    double GetAvarage();
};

