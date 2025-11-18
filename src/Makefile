##
## EPITECH PROJECT, 2024
## arcade
## File description:
## Makefile
##

CXX := g++

CXXFLAGS := -std=c++20 -Wall -Wextra -I../inc -I./Core -I./Menu -I./Settings -g3

SRCS := $(wildcard *.cpp) $(wildcard Core/*.cpp) $(wildcard Menu/*.cpp) $(wildcard Settings/*.cpp) $(wildcard tools/*.cpp) $(wildcard abstracts/*.cpp)

OBJS := $(SRCS:.cpp=.o)

NAME := arcade

all: $(NAME)
	cp $(NAME) ../

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all