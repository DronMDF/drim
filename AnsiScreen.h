#pragma once
#include "Screen.h"

class AnsiScreen final : public Screen
{
public:
	AnsiScreen();
	~AnsiScreen() override;

	void draw(const std::vector<std::string> &lines) const override;
};
