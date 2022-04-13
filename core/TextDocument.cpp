#include "TextDocument.h"

using namespace std;

TextDocument::TextDocument(const string &text)
	: text(text)
{
}

string TextDocument::over() const
{
	return text;
}
