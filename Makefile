NAME = push_swap

LIBFT_DIR = ./libft
LIBFT =  $(LIBFT_DIR)/libft.a
INC_D = /includes
SRC_DIR = srcs

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Recherche des fichiers source
SRCS = $(shell find $(SRC_DIR) -name "*.c")

# Répertoire des objets compilés
OBJ_DIR = objets

# Fichiers objets
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

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

# Crée le répertoire d'objets
$(OBJ_DIR):
	@echo "$(YELLOW)Création du répertoire des objets...$(RESET)"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Nettoyage des objets...$(RESET)"
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Nettoyage des fichiers objets de $(NAME)$(RESET)"

fclean: clean
	@echo "$(RED)Suppression de $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Nettoyage Complet de $(NAME)$(RESET)"

re: fclean all
	@echo "$(GREEN)Recompilation complète...Done$(RESET)"

.PHONY: all bonus clean fclean re bonus re_bonus