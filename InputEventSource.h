#pragma once
#include <list>
#include <memory>
#include "Event.h"

struct termios;

class InputEventSource final {
public:
	InputEventSource();
	~InputEventSource();

	std::list<std::shared_ptr<const Event>> event() const;
private:
	const std::shared_ptr<termios> original;
};
