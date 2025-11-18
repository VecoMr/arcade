.PHONY: all clean fclean re

all:
	@$(MAKE) -C ./src
	@$(MAKE) -C ./librairies

clean:
	@$(MAKE) -C ./librairies clean
	@$(MAKE) -C ./src clean

fclean:
	@$(MAKE) -C ./librairies fclean
	@$(MAKE) -C ./src fclean

re: fclean all

rej: fclean
	make -j 16

core:
	make -C ./src

games:
	make -C ./librairies/Games

graphicals:
	make -C ./librairies/Graphics
