CXX = g++
CXXFLAGS = -Iinclude -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = src/main.cpp \
      src/BaseWeapon.cpp \
      src/BaseAnimal.cpp \
      src/BaseHunter.cpp \
      src/Engine.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = hunter

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)