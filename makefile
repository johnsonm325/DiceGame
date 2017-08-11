CXX = g++
CXXFLAGS += -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g#

OBJS = inputValidation.o DiceMenu.o dice.o loadedDie.o game.o gameMain.o

SRCS = inputValidation.cpp DiceMenu.cpp dice.cpp loadedDie.cpp game.cpp gameMain.cpp

HEADERS = inputValidation.h DiceMenu.h Dice.h LoadedDie.h Game.h

diceWar: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o DiceWar

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
