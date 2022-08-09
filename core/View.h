#pragma once
#include <cstddef>

struct Position;

class View {
public:
	virtual ~View() = default;

	// Первая видимая строка
	virtual Position from() const = 0;

	// Последняя видимая строка
	virtual Position to() const = 0;
};
