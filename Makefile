# Makefile for Linux GCC, use V=1 get more information

CC	= gcc
LD	= gcc -o
CFLAGS	:= -Wall -fomit-frame-pointer -std=c11 -O3 -pipe \
	   -ffast-math $(EXTRA_CFLAGS)
CFLAGS	+= `sdl2-config --cflags`
LDFLAGS	:= `sdl2-config --libs` -lSDL2_mixer
EXTRA_CFLAGS	:=

RM	= rm -f

ifndef V
	CCQUIET	= @echo '  CC     ' $@;
	LDQUIET	= @echo '  LD     ' $@;
	export V
endif

rewrite: main.o common.o func.o Makefile
	$(LDQUIET) $(LD) rewrite main.o common.o func.o $(LDFLAGS)

main.o: main.c rewrite.h Makefile
	$(CCQUIET) $(CC) -c main.c $(CFLAGS) -o main.o

common.o: common.c rewrite.h cursor.h Makefile
	$(CCQUIET) $(CC) -c common.c $(CFLAGS) -o common.o

func.o: func.c rewrite.h cursor.h Makefile
	$(CCQUIET) $(CC) -c func.c $(CFLAGS) -o func.o

.PHONY: clean
clean:
	$(RM) rewrite *.o
