#pragma once
#include "View.h"
#include "Position.h"

class SelectView final : public View {
public:
	SelectView(const Position &pos_from, const Position &pos_to);
	SelectView(size_t line_from, size_t pos_from, size_t line_to, size_t pos_to);
	Position from() const override;
	Position to() const override;
private:
	const Position pos_from;
	const Position pos_to;
};
