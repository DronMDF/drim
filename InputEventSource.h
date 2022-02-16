#pragma once
#include <list>
#include "Event.h"

class InputEventSource final {
public:
	InputEventSource();
	~InputEventSource();

	std::list<std::shared_ptr<const Event>> event() const;
};
