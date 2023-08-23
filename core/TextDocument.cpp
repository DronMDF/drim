#include "TextDocument.h"
#include <algorithm>
#include "View.h"
#include "Position.h"

using namespace std;

TextDocument::TextDocument(const string &text)
	: text(text)
{
}

string TextDocument::over(const shared_ptr<const View> &view) const
{
	const auto from = view->from();
	auto ifrom = text.begin();
	size_t n = 1;	// Номер строки
	while (n < from.line) {
		ifrom = find(ifrom, text.end(), '\n');
		if (ifrom == text.end()) {
			return {};
		}
		ifrom++;
		n++;
	}
	int p = 1;
	while (ifrom != text.end() && *ifrom != '\n' && p < from.pos) {
		// todo: Не учитываем utf8
		ifrom++;
		p++;
	}

	const auto to = view->to();
	auto ito = ifrom;
	while (n < to.line) {
		ito = find(ito, text.end(), '\n');
		if (ito == text.end()) {
			return {ifrom, ito};
		}
		ito++;
		n++;
		p = 1;
	}
	while (ito != text.end() && *ito != '\n' && p < to.pos) {
		// todo: Не учитываем utf8
		ito++;
		p++;
	}

	return {ifrom, ito};
}
