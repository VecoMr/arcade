CC := g++

CXXFLAGS := -Wall -Werror -fpic -I./../../../inc -lSDL2 -lSDL2_image -lSDL2_ttf

SRCS := $(wildcard *.cpp)

OBJS := $(SRCS:.cpp=.o)

LIBRARY := arcade_sdl2.so

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
