# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mjiam <mjiam@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/23 13:52:25 by mjiam         #+#    #+#                  #
#    Updated: 2020/08/31 12:29:26 by mjiam         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a

SRC_A	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

SRC_B	= bonus/ft_atoi_base.s

TEST	= test

MAIN 	= testmain.c bonus_testmain.c

ifdef WITH_BONUS
OBJ		= $(SRC_A:.s=.o) $(SRC_B:.s=.o)
else
OBJ		= $(SRC_A:.s=.o)
endif

NSM		= nasm -f macho64

FLAGS	= -Wall -Wextra -Werror 

# COLORS
BLUE	= 	\033[38;5;27m
CYAN	= 	\033[38;5;51m
PINK	=	\033[38;5;211m
TURQ	= 	\033[38;5;37m
WHITE	= 	\033[38;5;15m
YELLOW	= 	\033[38;5;220m
RES		=	\033[0m
LBOR	=	"▌│█║▌║▌║ "
RBOR	= 	" ║▌║▌║█│▌"

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\t   $(CYAN)$(LBOR)Linking library$(RBOR)$(RES)\n"
	@ar rc $@ $^
	@ranlib $@

%.o: %.s
	@echo "\n\t   $(BLUE)$(LBOR)Compiling: $<$(RBOR)$(RES)\n"
	@$(NSM) $<

bonus: $(SRC_B)
	@echo "\n\t   $(PINK)$(LBOR)Compiling bonus files$(RBOR)$(RES)\n"
	@$(MAKE) WITH_BONUS=1 all
	@$(MAKE) test

test: $(MAIN) $(NAME)
	@echo "\n\t   $(TURQ)$(LBOR)Compiling test$(RBOR)\n"
	@gcc $(FLAGS) -L. -lasm -lc -o $(TEST) $(MAIN)
	@echo ""
	@echo "      *~*~*~*~*~* libasm test commands *~*~*~*~*~"
	@echo "      |                                          |"
	@echo "      |             ./test strlen                |"
	@echo "      |             ./test strcpy                |"
	@echo "      |             ./test strcmp                |"
	@echo "      |              ./test write                |"
	@echo "      |              ./test read                 |"
	@echo "      |             ./test strdup                |"
	@echo "      |              ./test atoi                 |"
	@echo "      |                                          |"
	@echo "      ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"
	@echo "$(RES)"

clean:
	@echo "\n\t   $(YELLOW)$(LBOR)Cleaning$(RBOR)$(RES)\n"
	@rm -rf $(SRC_A:.s=.o) $(SRC_B:.s=.o)

fclean: clean
	@echo "\n\t   $(RES)$(LBOR)Clean af$(RBOR)$(RES)\n"
	@rm -rf $(NAME) text test read.txt

re:
	@echo "\n\t   $(BLUE)$(LBOR)Aww here we go again$(RBOR)$(RES)\n"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re test bonus