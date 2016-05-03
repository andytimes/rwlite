# Makefile for Linux, use V=1 get more information

CC	= gcc
CXX	= g++
LD	= $(CXX) -o

CFLAGS	:= -Wall -std=c++11 -O3 -march=native \
	   -fomit-frame-pointer -pipe \
	   $(EXTRA_CFLAGS)
CFLAGS	+= $(shell sdl2-config --cflags)
LDFLAGS	:= -lSDL2 -lSDL2_mixer
EXTRA_CFLAGS	:=

RM	= @rm -f

DEBUG = 0

ifeq ($(DEBUG), 1)
    CFLAGS	+= -DRWDEBUG
endif

ifndef V
	QCC	= @echo '  CC      ' $@;
	QCXX	= @echo '  CXX     ' $@;
	QLD	= @echo '  LD      ' $@;
	export V
endif

OBJECTS	= common.o cursor.o func.o main.o music.o print.o

.PHONY: all
all: rewrite

rewrite: $(OBJECTS) Makefile
	$(QLD) $(LD) rewrite $(OBJECTS) $(LDFLAGS)

common.o: common.cc cursor.h music.h print.h time.h Makefile
	$(QCXX) $(CXX) -c common.cc $(CFLAGS) -o common.o

cursor.o: cursor.cc cursor.h Makefile
	$(QCXX) $(CXX) -c cursor.cc $(CFLAGS) -o cursor.o

func.o: func.cc rewrite.h cursor.h print.h music.h Makefile
	$(QCXX) $(CXX) -c func.cc $(CFLAGS) -o func.o

main.o: main.cc rewrite.h Makefile
	$(QCXX) $(CXX) -c main.cc $(CFLAGS) -o main.o

music.o: music.cc Makefile
	$(QCXX) $(CXX) -c music.cc $(CFLAGS) -o music.o

print.o: print.cc print.h cursor.h time.h Makefile
	$(QCXX) $(CXX) -c print.cc $(CFLAGS) -o print.o

.PHONY: clean
clean:
	@echo '  CLEAN   .'
	$(RM) rewrite *.o
