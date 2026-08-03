CC      = gcc
CFLAGS  = -O2 -Wall -Wno-format-truncation
LIBS    = -lSDL2 -lSDL2_image -lSDL2_ttf -lm
INCLUDES = -I/usr/include/SDL2

# Prefer pkg-config when available
PKG_CFLAGS := $(shell pkg-config --cflags sdl2 SDL2_image SDL2_ttf 2>/dev/null)
PKG_LIBS   := $(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf 2>/dev/null)

ifneq ($(PKG_LIBS),)
  CFLAGS  += $(PKG_CFLAGS)
  LIBS     = $(PKG_LIBS) -lm
  INCLUDES =
endif

TARGET = gaubarcade
SRC    = gaubarcade.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(LIBS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
