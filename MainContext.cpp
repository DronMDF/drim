#include "MainContext.h"

using namespace std;

shared_ptr<const Context> MainContext::process(const shared_ptr<const Event> &event) const
{
	// Здесь должен быть диспетчер
	// Чтобы разрулить события по обработчикам.
	// И событие вероятно ничего не знает про Context
	// Хотя оно может знать про него абстрактно.
	//
	// И события могут быть не только связанные с клавиатурой.
	//
	// Идея описать все варианты команд здесь - достаточно интересная.
	// Размазывать это описание по разным методам и классам довольно неюзабельно
	// Но нужно уметь указывать всякие паттерны.
	//
	// Но червь оптимизации гложет - это же будут аллокации...
	// И довольно много... десятки?
	const auto {
		LEFT, <MoveContextFactory>(-1, 0)
		RIGHT, <MoveContextFactrory>(+1, 0)
		UP, <MoveContextFactrory>(0, -1) 
		DOWN, <MoveContextFactrory>(0, +1) 
		"i", <InsertContextFactory>(0, 0)
	}

	return event->select(actions)->create(screen, x, y, doc);
}
