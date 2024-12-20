RESET='\033[0m'
RED='\033[31m'
GREEN='\033[32m'
YELL='\033[33m'
BOLD='\033[1m'
UNDER='\033[4m'

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS =	philo.c	error_message.c	philo_utils.c\
		parsing.c	init_resource.c\
		cleanner.c	dinner_utils.c	start_dinner.c	getter_setter.c\
		one_philo.c

HEADER = philo.h

OBJS = $(SRCS:.c=.o)

all:	$(NAME)
	@sleep 0.7
	@echo ${GREEN}${BOLD}"\n	[Files Compiled]\n"${RESET}
%.o: %.c	$(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo ${YELL}${BOLD}"\n	[files cleaned]\n"${RESET}

fclean:	clean
	@rm -rf $(NAME)
re:	fclean	all

.PHONY: all	clean	fclean	re