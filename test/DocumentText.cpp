#include "DocumentText.h"
#include <core/Document.h>

using namespace std;

DocumentText::DocumentText(
	const shared_ptr<const Document> &document,
	const shared_ptr<const View> &view
) : document(document), view(view)
{
}

string DocumentText::asString() const
{
	return document->over(view);
}
