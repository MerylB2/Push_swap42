NAME = push_swap
BONUS = checker

LIBFT_DIR = ./libft
LIBFT =  $(LIBFT_DIR)/libft.a
INC_D = /includes
SRC_DIR = srcs
BONUS_DIR = bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Recherche des fichiers source
SRCS = $(shell find $(SRC_DIR) -name "*.c")
BONUS_SRCS = $(shell find $(BONUS_DIR) -name "*.c")

# Répertoire des objets compilés
OBJ_DIR = objets

# Fichiers objets
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

# Couleurs pour l'affichage
RED     := \033[1;31m
GREEN   := \033[1;32m
YELLOW  := \033[1;33m
BLUE    := \033[1;34m
RESET   := \033[0m

# Ajouter les répertoires à `vpath` pour la recherche des fichiers sources
vpath %.c $(SRC_DIR) $(BONUS_DIR)

# Règle par défaut : création de l'exécutable principal
all: $(NAME)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -I.$(INC_D) -c $< -o $@

# Lier et créer l'exécutable principal
$(NAME): $(OBJS)
	@echo "$(BLUE)Liaison de $(NAME)...$(RESET)"
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) créé avec succès !$(RESET)"

# Lier et créer l'exécutable bonus
bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	@echo "$(BLUE)Liaison de $(BONUS)...$(RESET)"
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(GREEN)$(BONUS) créé avec succès !$(RESET)"

# Crée le répertoire d'objets
$(OBJ_DIR):
	@echo "$(YELLOW)Création du répertoire des objets...$(RESET)"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Nettoyage des objets...$(RESET)"
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Suppression de $(NAME) et $(BONUS)...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) $(BONUS)
	@rm -rf $(OBJ_DIR)

re: fclean all
	@echo "$(GREEN)Recompilation complète...Done$(RESET)"

re_bonus: fclean bonus
	@echo "$(GREEN)Recompilation du bonus...Done$(RESET)"

.PHONY: all bonus clean fclean re bonus re_bonus