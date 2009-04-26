## Makefile for mcmc
## 
## You can call it like this if you have segfaults
##  $ LD_PRELOAD=libduma.so.0.0.0 CCFLAGS="-DDEBUG -DSEGV" make tests
## 
## You might want to compile your gsl with -DHAVE_INLINE 
## 

CFLAGS=-O3 -Wall -Werror -Wextra -g -ansi -pedantic ${CCFLAGS}
LDFLAGS=-lgsl -lgslcblas -lm
CC=gcc
COMMON_SOURCES=gsl_helper.c debug.c

help:
	@grep -E '^## ' Makefile|grep -v ':'|sed 's,^## ,,g'
	@echo This Makefile has the targets:
	@grep -E '^## [.a-z]{2,}:' Makefile|sed 's,^## *,\t,g' |sed 's,: ,\t,g'

## all: 
all: tools 

tools: polynom_climber.exe generic_climber.exe example_climber.exe 

%.exe: %.c $(COMMON_SOURCES)
	$(CC) -I src $(CFLAGS) $(LDFLAGS) $^ -o $@

## clean: 
clean:
	rm -f *.exe *.o

.PHONY: clean all help tools
