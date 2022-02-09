#pragma once

// Абстракция экрана.
//
// Контекст должен понимать, какой размер текста можно отобразить на экране.

class Screen {
public:
	virtual ~Screen() = default;

	std::tuple<int, int> size() const;
	// Перерисовывается экран целиком.
	void draw(const std::vector<std::string> &lines) const;
};
