NAME	= gnl

NAME_BONUS	= bonus

FLAGS 	= -Wall -Werror -Wextra

SRCS 	= main.c get_next_line.c get_next_line_utils.c

SRCS_BONUS = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

$(NAME):
		cc $(FLAGS) $(SRCS) -o $(NAME)

all:		$(NAME) $(NAME_BONUS)

fclean:
		rm -rf $(NAME) $(NAME_BONUS)

re:		fclean all

bonus:
		cc $(FLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

n:
		norminette -R CheckForbiddenSourceHeader *.c *.h

.PHONY: all fclean re