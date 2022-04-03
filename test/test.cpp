#include <iostream>
#include <memory>
#include <2out/2out.h>

using namespace std;
using namespace oout;

int main(int, char **)
{
	const auto tests = MatchTest(
		make_shared<const StringText>("drim"),
		make_shared<const EqualMatch>("drim")
	);

	const shared_ptr<const Result> result = tests.result();

	cout << OoutReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
