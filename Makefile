CC = gcc
CFLAGS = -g -Wall

PREFIX ?= /usr/local
BINDIR = ${PREFIX}/bin

objects = microbat 

all: $(objects)
$(objects): %: %.c
	$(CC) $(CFLAGS) $< -o $@

install:
	install -d ${BINDIR}
	install -m 755 $(objects) ${BINDIR}

uninstall:
	rm ${BINDIR}/$(objects)

clean:
	rm $(objects)
