#pragma once
#include <string>

class BaseObj
{
public:
	// Constructors
	BaseObj();
	BaseObj(int idIn);
	BaseObj(int idIn, std::string nameIn, std::string descIn);
	~BaseObj() = default;

	// Accessors
	int getID();
	void setName(std::string nameIn);
	std::string getName();
	void setDesc(std::string descIn);
	std::string getDesc();
	bool validate();
protected:
	int id;
	std::string name;
	std::string desc;
};

