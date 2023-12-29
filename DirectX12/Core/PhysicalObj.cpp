#include "pch.h"
#include "PhysicalObj.h"

PhysicalObj::PhysicalObj() : BaseObj()
{
	xPos, yPos = -1;
	xSize, ySize = 0;
}
PhysicalObj::PhysicalObj(int idIn) : BaseObj(idIn)
{
	xPos, yPos = -1;
	xSize, ySize = 0;
}
PhysicalObj::PhysicalObj(int idIn, std::string nameIn, std::string descIn) : BaseObj(idIn, nameIn, descIn)
{
	xPos, yPos = -1;
	xSize, ySize = 0;
}

void PhysicalObj::setXPos(float xPosIn)
{
	xPos = xPosIn;
}
void PhysicalObj::addXPos(float xAmt)
{
	xPos += xAmt;
}
float PhysicalObj::getXPos()
{
	return xPos;
}
void PhysicalObj::setYPos(float yPosIn)
{
	yPos = yPosIn;
}
void PhysicalObj::addYPos(float yAmt)
{
	yPos += yAmt;
}
float PhysicalObj::getYPos()
{
	return yPos;
}
void PhysicalObj::setXSize(float xSizeIn)
{
	xSize = xSizeIn;
}
float PhysicalObj::getXSize()
{
	return xSize;
}
void PhysicalObj::setYSize(float ySizeIn)
{
	ySize = ySizeIn;
}
float PhysicalObj::getYSize()
{
	return ySize;
}
