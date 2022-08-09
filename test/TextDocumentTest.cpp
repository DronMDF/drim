#include "TextDocumentTest.h"
#include <2out/2out.h>
#include <core/LineView.h>
#include <core/SelectView.h>
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
	),
	make_shared<NamedTest>(
		"Отображаемая часть документа ограничена View"s,
		make_shared<DocumentText>(
			make_shared<TextDocument>("test1\ntest2"s),
			make_shared<LineView>(2)
		),
		make_shared<EqualMatch>("test2"s)
	),
	make_shared<NamedTest>(
		"Выбор текста до позиции в строке"s,
		make_shared<DocumentText>(
			make_shared<TextDocument>("Hello"s),
			make_shared<SelectView>(1, 1, 1, 2)
		),
		make_shared<EqualMatch>("H"s)
	)
)
{
}
