CC = cc
FLAGS = -O3

all: write-xml.o preprocess.o brute-force-wifi.o list-wifi.o main.o
	$(CC) $(FLAGS) $? -o brute-force-exe

write-xml.o: write-xml.c
	$(CC) $(FLAGS) -c $? -o $@

preprocess.o: preprocess.c
	$(CC) $(FLAGS) -c $? -o $@

brute-force-wifi.o: brute-force-wifi.c
	$(CC) $(FLAGS) -c $? -o $@

list-wifi-type.o: list-wifi-type.c
	$(CC) $(FLAGS) -c $? -o $@

list-wifi.o: list-wifi.c
	$(CC) $(FLAGS) -c $? -o $@

main.o: main.c
	$(CC) $(FLAGS) -c $? -o $@

clean: write-xml.o preprocess.o brute-force-wifi.o list-wifi.o main.o
	rm -f $?