C_SRC = $(wildcard *.c)
C_TAR = $(patsubst %.c, %, $(C_SRC))

CPP_SRC = $(wildcard *.cpp)
CPP_TAR = $(patsubst %.cpp, %, $(CPP_SRC))

CC = gcc
CPP = g++ -std=c++11
RM = rm -f 

CFLAGS = -Wall -g  
LDFLAGS = -lpthread -lrt

all:$(C_TAR) $(CPP_TAR)

$(C_TAR):%:%.c
	$(CC) $(CFLAGS) $^ -o $@

$(CPP_TAR):%:%.cpp
	$(CPP) $(CFLAGS) $^ -o $@ $(LDFLAGS) 

.PHONY: all clean

clean:
	$(RM) *~ $(C_TAR) $(CPP_TAR)
