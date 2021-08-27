RAYLIB_PATH = C:/raylib/raylib
LIBRARY_PATHS = -L./lib
INCLUDE_PATHS = -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external
LIBRARIES = -lraylib -lopengl32 -lgdi32 -lwinmm

all: $(FILES)
	gcc $(wildcard ./src/*.c) $(wildcard ./src/*.h) $(LIBRARY_PATHS) $(INCLUDE_PATHS) $(LIBRARIES)