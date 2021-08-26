CC			:= gcc

CFLAGS		:= -Wall -Werror -Wextra -D BUFFER_SIZE=4

SRC			:= 	get_next_line.c /

OBJ			:= $(SRC:.c=.o)

all:
	gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out

%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

run:
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 get_next_line.c get_next_line_utils.c main.c && ./a.out

valgrind:
	gcc get_next_line.c get_next_line_utils.c main.c
	valgrind ./a.out
gdb:
	gcc -g get_next_line.c get_next_line_utils.c main.c
	gdb ./a.out
	start
	tui enable

test:
	make -C ./gnlTester

