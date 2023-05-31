
ARCH      = arm
CC        = $(CROSS_COMPILE)gcc
SYSROOT   = $(shell $(CC) --print-sysroot)

CFLAGS   += -Wall -Ofast -marm -march=armv7ve+simd -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard
CFLAGS   += -flto -fwhole-program -fuse-linker-plugin -ffunction-sections -fdata-sections
CFLAGS   += -fno-unwind-tables -fno-asynchronous-unwind-tables -Wl,-s -Wl,--gc-sections
CFLAGS   += -D_FILE_OFFSET_BITS=64

UNZ_OBJS = miniunz.o unzip.o ioapi.o
ZIP_OBJS = minizip.o zip.o   ioapi.o
LIBS     = -lz

.c.o:
	$(CC) -c $(CFLAGS) $*.c

all: miniunz minizip

miniunz:  $(UNZ_OBJS)
	$(CC) $(CFLAGS) -o $@ $(UNZ_OBJS) $(LIBS)

minizip:  $(ZIP_OBJS)
	$(CC) $(CFLAGS) -o $@ $(ZIP_OBJS) $(LIBS)

test:	miniunz minizip
	@rm -f test.*
	@echo hello hello hello > test.txt
	./minizip test test.txt
	./miniunz -l test.zip
	@mv test.txt test.old
	./miniunz test.zip
	@cmp test.txt test.old
	@rm -f test.*

clean:
	/bin/rm -f *.o *~ minizip miniunz test.*
