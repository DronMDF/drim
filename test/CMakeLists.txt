
ADD_EXECUTABLE(
	drim_test
	test.cpp
	# Вспомогательные классы
	DocumentText.cpp
	# Тесты
	EmptyDocumentTest.cpp
	TextDocumentTest.cpp
)

ADD_DEPENDENCIES(
	drim_test
	drim_core
)

TARGET_LINK_LIBRARIES(
	drim_test
	drim_core
	2out
)

ADD_TEST(
	NAME drim_test
	COMMAND drim_test
)
