#include "TextDocumentTest.h"
#include <2out/2out.h>
#include <core/TextDocument.h>
#include <core/TotalView.h>
#include "DocumentText.h"

using namespace std;
using namespace oout;

TextDocumentTest::TextDocumentTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Документ с текстом отображается"s,
		make_shared<DocumentText>(
			make_shared<TextDocument>("test"s),
			make_shared<TotalView>()
		),
		make_shared<EqualMatch>("test"s)
	)
)
{
}
