#include "EmptyDocumentTest.h"
#include <2out/2out.h>
#include <core/EmptyDocument.h>
#include <core/TotalView.h>
#include "DocumentText.h"

using namespace std;
using namespace oout;

EmptyDocumentTest::EmptyDocumentTest()
: dirty::Test(
	make_shared<NamedTest>(
		"Пустой документ не имеет текста, отображается только с позиции 0,0"s,
		make_shared<DocumentText>(
			make_shared<EmptyDocument>(),
			make_shared<TotalView>()
		),
		make_shared<EqualMatch>(""s)
	)
)
{
}
