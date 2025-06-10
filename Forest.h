#pragma once
#include "Location.h"
#include <string>

class Forest : public Location
{
public:
	Forest(const std::string& name, const std::string& desc);

	void Enter() override;
	char Action() override;
};