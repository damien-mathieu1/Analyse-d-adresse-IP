all: main	

main: main.c calculatrice.o extraireChamp.o conversionValeur.o classeIP.o typeAdresse.o
	gcc main.c -o main.exe

lecture.o: lecture.c lecture.h
	gcc -c lecture.c

extraireChamp.o: extraireChamp.c extraireChamp.h
	gcc -c extraireChamp.c

conversionValeur.o: conversionValeur.c conversionValeur.h
	gcc -c conversionValeur.c

classeIP.o: classeIP.c classeIP.h
	gcc -c classeIP.c

typeAdresse.o: typeAdresse.c typeAdresse.h
	gcc -c typeAdresse.c