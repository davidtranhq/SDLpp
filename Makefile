#OBJS specifies which files to compile as part of the project 
OBJS = SDLpp.o SDLpp_window.o SDLpp_surface.o SDLpp_texture.o SDLpp_renderer.o SDLpp_font.o SDLpp_timer.o

#CC specifies which compiler we're using 
CC = g++ 

#INCLUDE_PATHS specifies the additional include paths we'll need 
INCLUDE_PATHS = -IC:\mingw_dev_lib\include\SDL2 \
				-IC:\mingw_dev_lib\include\SDL_image \
				-IC:\mingw_dev_lib\include\SDLpp \
				-IC:\mingw_dev_lib\include\SDL_ttf

#LIBRARY_PATHS specifies the additional library paths we'll need 
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
# -Wall includes all warnings
# -Wl,-subsystem,windows gets rid of the console window 
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

#LIB_NAME specifies the name of our library 
LIB_NAME = libSDLpp.a

#FINAL_PATH specifies the final path of the library
FINAL_PATH = C:\mingw_dev_lib\lib

#This is the target that compiles our executable 

.PHONY : clean move full

all : $(OBJS)
	ar rvs $(LIB_NAME) $(OBJS)

%.o : %.cpp
	$(CC) $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -c $(LINKER_FLAGS) -o $@
	
clean :
	del *.o /Q
	
move:
	cmd /c move $(LIB_NAME) $(FINAL_PATH)
	
full : all clean move