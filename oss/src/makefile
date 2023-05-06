ifeq (,$(CROSS_COMPILE))
$(error missing CROSS_COMPILE for this toolchain)
endif

TARGET = oss

CC = $(CROSS_COMPILE)gcc
CFLAGS   = -Os -marm -march=armv7ve+simd -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard 
CFLAGS  += -Wall -ffunction-sections -fdata-sections -fmerge-all-constants -fno-stack-protector -fno-ident -fomit-frame-pointer  
CFLAGS  += -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-unroll-loops -fno-math-errno -ffast-math
LDFLAGS	 = -Wl,--gc-sections -s

all:
	$(CC) oss.c -o $(TARGET) $(CFLAGS) $(LDFLAGS)
clean:
	rm -f $(TARGET)
