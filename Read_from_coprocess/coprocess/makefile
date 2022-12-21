CC := g++
CFLAGS := -c -g -O0 -Wall -Wextra
LDFLAGS :=
SRCPATH := ./
search_wildcard := $(addsuffix /*.cpp, $(SRCPATH))
SOURCES := $(wildcard $(search_wildcard))
OBJECTPATH := ./obj
OBJECTS := $(patsubst $(SRCPATH)/%.cpp, $(OBJECTPATH)/%.o, ${SOURCES})
BUILDPATH := ./build
EXECUTABLE := coprocess.exe

.PHONY: all clean

all: $(BUILDPATH)/$(EXECUTABLE)

$(BUILDPATH)/$(EXECUTABLE): $(OBJECTS)
	@echo [Linking:] $@
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJECTS): $(OBJECTPATH)/%.o: $(SRCPATH)/%.cpp
	@echo [Compiling:] $@
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(BUILDPATH)/$(EXECUTABLE) $(OBJECTPATH)/*.o
	rm -rf $(EXECUTABLE)
