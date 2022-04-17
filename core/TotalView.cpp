#include "TotalView.h"
#include <limits>

using namespace std;

size_t TotalView::from() const
{
	return 1;
}

size_t TotalView::to() const
{
	return numeric_limits<size_t>::max();
}
