#include "InsertDocument.h"
#include "TotalView.h"

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
	// Наивная реализация для вставки в хвост
	return document->over(make_shared<TotalView>()) + text; 
}
