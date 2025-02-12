# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 16:25:10 by cmetee-b          #+#    #+#              #
#    Updated: 2025/02/11 19:58:57 by cmetee-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#les_variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes

SRC_DIR			= srcs/
OBJ_DIR			= objs/

#les_fichiers
SRCS = $(shell find $(SRC_DIR) -name "*.c")

OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

#couleurs
RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
BLUE    := "\033[1;34m"
RESET   := "\033[0m"

#regles
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -fPIE -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(GREEN)"Compilation de LIBFT Done!!!!"$(RESET)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(BLUE)"Nettoyage des fichiers objets de la LIBFT!! OK"$(RESET)

fclean: clean
	@rm -rf $(NAME)
	@echo $(BLUE)"Nettoyage Complet de LIBFT!!! OK"$(RESET)

re: fclean all

.PHONY: all clean fclean re
