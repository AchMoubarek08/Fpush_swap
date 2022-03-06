SRC =	atoi.c \
		instructions.c Push_swap.c \
		utils.c 

OBJ =	atoi.o \
		instructions.o Push_swap.o \
		utils.o 

CC = gcc -c

NAME = push_swap.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(SRC)
	ar rc $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all