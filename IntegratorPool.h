// Adam Geppert, Piotr Bodnar Grupa 7

#pragma once
#include "Integrator.h"
#include <vector>
#include <mutex>
class IntegratorPool
{
	std::vector<Integrator *> pool;
public:
	IntegratorPool(const size_t);
	virtual ~IntegratorPool();
	Integrator * GetInstance();
	size_t GetLoad();
};

