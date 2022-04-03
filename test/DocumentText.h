#include <2out/2out.h>

class Document;
class View;

class DocumentText final : public oout::Text {
public:
	DocumentText(
		const std::shared_ptr<const Document> &document,
		const std::shared_ptr<const View> &view
	);

	std::string asString() const override;
private:
	const std::shared_ptr<const Document> document;
	const std::shared_ptr<const View> view;
};
