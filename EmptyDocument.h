#include "Document.h"

class EmptyDocument final : public Document {
public:
	std::string over() const override;
};
