#include <iostream>
#include <iomanip>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

int main(int, char **)
{
	struct termios raw;
	tcgetattr(STDIN_FILENO, &raw);
	// Прикопать оригинальный, чтобы восстановить при выходе.
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

	while (true) {
		fd_set rfds;
		FD_ZERO(&rfds);
		FD_SET(STDIN_FILENO, &rfds);
		int max_fd = STDIN_FILENO + 1;
		if (select(max_fd + 1, &rfds, nullptr, nullptr, nullptr) == -1) {
			continue;
		}
		
		if (FD_ISSET(STDIN_FILENO, &rfds)) {
			char buffer[1024];
			int size = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

			cout << "input: ";
			for (int i = 0; i < size; i++) {
				if (buffer[i] == 0x1b) {
					return 0;
				}
				cout << setw(2) << setfill('0') << hex << int(buffer[i]) << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
