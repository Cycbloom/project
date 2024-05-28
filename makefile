# Makefile for building the tiger compiler

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRCDIR = src
BUILDDIR = build

# Files
YACCFILE = tiger.y
LEXFILE = tiger.l
ASTFILE = ast.c
UTILFILE = util.c

# Targets
all: $(BUILDDIR)/tiger

$(BUILDDIR)/tiger: $(BUILDDIR)/y.tab.c $(BUILDDIR)/lex.yy.c $(SRCDIR)/$(ASTFILE) $(SRCDIR)/$(UTILFILE)
	$(CC) $(CFLAGS) -o $@ -Iinclude $^

$(BUILDDIR)/y.tab.c: $(SRCDIR)/$(YACCFILE)
	bison --yacc -dv -o $@ $<

$(BUILDDIR)/lex.yy.c: $(SRCDIR)/$(LEXFILE)
	flex -o $@ $<

clean:
	rm -f $(BUILDDIR)/tiger $(BUILDDIR)/y.tab.c $(BUILDDIR)/y.tab.h $(BUILDDIR)/y.output $(BUILDDIR)/lex.yy.c

.PHONY: all clean
