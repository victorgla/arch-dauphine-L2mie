CC = gcc
DEBUG=yes
ifeq ($(DEBUG),yes)
	CCFLAGS = -g -lm -Iinclude
else
	CCFLAGS = -Wall 
endif
LDFLAGS =  
OBJDIR = objet
DIR = ./  
SRC = $(foreach dir, $(DIR), $(wildcard $(dir)/*.c))
//OBJ = $(SRC:%.c=%.o)
LIB = $(wildcard include/*.h) 
EXEC = test

all: $(EXEC)  $(OBJDIR)

$(OBJDIR): 
	mkdir $(OBJDIR)

$(OBJDIR)/%o:%.c
	$(CC) $(CCFLAGS) -c -o $@ $< 

$(EXEC): $(SRC)
	$(CC) -o $@ $^ $(LDFLAGS) $(CCFLAGS) -iquote include


.PHONY: clean mrproper

clean:
	$(foreach dir, $(DIR), rm -rf $(wildcard $(dir)/*.o))

mrproper:
	rm -rf $(EXEC)
