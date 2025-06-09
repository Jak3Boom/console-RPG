#pragma once
#include "Location.h"
#include <string>

class Town : public Location
{
public:
	Town(const std::string& name, const std::string& desc);

	void Enter() override;
	void Action() override;
};