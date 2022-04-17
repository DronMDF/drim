#include "Document.h"

class EmptyDocument final : public Document {
public:
	std::string over(const std::shared_ptr<const View> &view) const override;
};
