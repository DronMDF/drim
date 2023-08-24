#include <iostream>
#include <memory>
#include <2out/2out.h>
#include "EmptyDocumentTest.h"
#include "EventQueueTest.h"
#include "InsertDocumentTest.h"
#include "TextDocumentTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const auto tests = SuiteTest(
		make_shared<EmptyDocumentTest>(),
		make_shared<EventQueueTest>(),
		make_shared<InsertDocumentTest>(),
		make_shared<TextDocumentTest>()
	);

	const shared_ptr<const Result> result = tests.result();

	cout << OoutReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
