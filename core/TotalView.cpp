#include "TotalView.h"
#include <limits>
#include "Position.h"

using namespace std;

Position TotalView::from() const
{
	return {1, 1};
}

Position TotalView::to() const
{
	return {numeric_limits<size_t>::max(), numeric_limits<size_t>::max()};
}
