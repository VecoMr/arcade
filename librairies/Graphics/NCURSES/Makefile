CC := g++

CXXFLAGS := -Wall -Werror -fpic -I./../../../inc -lncurses -g3

SRCS := $(wildcard *.cpp)

OBJS := $(SRCS:.cpp=.o)

LIBRARY := arcade_ncurses.so

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
