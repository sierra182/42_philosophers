NAME = philo
X_HDR_DIR = x_includes
HDR_DIR = includes
SRC_DIR = sources
CC = cc
THREAD = -pthread

CFLAGS = $(X_HDRFLAGS) $(HDRFLAGS) $(THREAD) -g -Wall -Wextra -Werror
LDFLAGS = $(THREAD)

X_HDRFLAGS = \
	-I$(X_HDR_DIR)/exit_area \
	-I$(X_HDR_DIR)/philo_utils \
	-I$(X_HDR_DIR)/setup \
	-I$(X_HDR_DIR)/setup/error_zone

X_HDR =	\
	$(X_HDR_DIR)/exit_area/x_exit.h \
	$(X_HDR_DIR)/exit_area/x_data_store.h \
	$(X_HDR_DIR)/philo_utils/x_philo_struct.h \
	$(X_HDR_DIR)/philo_utils/x_philo_utils.h \
	$(X_HDR_DIR)/setup/x_init.h \
	$(X_HDR_DIR)/setup/x_setup.h \
	$(X_HDR_DIR)/setup/error_zone/x_error_utils.h 

HDRFLAGS = \
	-I$(HDR_DIR) \
	-I$(HDR_DIR)/exit_area \
	-I$(HDR_DIR)/mortuary \
	-I$(HDR_DIR)/philo_utils \
	-I$(HDR_DIR)/routine \
	-I$(HDR_DIR)/setup \
	-I$(HDR_DIR)/setup/error_zone

HDR = \
	$(HDR_DIR)/main.h \
	$(HDR_DIR)/exit_area/exit.h \
	$(HDR_DIR)/exit_area/data_store.h \
	$(HDR_DIR)/mortuary/mortuary.h \
	$(HDR_DIR)/philo_utils/ft_calloc.h \
	$(HDR_DIR)/philo_utils/philo_utils.h \
	$(HDR_DIR)/philo_utils/time.h \
	$(HDR_DIR)/routine/eat.h \
	$(HDR_DIR)/routine/routine.h \
	$(HDR_DIR)/setup/init.h \
	$(HDR_DIR)/setup/setup.h \
	$(HDR_DIR)/setup/error_zone/check_argv.h \
	$(HDR_DIR)/setup/error_zone/error_utils.h	

OBJ = $(SRC:.c=.o)

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/exit_area/exit.c \
	$(SRC_DIR)/exit_area/data_store.c \
	$(SRC_DIR)/mortuary/mortuary.c \
	$(SRC_DIR)/philo_utils/ft_calloc.c \
	$(SRC_DIR)/philo_utils/philo_utils.c \
	$(SRC_DIR)/philo_utils/time.c \
	$(SRC_DIR)/routine/eat.c \
	$(SRC_DIR)/routine/routine.c \
	$(SRC_DIR)/setup/init.c \
	$(SRC_DIR)/setup/setup.c \
	$(SRC_DIR)/setup/error_zone/check_argv.c \
	$(SRC_DIR)/setup/error_zone/error_utils.c

.PHONY: all clean fclean re intro l newline backline emoticon address thread bonus

all: intro $(NAME) 

address:
	@$(MAKE) -s l THREAD="-pthread -fsanitize=address"

thread:
	@$(MAKE) -s l THREAD="-pthread -fsanitize=thread"

l: emoticon $(NAME)

bonus:
	@$(MAKE) l -s -C ../philo_bonus

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
	@$(MAKE) clean -s -C ../philo_bonus	

fclean: 
	@echo "\n cleanning $(NAME) objects 🧻"
	@rm -f $(OBJ) $(OBJ_BONUS);
	@echo " cleanning $(NAME) 🚽" 
	@rm -f $(NAME) $(NAME_BONUS)	
	@$(MAKE) fclean -s -C ../philo_bonus

re: fclean backline l