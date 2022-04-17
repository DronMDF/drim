#include "LineView.h"
#include <limits>
#include <stdexcept>

using namespace std;

LineView::LineView(size_t from, size_t to)
	: _from(from), _to(to)
{
	if (_from < 1) {
		throw runtime_error("Invalid view from");
	}
}

LineView::LineView(size_t from)
	: LineView(from, numeric_limits<size_t>::max())
{
}

size_t LineView::from() const
{
	return _from;
}

size_t LineView::to() const
{
	return _to;
}
