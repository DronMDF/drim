#include "InsertDocument.h"
#include <limits>
#include "SelectView.h"

using namespace std;

InsertDocument::InsertDocument(
	const shared_ptr<const Document> &document,
	size_t line,
	size_t pos,
	const string &text
) : document(document), line(line), pos(pos), text(text)
{
}

string InsertDocument::over(const shared_ptr<const View> &view) const
{
	// @todo - view должен уметь включать один в другой.
	//  Чтобы запросы к документу, не видимые через view вырождались в пустой view.
	// @todo - никак не используется view
	const auto prefix = document->over(
		make_shared<SelectView>(Position{1, 1}, Position{line, pos})
	);
	const auto suffix = document->over(
		make_shared<SelectView>(
			Position{line, pos},
			Position{numeric_limits<size_t>::max(), numeric_limits<size_t>::max()}
		)
	);
	return prefix + text + suffix; 
}
