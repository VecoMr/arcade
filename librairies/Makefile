SUBDIRS := 	Graphics \
			Games

all:
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