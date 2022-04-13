#include "Document.h"

class TextDocument final : public Document {
public:
	TextDocument(const std::string &text);

	std::string over() const override;
private:
	const std::string text;
};
