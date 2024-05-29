# Makefile for building the tiger compiler

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRCDIR = src
BUILDDIR = build
SRC_DIR = test
BUILD_DIR = build
FILES := $(wildcard $(SRC_DIR)/*.txt)
PNG_FILES := $(patsubst $(SRC_DIR)/%.txt, $(BUILD_DIR)/%_tree.png, $(FILES))

# Files
YACCFILE = tiger.y
LEXFILE = tiger.l

# Targets
all: $(BUILDDIR)/tiger

$(BUILDDIR)/tiger: $(BUILDDIR)/y.tab.c $(BUILDDIR)/lex.yy.c $(wildcard $(SRCDIR)/*.c)
	$(CC) $(CFLAGS) -o $@ -Iinclude $^

$(BUILDDIR)/y.tab.c: $(SRCDIR)/$(YACCFILE)
	bison -y -d -v -o $@ $<

$(BUILDDIR)/lex.yy.c: $(SRCDIR)/$(LEXFILE)
	flex -o $@ $<

# test 目标依赖于 tiger 和 PNG_FILES
test: $(BUILDDIR)/tiger $(PNG_FILES)

$(BUILD_DIR)/%_tree.png: $(SRC_DIR)/%.txt
	$(BUILDDIR)/tiger $<
	dot -Tpng tree.dot -o $@

clean:
	rm -f $(BUILDDIR)/tiger $(BUILDDIR)/y.tab.c $(BUILDDIR)/y.tab.h $(BUILDDIR)/y.output $(BUILDDIR)/lex.yy.c $(BUILD_DIR)/*_tree.png

.PHONY: all clean test
