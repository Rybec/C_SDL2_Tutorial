
all: test.exe render.exe

test.exe: test.c
	gcc test.c -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o test.exe

render.exe: render.c
	gcc render.c -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o render.exe
	
