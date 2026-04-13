CC = gcc
CFLAGS = -Wall -I../../include -fPIC
LIBNAME := mytrans
LIB := lib$(LIBNAME).a
OBJDIR ?= ./obj
LIB_PATH := $(OBJDIR)/$(LIB)
SRCS := mytrans.c myhash.c
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

all: $(LIB_PATH)

$(LIB_PATH): $(OBJS)
	ar rcs $@ $^

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)/*.o $(LIB_PATH)
