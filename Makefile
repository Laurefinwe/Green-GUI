CC = gcc

CFLAGS = -c -g -std=c99 -Wall
LDFLAGS = -lSDL -lSDL_ttf
HEADERS = button.h label.h check.h surface.h
SOURCES = button.c label.c check.c surface.c
OBJECTS = $(SOURCES:.c=.o)
STFLAGS = -rcs
STATIC = libgreen.a

object: $(SOURCES) 
	$(CC) $(CFLAGS) $^

$(STATIC): $(OBJECTS)
	ar $(STFLAGS) $@ $^

clear:
	rm *.o *.a *.so
