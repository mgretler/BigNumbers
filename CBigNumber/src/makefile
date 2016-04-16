CC = g++
OBJECTS = BigNumberTest.o CBigNumber.o
LIBS = -lcurl
CFLAGS = -Wall -O2
BINDIR = $(DESTDIR)/usr/bin
NAME = BigNumberTest

BigNumberTest: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

install:
	#install --mode=755 $(NAME) $(BINDIR)/

clean:
	rm *.o $(NAME)

uninstall:
	#rm $(BINDIR)/$(NAME)