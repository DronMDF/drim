#include "MainContext.h"
#include <vector>
#include "Event.h"
#include "InsertContextMatch.h"

using namespace std;

MainContext::MainContext(const shared_ptr<const Screen> &screen [[maybe_unused]])
{
}

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
	//const Matches matches(
	const vector<shared_ptr<const Match>> matches = {
		//LEFT, <MoveContextFactory>(-1, 0)
		//RIGHT, <MoveContextFactrory>(+1, 0)
		//UP, <MoveContextFactrory>(0, -1) 
		//DOWN, <MoveContextFactrory>(0, +1) 
		//make_shared<InsertContextMatch>("a"),
		//make_shared<InsertContextMatch>("i")
	};

	// Здесь не хватает одного промежуточного звена.
	// Не понятно как код из Event можно передать в метод создания.
	// Мы же не можем залесь в Event и достать из него код.
	//
	// Но матч может сам являться хранителем, или даже создателем фабрики.
	// А он получает содержимое евента.
	return {}; //event->select(matches)->create(screen);
}
