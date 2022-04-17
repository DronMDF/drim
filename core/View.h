#pragma once
#include <cstddef>

class View {
public:
	virtual ~View() = default;

	// Первая видимая строка
	virtual size_t from() const = 0;

	// Последняя видимая строка
	virtual size_t to() const = 0;
};
