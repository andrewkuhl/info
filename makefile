CC = g++
CFLAGS = -Wall
LDFLAGS =
OBJFILES = main.o util.o info.o
TARGET = run

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~