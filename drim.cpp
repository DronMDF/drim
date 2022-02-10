#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
#include "AnsiScreen.h"

using namespace std;

int main(int, char **)
{
	AnsiScreen screen;
	screen.draw({
		"first",
		"second",
		"third"
	});

	this_thread::sleep_for(5s);

	screen.draw({
		"first new",
		"second",
		"third"
	});

	//struct termios raw;
	//tcgetattr(STDIN_FILENO, &raw);
	//// Прикопать оригинальный, чтобы восстановить при выходе.
	//raw.c_lflag &= ~(ECHO | ICANON);
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

	//while (true) {
	//	fd_set rfds;
	//	FD_ZERO(&rfds);
	//	FD_SET(STDIN_FILENO, &rfds);
	//	int max_fd = STDIN_FILENO + 1;
	//	if (select(max_fd + 1, &rfds, nullptr, nullptr, nullptr) == -1) {
	//		continue;
	//	}
	//	
	//	if (FD_ISSET(STDIN_FILENO, &rfds)) {
	//		char buffer[1024];
	//		int size = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

	//		cout << "input: ";
	//		for (int i = 0; i < size; i++) {
	//			cout << setw(2) << setfill('0') << hex << int(buffer[i]) << " ";
	//		}
	//		cout << endl;
	//	}
	//}

	return 0;
}
