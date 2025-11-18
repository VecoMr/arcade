SUBDIRS :=	SNAKE 	\
			NIBBLER

all:
	ln -sf $(realpath ../../src/abstracts/ATexture.cpp) ./abstracts/ATexture.cpp
	ln -sf $(realpath ../../src/abstracts/ARect.cpp) ./abstracts/ARect.cpp
	ln -sf $(realpath ../../src/abstracts/ASprite.cpp) ./abstracts/ASprite.cpp
	ln -sf $(realpath ../../src/abstracts/AGrid.cpp) ./abstracts/AGrid.cpp
	ln -sf $(realpath ../../src/abstracts/AText.cpp) ./abstracts/AText.cpp
	ln -sf $(realpath ../../src/abstracts/ABanner.cpp) ./abstracts/ABanner.cpp
	mkdir -p ../../lib
	@for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir; \
    done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir fclean; \
    done

re:
	@for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir re; \
    done

.PHONY: all clean fclean re