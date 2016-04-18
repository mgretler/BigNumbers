CC = g++
SOURCES = CBigNumber.cpp BigNumberTest.cpp
OBJECTS = $(SOURCES:.cpp=.o)
LIBS = 
CFLAGS = -Wall -O2
LDFLAGS = 
BINDIR = $(DESTDIR)/usr/bin
NAME = BigNumberTest

all: $(SOURCES) $(NAME)


$(NAME): $(OBJECTS)

	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

#%.o: %.c
#	$(CC) -c $(CFLAGS) $<

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

install:
	#install --mode=755 $(NAME) $(BINDIR)/

clean:
	- rm *.o $(NAME)

uninstall:
	#rm $(BINDIR)/$(NAME)