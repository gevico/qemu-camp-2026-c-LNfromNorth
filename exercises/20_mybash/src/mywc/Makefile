CC = gcc
CFLAGS = -Wall -I../../include -fPIC
LIBNAME := mywc
LIB := lib$(LIBNAME).a
OBJDIR ?= ./obj
LIB_PATH := $(OBJDIR)/$(LIB)
SRCS := mywc.c
OBJS := $(OBJDIR)/mywc.o

all: $(LIB_PATH)

$(LIB_PATH): $(OBJS)
	ar rcs $@ $^

$(OBJDIR)/mywc.o: mywc.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)/*.o $(LIB_PATH)
