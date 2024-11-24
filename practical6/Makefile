CC = gcc
CFLAGS = -O3
LDFLAGS = -lm

TARGET = matmult

all: $(TARGET)

$(TARGET): main.o matmult.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) -c $(CFLAGS) $<

matmult.o: matmult.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f *.o $(TARGET)
