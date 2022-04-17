#include "TextDocument.h"
#include "View.h"

using namespace std;

TextDocument::TextDocument(const string &text)
	: text(text)
{
}

string TextDocument::over(const shared_ptr<const View> &view) const
{
	const auto first = line_offset(view->from());
	const auto last = line_offset(view->to());
	return text.substr(first, last - first);
}

size_t TextDocument::line_offset(size_t line_no) const
{
	// line_no может быть сильно за пределами строки.
	int n = 1;
	const auto ln = find_if(
		text.begin(),
		text.end(),
		[&](const auto &c){
			if (n == line_no) {
				return true;
			}
			if (c == '\n') {
				n++;
			}
			return false;
		}
	);
	return distance(text.begin(), ln);
}
