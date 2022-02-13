#include "AnsiScreen.h"
#include <iostream>

using namespace std;

AnsiScreen::AnsiScreen(int maxx, int maxy)
	: maxx(maxx), maxy(maxy)
{
	// Sctoll console state up.
	for (int i = 1; i < maxy; i++) {
		cout << endl;
	}
}

AnsiScreen::~AnsiScreen()
{
	// return to console after editor screen
	cout << "\x1b[999B" << endl;
}

void AnsiScreen::draw(const vector<string> &lines) const
{
	cout << "\x1b[H"; // go home
	cout << "\x1b[J"; // clear screen
	for (const auto &l : lines) {
		cout << l << endl;
	}
}
