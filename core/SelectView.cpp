#include "SelectView.h"
#include <limits>

using namespace std;

SelectView::SelectView(const Position &pos_from, const Position &pos_to)
	: pos_from(pos_from), pos_to(pos_to)
{
}

SelectView::SelectView(size_t line_from, size_t pos_from, size_t line_to, size_t pos_to)
	: SelectView({line_from, pos_from}, {line_to, pos_to})
{
}

Position SelectView::from() const
{
	return pos_from;
}

Position SelectView::to() const
{
	return pos_to;
}
