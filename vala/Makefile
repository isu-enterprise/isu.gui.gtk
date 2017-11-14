.PHONY: run build all build-test build-c

LIB_NAME=icc_gui
VALA_FLAGS=-X -fPIC -X -shared -g
PACKAGES=--pkg=gtk+-3.0 --pkg=glib-2.0

SRC=$(LIB_NAME).vala

all: build build-c

run: build

test: build build-test
	./gui_test

build: $(SRC)
	valac --library $(LIB_NAME) -o $(LIB_NAME).so  -H $(LIB_NAME).h $< $(VALA_FLAGS) $(PACKAGES)

build-test:

build-c: $(SRC) build
	valac --library $(LIB_NAME) -H $(LIB_NAME).h -C $< $(PACKAGES)
