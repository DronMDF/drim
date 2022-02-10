#include "AnsiScreen.h"
#include <iostream>

using namespace std;

AnsiScreen::AnsiScreen()
{
	cout << "\x1b[47h" << flush; 	// Save screen
}

AnsiScreen::~AnsiScreen()
{
	cout << "\x1b[47l" << flush;	// Restore screen
}

void AnsiScreen::draw(const vector<string> &lines) const
{
	cout << "\x1b[H"; // go home
	cout << "\x1b[J"; // clear screen
	for (const auto &l : lines) {
		cout << l << endl;
	}
}
