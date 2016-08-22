CC=g++
CFLAGS=-Wall -std=c++11 -Ilib/jvisu/include -g
LINK=g++
LFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

SRC_FOLDER=src
BIN_FOLDER=bin
BUILD_FOLDER=build
EXE=exe

C_SOURCES=$(shell find $(SRC_FOLDER) -type f -iname '*.c')
CPP_SOURCES=$(shell find $(SRC_FOLDER) -type f -iname '*.cpp')
HEADERS=$(shell find $(SRC_FOLDER) -type f -iname '*.h')
OBJECTS=$(subst $(SRC_FOLDER),$(BIN_FOLDER),$(subst .c,.o,$(C_SOURCES)))
OBJECTS+= $(subst $(SRC_FOLDER),$(BIN_FOLDER),$(subst .cpp,.o,$(CPP_SOURCES)))

JVISU_LIB=lib/jvisu/lib/jvisu.a



$(BIN_FOLDER)/%.o : $(SRC_FOLDER)/%.c* $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


$(EXE): $(OBJECTS) $(JVISU_LIB)
	$(LINK) $^ $(LFLAGS) -o $@


.phony: run
run: $(EXE)
	./$(EXE)



.phony: build
build: $(EXE)
	rm -rf $(BUILD_FOLDER)/rectstack
	mkdir $(BUILD_FOLDER)/rectstack
	mv $(EXE) build/rectstack/rectstack
	cp -r assets $(BUILD_FOLDER)/rectstack/assets


.phony: clobber
clobber:
	rm -f $(BIN_FOLDER)/*.o
	rm -f $(EXE)
	rm -rf $(BUILD_FOLDER)/rectstack

.phony: test
test: 
	@echo $(SOURCES)
	@echo $(HEADERS)
	@echo $(OBJECTS)


#print number of lines
.phony: line_count
line_count:
	find src -name '*.cpp' -o -name '*.h' | xargs wc -l

