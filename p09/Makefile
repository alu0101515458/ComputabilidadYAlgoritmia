CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = Alphabet.cc Chain.cc ClientMain.cc State.cc Symbol.cc Tape.cc Tools.cc TuringMachine.cc
OBJ = $(SRC:.cc=.o)
EXEC = p09_turing_machine

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)