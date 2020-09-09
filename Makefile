MKDIR   := mkdir -p
RMDIR   := rm -rf
CC      := g++
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.cpp)
OBJS    := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))
EXE     := $(BIN)/mmxpd
CFLAGS  := -I$(INCLUDE)

.PHONY: all run clean

all: $(EXE)

$(EXE): $(OBJS) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	$(MKDIR) $@

run: $(EXE)
	$<

clean:
	$(RMDIR) $(OBJ) $(BIN)