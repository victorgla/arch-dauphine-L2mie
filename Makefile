CXX = gcc
DEBUG=yes
ifeq ($(DEBUG),yes)
	CXXFLAGS = -Wall -g 
else
	CXXFLAGS = -Wall 
endif
LDFLAGS = 
OBJDIR = objet
DIR = ./  
SRC = $(foreach dir, $(DIR), $(wildcard $(dir)/*.c))
OBJ = $(SRC:%.c=%.o)
LIB = $(wildcard include/*.h) 
EXEC = TP7

all: $(EXEC)  $(OBJDIR)

$(OBJDIR): 
	mkdir $(OBJDIR)

$(OBJDIR)/%o:%.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)


.PHONY: clean mrproper

clean:
	$(foreach dir, $(DIR), rm -rf $(wildcard $(dir)/*.o))

mrproper:
	rm -rf $(EXEC)
