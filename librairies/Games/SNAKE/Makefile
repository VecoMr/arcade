CC := g++

CXXFLAGS := -Wall -Werror -fpic -I./../../../inc

SRCS := $(wildcard *.cpp) $(wildcard ../abstracts/*.cpp)

OBJS := $(SRCS:.cpp=.o)

LIBRARY := arcade_snake.so

all: $(LIBRARY)

%.o: %.c
	$(CC) $(CXXFLAGS) -c $< -o $@

$(LIBRARY): $(OBJS)
	$(CC) $(CXXFLAGS) -shared $(OBJS) -o $@
	cp $(LIBRARY) ../../../lib

clean:
	rm -f $(OBJS) $(LIBRARY)

fclean: clean
	rm -f ../../../lib/$(LIBRARY)

re: fclean all
