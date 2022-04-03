#pragma once
#include <memory>

// Event - событие возникающее в системе.
// событие направляется в какой-то контекст.
// Но только событие знает какие изменения стоит произвести в контексте.
// Тут используется двойная диспетчеризация
//
// Event может быть следующих типов
// - пользовательские
//   - Навигация
//   - Ввод
// - Системные
//   - Завершилась операция io
//   - Изменился размер экрана

class Context;

class Event {
	virtual ~Event() = default;

	std::shared_ptr<const Context> on(const std::shared_ptr<const Context> &context) const;
};
