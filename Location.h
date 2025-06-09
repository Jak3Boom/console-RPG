#pragma once
#include <string>

class Location
{
public:
	Location(const std::string& name, const std::string& desc);
	virtual void Enter() = 0;
	virtual void Action() = 0;

protected:
	std::string name;
	std::string description;
};