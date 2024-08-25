PHONY = all clean
CC = cl
FLAGS =
ifeq ($(CC), cl)
	OBJ_EXTENSION = .obj
else
	OBJ_EXTENSION = .o
endif

.SUFFIXES: .c $(OBJ_EXTENSION)
SRC_DIR = .
SRC = 	$(SRC_DIR)/write-xml.c \
		$(SRC_DIR)/preprocess.c \
		$(SRC_DIR)/brute-force-wifi.c \
		$(SRC_DIR)/list-wifi.c \
		$(SRC_DIR)/main.c

OBJ = $(SRC:.c=$(OBJ_EXTENSION))

all: $(OBJ)
	$(CC) $(FLAGS) $? -o brute-force-exe

%$(OBJ_EXTENSION): %.c
	$(CC) $(FLAGS) -c $*.c -o $*$(OBJ_EXTENSION)

clean: 
	rm -f *$(OBJ_EXTENSION) *.exe