progc = combat.c deplacement.c invetory.c spells.c main.c
progh = combat.h deplacement.h invetory.h spells.h structures.h

all: clean prog

prog: combat.o deplacement.o inventory.o spells.o main.o
	gcc $^ -o $@ 
	
%.o: %.c $(progh)
	gcc -c $< -o $@ -lm
	
clean:
	rm -f *.o
