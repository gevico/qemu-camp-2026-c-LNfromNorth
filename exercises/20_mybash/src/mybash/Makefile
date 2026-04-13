# src/mybash/Makefile

CC = gcc
CFLAGS = -Wall -I../../include

TARGET := mybash
BINDIR ?= ./bin
OBJDIR ?= ./obj
LINKLIBS ?= -L../../obj/mysed -lmysed -L../../obj/mywc -lmywc -L../../obj/mytrans -lmytrans -L../../obj/myfile -lmyfile

SRCS := main.c
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
TARGET_PATH := $(BINDIR)/$(TARGET)

all: $(TARGET_PATH)

$(TARGET_PATH): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LINKLIBS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -fPIE -c $< -o $@
clean:
	@rm -rf $(OBJDIR)/*.o $(TARGET_PATH)

