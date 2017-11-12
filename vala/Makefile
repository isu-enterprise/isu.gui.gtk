.PHONY: run build all

LIB_NAME=icc_gui
VALA_FLAGS=-X -fPIC -X -shared -o $(LIB_NAME).so
PACKAGES=--pkg=gtk+-3.0 --pkg=glib-2.0

all: build

run: build

test: build build-test
	./gui_test

build: $(LIB_NAME).vala
	valac --library $(LIB_NAME) -H $(LIB_NAME).h $< $(VALA_FLAGS) $(PACKAGES)

build-test:
