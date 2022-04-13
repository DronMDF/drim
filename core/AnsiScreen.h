#pragma once
#include "Screen.h"

class AnsiScreen final : public Screen
{
public:
	AnsiScreen(int maxx, int maxy);
	~AnsiScreen() override;

	void draw(const std::vector<std::string> &lines) const override;
private:
	const int maxx;
	const int maxy;
};
