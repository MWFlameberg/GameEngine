#pragma once
#include "PhysicalObj.h"
#include "DeviceResources.h"
#include <pch.cpp>
#include <StepTimer.h>


class ControllableObj : public PhysicalObj
{
public:
	// Constructors
	ControllableObj();
	ControllableObj(int idIn);
	ControllableObj(int idIn, std::string nameIn, std::string descIn);
	~ControllableObj() = default;

	// Accessors

protected:
};

