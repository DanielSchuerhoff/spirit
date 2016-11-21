#pragma once
#ifndef OPTIMIZER_SIB2_H
#define OPTIMIZER_SIB2_H

#include <vector>

#include "Core_Defines.h"
#include "Optimizer.hpp"
#include "Spin_System_Chain.hpp"

namespace Engine
{
	/*
		Nikolai's version of the SIB Optimizer... Translated from his code... May be buggy, but so might the original SIB...
	*/
	class Optimizer_SIB2 : public Optimizer
	{
	public:
		Optimizer_SIB2(std::shared_ptr<Engine::Method> method);
		
		// One step in the optimization
		void Iteration() override;
		
		// Optimizer name as string
		std::string Name() override;
		std::string FullName() override;

    private:
		// Temporary Spins arrays
		std::vector<std::vector<scalar>> spins_temp;

		void Gen_Xi(Data::Spin_System & s, std::vector<scalar> & xi, scalar eps);
    };
}

#endif