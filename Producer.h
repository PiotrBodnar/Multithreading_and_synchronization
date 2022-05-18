// Adam Geppert, Piotr Bodnar Grupa 7

#pragma once
#include <vector>
#include <mutex>
#include "IThread.h"

using namespace std;

class Producer :
    public IThread
{
private:

    vector<double> data;
    mutex dataMutex;

    void ThreadRoutine() override;

public:
    vector<double> GetData();
};

