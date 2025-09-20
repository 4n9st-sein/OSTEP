CC     = gcc
CFLAGS = -Wall
TARGET = a.out
SRCS   = 2.2.c
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
	-rm -f $(OBJS) $(TARGET) *.d