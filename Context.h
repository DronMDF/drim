#pragma once

// Context - это область хранения состояния редактора.
// Внутри контекста располагается
// - документ
// - экран (необходимо понимание о его размерах)
// - положение видимой области документа на экране
// - положение курсора на экране
//
// Несколько контекстов могут работать паралельно - и образуют Workspace...
// Несколько документов к примеру.
class Context {
public:
	virtual ~Context() = default;

	std::shared_ptr<const Context> navigate(int dx, int dy) const;
	std::shared_ptr<const Context> input(const std::string &text) const;
};
