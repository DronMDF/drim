#include "EventQueue.h"

using namespace std;

void EventQueue::push(const shared_ptr<const Event> &event)
{
	lock_guard<mutex> guard(lock);
	queue_.push(event);
}

std::shared_ptr<const Event> EventQueue::pop()
{
	lock_guard<mutex> guard(lock);
	const auto event = queue_.front();
	queue_.pop();
	return event;
}

bool EventQueue::empty() const
{
	lock_guard<mutex> guard(lock);
	return queue_.empty();
}
