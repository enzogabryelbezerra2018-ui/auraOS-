CXX=g++
CXXFLAGS=-O2 -std=c++17

SRC=src/main.cpp src/terminal_logic.cpp
OBJ=$(SRC:.cpp=.o)
OUT=terminal

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)
