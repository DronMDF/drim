#pragma once
#include <cstddef>
#include "View.h"

class LineView final : public View {
public:
	// Ограничивает область видимости первой и последней строкой.
	LineView(size_t from, size_t to);

	// Ограничиваем область видимости первой строкой
	LineView(size_t from);

	Position from() const override;
	Position to() const override;
private:
	const size_t _from;
	const size_t _to;
};
