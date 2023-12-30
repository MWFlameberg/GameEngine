#include "pch.h"
#include "ControllableObj.h"

ControllableObj::ControllableObj() : PhysicalObj()
{
}

ControllableObj::ControllableObj(int idIn) : PhysicalObj(idIn)
{
}

ControllableObj::ControllableObj(int idIn, std::string nameIn, std::string descIn) : PhysicalObj(idIn, nameIn, descIn)
{
}