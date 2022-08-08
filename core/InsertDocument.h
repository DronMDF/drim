#pragma once
#include "Document.h"

class InsertDocument final : public Document {
public:
	InsertDocument(
		const std::shared_ptr<const Document> &document,
		size_t line,
		size_t pos,
		const std::string &text
	);

	std::string over(const std::shared_ptr<const View> &view) const override;

private:
	const std::shared_ptr<const Document> document;
	const size_t line;
	const size_t pos;
	const std::string text;
};
