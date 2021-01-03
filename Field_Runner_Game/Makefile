CC := g++ -std=c++11
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: FieldRunners.out

FieldRunners.out: main.o Game.o GameWindow.o Glue.o Tesla.o Missile.o Gatling.o Tower.o rsdl.o EachRoom.o Enemy.o TheRunner.o Stubborn.o Scrambler.o Trooper.o
	$(CC) main.o GameWindow.o Game.o Glue.o Tesla.o Missile.o Gatling.o Tower.o rsdl.o EachRoom.o Enemy.o TheRunner.o Stubborn.o Scrambler.o Trooper.o $(CCFLAGS) -o FieldRunners.out

main.o: main.cpp rsdl.o Game.o GameWindow.o Glue.o Tesla.o Missile.o Gatling.o Tower.o Enemy.o TheRunner.o Stubborn.o Scrambler.o Trooper.o
	$(CC) -c main.cpp

Game.o: Game.cpp Game.h EachRoom.o rsdl.o Glue.o Tesla.o Missile.o Gatling.o Tower.o Enemy.o TheRunner.o Stubborn.o Scrambler.o Trooper.o
	$(CC) -c Game.cpp

GameWindow.o: GameWindow.cpp GameWindow.h EachRoom.o rsdl.o
	$(CC) -c GameWindow.cpp

EachRoom.o: EachRoom.cpp EachRoom.h Glue.o Tesla.o Missile.o Gatling.o Tower.o rsdl.o
	$(CC) -c EachRoom.cpp

Glue.o: Glue.cpp Glue.h Tower.o
	$(CC) -c Glue.cpp

Tesla.o: Tesla.cpp Tesla.h Tower.o
	$(CC) -c Tesla.cpp

Missile.o: Missile.cpp Missile.h Tower.o
	$(CC) -c Missile.cpp

Gatling.o: Gatling.cpp Gatling.h Tower.o
	$(CC) -c Gatling.cpp

Tower.o: Tower.cpp Tower.h rsdl.o
	$(CC) -c Tower.cpp

Trooper.o: Trooper.cpp Trooper.h Enemy.o rsdl.o
	$(CC) -c Trooper.cpp

Scrambler.o: Scrambler.cpp Scrambler.h Enemy.o rsdl.o
	$(CC) -c Scrambler.cpp

Stubborn.o: Stubborn.cpp Stubborn.h Enemy.o rsdl.o
	$(CC) -c Stubborn.cpp

TheRunner.o: TheRunner.cpp TheRunner.h Enemy.o rsdl.o
	$(CC) -c TheRunner.cpp

Enemy.o: Enemy.cpp Enemy.h rsdl.o
	$(CC) -c Enemy.cpp

rsdl.o: RSDL-master/src/rsdl.hpp RSDL-master/src/rsdl.cpp
	$(CC) -c RSDL-master/src/rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o
	rm FieldRunners.out


