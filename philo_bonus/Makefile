NAME = philo_bonus
X_HDR_DIR = x_includes
HDR_DIR = includes
SRC_DIR = sources
CC = cc
THREAD = -pthread

CFLAGS = $(X_HDRFLAGS) $(HDRFLAGS) $(THREAD) -g -Wall -Wextra -Werror
LDFLAGS = $(THREAD)

X_HDRFLAGS = \
	-I$(X_HDR_DIR) \

X_HDR =	\
	$(X_HDR_DIR)/x_philo_struct.h \
	$(X_HDR_DIR)/x_exit.h \

HDRFLAGS = \
	-I$(HDR_DIR) \
	-I$(HDR_DIR)/parsing \
	-I$(HDR_DIR)/setup \
	-I$(HDR_DIR)/exit \
	-I$(HDR_DIR)/childs \
	-I$(HDR_DIR)/childs/threads \
	-I$(HDR_DIR)/childs/threads/routines \

HDR = \
	$(HDR_DIR)/main.h \
	$(HDR_DIR)/ph_time.h \
	$(HDR_DIR)/death_noticer.h \
	$(HDR_DIR)/parsing/parsing.h \
	$(HDR_DIR)/parsing/parsing_utils.h \
	$(HDR_DIR)/setup/setup.h \
	$(HDR_DIR)/setup/setup_utils.h \
	$(HDR_DIR)/setup/ft_calloc.h \
	$(HDR_DIR)/exit/exit.h \
	$(HDR_DIR)/exit/data_store.h \
	$(HDR_DIR)/childs/childs.h \
	$(HDR_DIR)/childs/threads/ph_threads.h \
	$(HDR_DIR)/childs/threads/routines/mortician.h \
	$(HDR_DIR)/childs/threads/routines/philo.h \

OBJ = $(SRC:.c=.o)

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/time.c \
	$(SRC_DIR)/death_noticer.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/parsing_utils.c \
	$(SRC_DIR)/setup/setup.c \
	$(SRC_DIR)/setup/setup_utils.c \
	$(SRC_DIR)/exit/exit.c \
	$(SRC_DIR)/exit/data_store.c \
	$(SRC_DIR)/setup/ft_calloc.c \
	$(SRC_DIR)/childs/childs.c \
	$(SRC_DIR)/childs/threads/threads.c \
	$(SRC_DIR)/childs/threads/routines/philo.c \
	$(SRC_DIR)/childs/threads/routines/mortician.c \

.PHONY: all clean fclean re intro l newline backline emoticon address

all: intro $(NAME) 

address:
	@$(MAKE) -s l THREAD="-pthread -fsanitize=address"

thread:
	@$(MAKE) -s l THREAD="-pthread -fsanitize=thread"

l: emoticon $(NAME)

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
	@echo -e "\033[?25l"
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
	@cat mfile_design
	@$(MAKE) -s emoticon
	@echo "\033[?25h"
	@$(MAKE) -s backline

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