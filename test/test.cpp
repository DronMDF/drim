#include <iostream>
#include <memory>
#include <2out/2out.h>
#include "EmptyDocumentTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const auto tests = SuiteTest(
		make_shared<const MatchTest>(
			make_shared<const StringText>("drim"),
			make_shared<const EqualMatch>("drim")
		),
		make_shared<const MatchTest>(
			make_shared<const SignedText>(sizeof(wchar_t)),
			make_shared<const EqualMatch>("4")
		),
		make_shared<EmptyDocumentTest>()
	);

	const shared_ptr<const Result> result = tests.result();

	cout << OoutReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
