#pragma once
#include "Context.h"

class Screen;

class MainContext final : public Context {
public:
	explicit MainContext(const std::shared_ptr<const Screen> &screen);

	std::shared_ptr<const Context> process(
		const std::shared_ptr<const Event> &event
	) const override;
};
