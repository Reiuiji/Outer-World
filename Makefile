WORKDIR = `pwd`
NAME = Test
CXX = g++
LD = g++

CFLAGS =  -Wall

DIR = src

LIBDIR = 
LIB = -l ncurses -l menu
LDFLAGS = 

CFLAGS_DEBUG =  $(CFLAGS) -g
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG =  $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
OUT_DEBUG = bin/Debug/$(NAME)

CFLAGS_RELEASE =  $(CFLAGS) -O2
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE =  $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
OUT_RELEASE = bin/Release/$(NAME)

OBJ_DEBUG = $(OBJDIR_DEBUG)menu.o $(OBJDIR_DEBUG)main.o $(OBJDIR_DEBUG)items.o $(OBJDIR_DEBUG)Player.o $(OBJDIR_DEBUG)Definition.o $(OBJDIR_DEBUG)Generator.o $(OBJDIR_DEBUG)Game.o $(OBJDIR_DEBUG)Enemy.o $(OBJDIR_DEBUG)Display.o

OBJ_RELEASE = $(OBJDIR_RELEASE)menu.o $(OBJDIR_RELEASE)main.o $(OBJDIR_RELEASE)items.o $(OBJDIR_RELEASE)Player.o $(OBJDIR_RELEASE)Definition.o $(OBJDIR_RELEASE)Generator.o $(OBJDIR_RELEASE)Game.o $(OBJDIR_RELEASE)Enemy.o $(OBJDIR_RELEASE)Display.o

all: debug 
#release

clean: clean_debug 
#clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)menu.o: menu.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Menu.cpp -o $(OBJDIR_DEBUG)menu.o

$(OBJDIR_DEBUG)main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Main.cpp -o $(OBJDIR_DEBUG)main.o

$(OBJDIR_DEBUG)items.o: items.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Items.cpp -o $(OBJDIR_DEBUG)items.o

$(OBJDIR_DEBUG)Player.o: Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Player.cpp -o $(OBJDIR_DEBUG)Player.o

$(OBJDIR_DEBUG)Definition.o: Definition.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Definition.cpp -o $(OBJDIR_DEBUG)Definition.o

$(OBJDIR_DEBUG)Generator.o: Generator.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Generator.cpp -o $(OBJDIR_DEBUG)Generator.o

$(OBJDIR_DEBUG)Game.o: Game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Game.cpp -o $(OBJDIR_DEBUG)Game.o

$(OBJDIR_DEBUG)Enemy.o: Enemy.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Enemy.cpp -o $(OBJDIR_DEBUG)Enemy.o

$(OBJDIR_DEBUG)Display.o: Display.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(DIR)Display.cpp -o $(OBJDIR_DEBUG)Display.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) 
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)menu.o: menu.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Menu.cpp -o $(OBJDIR_RELEASE)menu.o

$(OBJDIR_RELEASE)main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Main.cpp -o $(OBJDIR_RELEASE)main.o

$(OBJDIR_RELEASE)items.o: items.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Items.cpp -o $(OBJDIR_RELEASE)items.o

$(OBJDIR_RELEASE)Player.o: Player.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Player.cpp -o $(OBJDIR_RELEASE)Player.o

$(OBJDIR_RELEASE)Definition.o: Definition.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Definition.cpp -o $(OBJDIR_RELEASE)Definition.o

$(OBJDIR_RELEASE)Generator.o: Generator.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Generator.cpp -o $(OBJDIR_RELEASE)Generator.o

$(OBJDIR_RELEASE)Game.o: Game.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Game.cpp -o $(OBJDIR_RELEASE)Game.o

$(OBJDIR_RELEASE)Enemy.o: Enemy.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Enemy.cpp -o $(OBJDIR_RELEASE)Enemy.o

$(OBJDIR_RELEASE)Display.o: Display.cpp
	$(CXX) $(CFLAGS_RELEASE) -c $(DIR)Display.cpp -o $(OBJDIR_RELEASE)Display.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)
