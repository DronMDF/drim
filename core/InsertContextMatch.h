#pragma once
#include <string>
#include "Match.h"

class InsertContextMatch final : public Match {
public:
	explicit InsertContextMatch(const std::string &code);

	std::pair<bool, std::shared_ptr<const ContextFactory>> match(
		int type,
		const std::string &code
	) const override;
private:
	const std::string code;
};
