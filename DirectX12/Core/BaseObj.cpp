#include "pch.h"
#include "BaseObj.h"

BaseObj::BaseObj()
{
	id = -1;
}
BaseObj::BaseObj(int idIn)
{
	id = idIn;
	name,desc = "";
}
BaseObj::BaseObj(int idIn, std::string nameIn, std::string descIn)
{
	id = idIn;
	name = nameIn;
	desc = descIn;
}

int BaseObj::getID()
{
	return id;
}
void BaseObj::setName(std::string nameIn)
{
	name = nameIn;
}
std::string BaseObj::getName()
{
	return name;
}
void BaseObj::setDesc(std::string descIn)
{
	desc = descIn;
}
std::string BaseObj::getDesc()
{
	return desc;
}
bool BaseObj::validate()
{
	return id >= 0;
}
