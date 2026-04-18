# src/mybash/Makefile

CC = gcc
CFLAGS = -Wall -I../../include

TARGET := mybash
BINDIR ?= ./bin
OBJDIR ?= ./obj
LINKLIBS ?= -L../../obj/mysed -lmysed -L../../obj/mywc -lmywc -L../../obj/mytrans -lmytrans -L../../obj/myfile -lmyfile

SRCS := main.c
OBJS := $(OBJDIR)/main.o
TARGET_PATH := $(BINDIR)/$(TARGET)

all: $(TARGET_PATH)

$(TARGET_PATH): $(OBJS) Makefile
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -pie -fPIE $(OBJS) $(LINKLIBS) -o $@

$(OBJDIR)/main.o: main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -fPIE -c $< -o $@

clean:
	@rm -rf $(OBJDIR)/*.o $(TARGET_PATH)
