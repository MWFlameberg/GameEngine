#pragma once

#include "BaseObj.h";

class PhysicalObj: public BaseObj
{
public:
	// Constructors
	PhysicalObj();
	PhysicalObj(int idIn);
	PhysicalObj(int idIn, std::string nameIn, std::string descIn);
	~PhysicalObj() = default;

	// Accessors
	void setXPos(float xPosIn);
	void addXPos(float xAmt);
	float getXPos();
	void setYPos(float yPosIn);
	void addYPos(float yAmt);
	float getYPos();

	void setXSize(float xSizeIn);
	float getXSize();
	void setYSize(float ySizeIn);
	float getYSize();
protected:
	float xPos;
	float yPos;
	float xSize;
	float ySize;
};

