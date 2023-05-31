ifeq (,$(CROSS_COMPILE))
$(error missing CROSS_COMPILE for this toolchain)
endif

TARGET = splash

CC = $(CROSS_COMPILE)gcc

CFLAGS   = -Os -Wall -marm -march=armv7ve+simd -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard
CFLAGS  += -ffunction-sections -fdata-sections -Wl,--gc-sections -Wl,-s
LIBS     = -lSDL -lSDL_image

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) splash.c $(LIBS)

clean:
	rm -f $(TARGET)
