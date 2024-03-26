NAME = philosophers
X_HDR_DIR = x_includes
HDR_DIR = includes
SRC_DIR = sources
CC = cc
THREAD =

CFLAGS = $(X_HDRFLAGS) $(HDRFLAGS) $(THREAD) -g #-Wall -Wextra -Werror
LDFLAGS = $(THREAD)

X_HDRFLAGS = -I$(X_HDR_DIR)/error_zone \
	-I$(X_HDR_DIR)/philo_utils

X_HDR = $(X_HDR_DIR)/error_zone/x_error_utils.h \
	$(X_HDR_DIR)/philo_utils/x_philo_utils.h

HDRFLAGS = -I$(HDR_DIR)/error_zone \
	-I$(HDR_DIR)/philo_utils

HDR = $(HDR_DIR)/error_zone/error_utils.h \
	$(HDR_DIR)/error_zone/check_argv.h \
	$(HDR_DIR)/philo_utils/philo_utils.h \
	$(HDR_DIR)/philo_utils/ft_calloc.h

OBJ = $(SRC:.c=.o)
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/error_zone/check_argv.c \
	$(SRC_DIR)/error_zone/error_utils.c \
	$(SRC_DIR)/exit_area/exit.c \
	$(SRC_DIR)/philo_utils/philo_utils.c \
	$(SRC_DIR)/philo_utils/ft_calloc.c \

.PHONY: all clean fclean re intro l newline backline emoticon address

#all: intro $(NAME) emoticon

all: $(NAME)

address:
	@$(MAKE) -s l THREAD="-pthread -fsanitize=address"

thread:
	@$(MAKE) -s l THREAD="-pthread -fsanitize=thread"

l: $(NAME)

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(HDR) $(X_HDR)
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