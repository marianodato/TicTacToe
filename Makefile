CC = gcc 
CFLAGS  = -g -Wall
TARGET = TicTacToe

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)