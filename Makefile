CC = gcc


SRC_DIR = src
TARGET = $(SRC_DIR)/main


SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/car.c

all: $(TARGET)

$(TARGET): $(SOURCES:.c=.o)
	$(CC) -o $@ $^

%.o: %.c $(SRC_DIR)/car.h
	$(CC) -c $< -o $@


run: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

.PHONY: all run clean
