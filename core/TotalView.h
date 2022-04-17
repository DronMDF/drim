#include "View.h"

class TotalView final : public View {
public:
	size_t from() const override;
	size_t to() const override;
};
