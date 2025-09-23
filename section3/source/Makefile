CC     = gcc
CFLAGS = -Wall
TARGET = a.out
SRCS   = 5.3.c
OBJS   = $(SRCS:.c=.o)
LINCDIR = -I../inc
LIBDIR =
LIBS   =

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(LINCDIR) -c $< -o $@

all: $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d *.o