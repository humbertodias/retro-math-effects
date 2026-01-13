SUBDIRS := $(wildcard */)

.PHONY: all $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	@echo "Building in $@"
	@cd $@ && cc main.c -o main `pkg-config sdl2 --libs --cflags`

clean:
	find . -type f -name 'main' -delete