CC := g++

CXXFLAGS := -Wall -Werror -fpic -I./../../../inc -lsfml-graphics -lsfml-window -lsfml-system

SRCS := $(wildcard *.cpp) $(wildcard ../abstract/*.cpp)

OBJS := $(SRCS:.cpp=.o)

LIBRARY := arcade_sfml.so

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
