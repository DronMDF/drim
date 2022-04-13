#include <chrono>
#include <memory>
#include <iomanip>
#include <iostream>
#include <thread>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
#include <core/AnsiScreen.h>
#include <core/InputEventSource.h>
#include <core/MainContext.h>

using namespace std;

int main(int, char **)
{
	winsize ws;
	if (ioctl(1, TIOCGWINSZ, &ws) == -1) {
		cerr << "Unable to determine screen size" << endl;
		return -1;
	}
	if (ws.ws_col == 0) {
		cerr << "Unable to determine screen size" << endl;
		return -1;
	}

	const auto input = make_shared<const InputEventSource>();
	const auto screen = make_shared<const AnsiScreen>(ws.ws_col, ws.ws_row);
	shared_ptr<const Context> context = make_shared<const MainContext>(screen);

	while (true) {
		// Мы можем весь главный цикл крутить вокруг клавиатуры,
		// Все операции ввода-вывода или аналитические выгружая в потоки.
		// Хотя всеравно нужна возможность обрабатывать результаты прочих операций в данном контексте
		// ПРИ ОТСУТСТВИИ НАЖАТИЙ НА КЛАВИШИ...
		const auto events = input->event();
		for (const auto &e : events) {
			context = context->process(e);
		}
	}

	return 0;
}
