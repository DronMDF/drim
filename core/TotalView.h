#include "View.h"

class TotalView final : public View {
public:
	Position from() const override;
	Position to() const override;
};
