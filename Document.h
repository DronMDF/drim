#pragma once

// Document - это довольно широкое понятие.
// В базовой сути - он хранит текстовый файл.
//
// Но структура класса может различаться в зависимости от режимов работы
// - Это может быть полный документ.
// - Может быть исправление к документу
// - Может быть буффер для ввода данных в документ, которые еще не приняты.
// - Может быть декоратор с контекстной подсказкой... Или лучше их сюда не примешивать... :) Декораторы могут накладываться в контексте перед выводом

class Document {
public:
	virtual ~Document() = default;

	std::shared_ptr<const Document> undo() const;
	std::shared_ptr<const Document> redo() const;
	std::shared_ptr<const Document> input(const int x, const int y, const std::string &text) const;
};
