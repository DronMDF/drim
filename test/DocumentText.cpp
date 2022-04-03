#include "DocumentText.h"

using namespace std;

DocumentText::DocumentText(
	const shared_ptr<const Document> &document,
	const shared_ptr<const View> &view
) : document(document), view(view)
{
}

string DocumentText::asString() const
{
	return {};
}
