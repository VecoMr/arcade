CC := g++

CXXFLAGS := -Wall -Werror -fpic -I./../../../inc -I./Snake

SRCS := $(wildcard *.cpp) $(wildcard ../abstracts/*.cpp) $(wildcard Snake/*.cpp)

OBJS := $(SRCS:.cpp=.o)

LIBRARY := arcade_nibbler.so

all: $(LIBRARY)

links:
	ln -sf $(realpath ../SNAKE/Snake.hpp) ./Snake
	ln -sf $(realpath ../SNAKE/Snake.cpp) ./Snake
	ln -sf $(realpath ../SNAKE/Movement.cpp) ./Snake
	ln -sf $(realpath ../SNAKE/Event.cpp) ./Snake
	ln -sf $(realpath ../SNAKE/Map.cpp) ./Snake

%.o: %.c
	$(CC) $(CXXFLAGS) -c $< -o $@

$(LIBRARY): links $(OBJS)
	$(CC) $(CXXFLAGS) -shared $(OBJS) -o $@
	cp $(LIBRARY) ../../../lib

clean:
	rm -f $(OBJS) $(LIBRARY)

fclean: clean
	rm -f ../../../lib/$(LIBRARY)

re: fclean all
