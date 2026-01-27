CC ?= gcc
CFLAGS ?= -Wall
CURDIR = $(shell pwd)
SOURCES := array.c array.h
BUILDDIR := $(CURDIR)/build/
OUT := $(BUILDDIR)/exe

all: $(OUT)

$(OUT): $(SOURCES)
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	- rm -rf $(CURDIR)/build