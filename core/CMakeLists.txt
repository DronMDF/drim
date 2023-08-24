CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

ADD_LIBRARY(
	drim_core
	AnsiScreen.cpp
	EmptyDocument.cpp
	EventQueue.cpp
	InputEventSource.cpp
	InsertDocument.cpp
	LineView.cpp
	MainContext.cpp
	SelectView.cpp
	TextDocument.cpp
	TotalView.cpp
)
