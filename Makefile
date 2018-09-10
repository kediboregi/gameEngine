DEP_PATH ?= C:\projeler\gameEngine\dependencies

BUILD_PATH = build\bin\windows\86
PROJECT_NAME ?= gameEngine


LIBRARY_PATHS = -L$(DEP_PATH)\SDL2-2.0.8\i686-w64-mingw32\lib -L$(DEP_PATH)\SDL2_image-2.0.3\i686-w64-mingw32\lib -L$(DEP_PATH)\SDL2_ttf-2.0.14\i686-w64-mingw32\lib
INCLUDE_PATHS = -I$(DEP_PATH)\SDL2-2.0.8\i686-w64-mingw32\include\SDL2 -I$(DEP_PATH)\SDL2_image-2.0.3\i686-w64-mingw32\include\SDL2 -I$(DEP_PATH)\SDL2_ttf-2.0.14\i686-w64-mingw32\include\SDL2

COMPILER_FLAGS = -O3 -std=c++11 -Dmain=SDL_main
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows

CC = g++

MAKE = mingw32-make

# Define all source files required
#PROJECT_SOURCE_FILES = $(wildcard *.cpp) $(wildcard */*.cpp)
#PROJECT_SOURCE_FILES ?= src/main.cpp src/App.cpp src/App.cpp
PROJECT_SOURCE_FILES = $(wildcard src/*/*/*.c) \
		$(wildcard src/*/*.c) \
		$(wildcard src/*.c)
       #$(wildcard src/component/*.c) \
       #$(wildcard src/manager/*.c) \
       #$(wildcard src/math/*.c) \
       #$(wildcard src/states/*.c) \

# Define all object files from source files
#OBJS = $(patsubst %.cpp, %.o, $(PROJECT_SOURCE_FILES))
OBJS = $(PROJECT_SOURCE_FILES:.c=.o)

#$(info VAR is $(OBJS))

all:
	$(MAKE) $(PROJECT_NAME)

# Project target defined by PROJECT_NAME
$(PROJECT_NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BUILD_PATH)\$(PROJECT_NAME)



# Compile source files
# NOTE: This pattern will compile every module defined on $(OBJS)
%.o: %.c
	$(CC) -c $< -o $@ $(COMPILER_FLAGS) $(INCLUDE_PATHS)

clean:
	del src\*.o
	del src\math\*.o
	del src\manager\*.o
	del src\entity\*.o
	del src\entity\component\*.o
	del src\states\*.o
	del src\system\*.o
