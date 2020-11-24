CC = g++
EXEC = main
FLAGS = -Wall -Werror -pedantic
STD = -std=c++17
O = obj/Debug
B = bin/Debug

all: $(O) $(B) $(O)/main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(FLAGS)

$(O)/main.o: $(O)/Game.o $(O)/Perso.o $(O)/Guerrier.o $(O)/Mage.o $(O)/Objet.o $(O)/Arme.o $(O)/Epee.o $(O)/Baguette.o $(O)/ListeAdapt.o $(O)/ListeAdaptMaillon.o $(O)/Mob.o
	$(CC) main.cpp -c -o $(O)/main.o $(STD) $(FLAGS)

$(O)/ListeAdapt.o:
	$(CC) ListeAdapt.cpp -c -o $(O)/ListeAdapt.o $(STD) $(FLAGS)

$(O)/ListeAdaptMaillon.o:
	$(CC) ListeAdaptMaillon.cpp -c -o $(O)/ListeAdaptMaillon.o $(STD) $(FLAGS)

$(O)/Arme.o: $(O)/Objet.o
	$(CC) Arme.cpp -c -o $(O)/Arme.o $(STD) $(FLAGS)

$(O)/Baguette.o: $(O)/Arme.o
	$(CC) Baguette.cpp -c -o $(O)/Baguette.o $(STD) $(FLAGS)

$(O)/Epee.o: $(O)/Arme.o
	$(CC) Epee.cpp -c -o $(O)/Epee.o $(STD) $(FLAGS)

$(O)/Perso.o: $(O)/Arme.o
	$(CC) Perso.cpp -c -o $(O)/Perso.o $(STD) $(FLAGS)

$(O)/Guerrier.o: $(O)/Perso.o $(O)/Arme.o
	$(CC) Guerrier.cpp -c -o $(O)/Guerrier.o $(STD) $(FLAGS)

$(O)/Mage.o: $(O)/Perso.o $(O)/Arme.o
	$(CC) Mage.cpp -c -o $(O)/Mage.o $(STD) $(FLAGS)

$(O)/Mob.o: $(O)/Perso.o
	$(CC) Mob.cpp -c -o $(O)/Mob.o $(STD) $(FLAGS)

$(O)/Objet.o: 
	$(CC) Objet.cpp -c -o $(O)/Objet.o $(STD) $(FLAGS)

$(O)/Game.o: $(O)/Perso.o $(O)/ListeAdapt.o
	$(CC) Game.cpp -c -o $(O)/Game.o $(STD) $(FLAGS)

clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)