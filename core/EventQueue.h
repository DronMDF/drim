#pragma once
#include <memory>
#include <queue>

class Event;

class EventQueue final {
public:
	void push(const std::shared_ptr<const Event> &event);
	std::shared_ptr<const Event> pop();
	bool empty() const;
private:
	std::queue<std::shared_ptr<const Event>> queue_;
	mutable std::mutex lock;
};
