progc = combat.c deplacement.c invetory.c spells.c main.c
progh = combat.h deplacement.h invetory.h spells.h structures.h

all: test_combat test_deplacement clean

test_combat: combat.o deplacement.o inventory.o spells.o test_combat.o
	gcc $^ -o $@ 
	
test_deplacement: combat.o deplacement.o inventory.o spells.o test_deplacement.o
	gcc $^ -o $@ 
	
%.o: %.c $(progh)
	gcc -c $< -o $@ -lm
	
clean:
	rm -f *.o
