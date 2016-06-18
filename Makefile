# Makefile for Linux, use V=1 get more information

SCRS	:= $(wildcard *.cc)
OBJS	:= $(SCRS:.cc=.o)

CFLAGS	:= $(shell sdl2-config --cflags) -std=c++11 \
	   -Wall -O2 -pipe -fomit-frame-pointer \
	   -Irapidjson/include \
	   $(EXTRA_CFLAGS)

LDFLAGS	:= -lSDL2 -lSDL2_mixer $(EXTRA_LDLAGS)

EXTRA_CFLAGS	:=
EXTRA_LDLAGS	:=

RM	:= @rm -f

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

.PHONY: all
all: rewrite

%.o: %.cc
	$(QCXX) $(CXX) $(CFLAGS) -c $< -o $@

rewrite: $(OBJS)
	$(QLD) $(CXX) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	@echo "  CLEAN   ."
	$(RM) $(OBJS) rewrite *.d

-include $(SCRS:.cc=.d)

%.d: %.cc
	@set -e; rm -f $@; \
	$(CXX) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
