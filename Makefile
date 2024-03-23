NAME = philosophers
HDR_DIR = includes
SRC_DIR = sources
CC = cc
CFLAGS = -I$(HDR_DIR) -g -pthread #-Wall -Wextra -Werror
LDFLAGS = -pthread
SRC = $(SRC_DIR)/main.c
HDR = $(HDR_DIR)
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re intro l newline backline emoticon

all: intro $(NAME) emoticon

l: $(NAME)

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(HDR)
	@echo "\033[0;32m compiling $(NAME) object $<...\033[0m" 🚀
	@$(CC) $(CFLAGS) $< -c -o $@

$(NAME) : $(OBJ) 
	@echo "\n\033[0;32m linking $(NAME) objects...\033[0m 🚀\n\n 💗 💎 💎 💗\n"
	@$(CC) $(OBJ) $(LDFLAGS) -o $@

emoticon:
	@echo "\n 💗 😀 😃 😍\n"

newline: 
	@echo ""

backline: 
	@echo "\033[A\033[A"

intro:
	clear
	@sleep 1
	@echo -n " Wake"
	@sleep .4
	@echo " up...\n"
	@sleep .1
	@echo -n " "
	@letters="The Makefile has you..."; \
	echo "\033[1;92m$$letters\033[0m" | awk '{split($$0, chars, ""); \
	for (i = 1; i <= length($$0); i++) \
	{printf "%s", chars[i]; system("sleep 0.2");}} \
	system("sleep 1");' 
	@words="\n\n\tFollow \n\t\tthe \t\b\b\033[0;96mColored! \
	\n\n\t\t\b\b\b\b\b\b\033[1;95mUnicorne!\033[0m...🦄\n\n"; \
	for j in $${words}; do \
		echo -n "$$j"; \
		sleep .4; \
	done
	@sleep .4
	@cat docs/mfile_design	

clean:
	@echo "\n cleanning $(NAME) objects 🧻"
	@rm -f $(OBJ) $(OBJ_BONUS);	
	@echo ""

fclean: 
	@echo "\n cleanning $(NAME) objects 🧻"
	@rm -f $(OBJ) $(OBJ_BONUS);
	@echo " cleanning $(NAME) 🚽" 
	@rm -f $(NAME) $(NAME_BONUS)	
	@echo ""

re: fclean backline l