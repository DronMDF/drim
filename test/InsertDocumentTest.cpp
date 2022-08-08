#include "InsertDocumentTest.h"
#include <2out/2out.h>
#include <core/InsertDocument.h>
#include <core/TextDocument.h>
#include <core/TotalView.h>
#include "DocumentText.h"

using namespace std;
using namespace oout;

InsertDocumentTest::InsertDocumentTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Документ с вставленным c хвоста текстом"s,
		make_shared<DocumentText>(
			make_shared<InsertDocument>(
				make_shared<TextDocument>("Hello"s),
				1, string::npos,
				" World"s
			),
			make_shared<TotalView>()
		),
		make_shared<EqualMatch>("Hello World"s)
	)
)
{
}
