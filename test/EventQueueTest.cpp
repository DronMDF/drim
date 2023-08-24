#include "EventQueueTest.h"
#include <2out/2out.h>
#include <core/Event.h>
#include <core/EventQueue.h>

using namespace std;
using namespace oout;

class EventQueueText final : public oout::Text {
public:
	EventQueueText(
		const shared_ptr<EventQueue> &queue,
		const list<shared_ptr<Event>> &events
	) : queue(queue), events(events)
	{
	}

	string asString() const override
	{
		for (const auto &e : events) {
			queue->push(e);
		}
		ostringstream out;
		while (!queue->empty()) {
			const auto e = queue->pop();
			out << e->id() << "|";
		}
		return out.str();
	}
private:
	const shared_ptr<EventQueue> queue;
	const list<shared_ptr<Event>> events;
};


class TestEvent final : public Event {
public:
	TestEvent(const string &id)
		: id_(id)
	{
	}

	string id() const override
	{
		return id_;
	}

	shared_ptr<const Context> on(const shared_ptr<const Context> &context) const override
	{
		return {};
	}
private:
	const string id_;
};


EventQueueTest::EventQueueTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Очередь событий работает по принципу FIFO"s,
		make_shared<EventQueueText>(
			make_shared<EventQueue>(),
			list<shared_ptr<Event>>{
				make_shared<TestEvent>("event1"s),
				make_shared<TestEvent>("event2"s)
			}
		),
		make_shared<EqualMatch>("event1|event2|"s)
	)
)
{
}
