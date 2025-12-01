NAME = libasm.a

SRC = ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s \
	ft_write.s \
	ft_read.s \
	ft_strdup.s

OBJ = $(SRC:.s=.o)

NASM = nasm
NASMFLAGS = -f elf64 

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating librairie $(NAME)..."
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

test: all
	@echo "Compilation of test program..."
	@gcc -Wall -Wextra -Werror -fPIE -pie main.c libasm.a -o test_libasm
	@echo "Executing ./test_libasm :"
	@./test_libasm

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ)

fclean: clean
	@echo "Deleting Librairie $(NAME)..."
	rm -f $(NAME)
	@echo "Deleting test executable file..."
	rm -f test_libasm

re: fclean all

.PHONY: all clean fclean re