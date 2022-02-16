#include "InputEventSource.h"

using namespace std;

InputEventSource::InputEventSource()
	: original(make_shared<termios>())
{
	tcgetattr(STDIN_FILENO, original.get());

	termios raw = *original;
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

InputEventSource::~InputEventSource()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, original.get());
}

list<shared_ptr<const Event>> ImputEventSource::event() const
{
	fd_set rfds;
	FD_ZERO(&rfds);
	FD_SET(STDIN_FILENO, &rfds);
	int max_fd = STDIN_FILENO + 1;
	if (select(max_fd + 1, &rfds, nullptr, nullptr, nullptr) == -1) {
		return {};
	}
		
	char c;
	if (read(STDIN_FILENO, &c, 1) == 0) {
		return {};
	}

	return {make_shared<InputEvent>(c)};
}
