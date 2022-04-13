#pragma once

class ContextFactory;

class Match {
public:
	virtual ~Match() = default;
	virtual std::pair<bool, std::shared_ptr<const ContextFactory>> match(
		int type,
		const std::string &code
	) const = 0;
};
