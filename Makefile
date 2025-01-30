CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
INCLUDES = ./header/
AR = ar rcs
RM = rm -rf
LIBFT = $(LIB_DIR)libft.a
NAME = minishell
LIB_DIR = ./lib/
CLEAR_LINE = \033[2K\r

# Emojis
CHECK   = "✅"
CROSS   = "❌"
BUILD   = "🔨"
LINK    = "🔗"
CLEAN   = "🧹"

# Couleurs ANSI
BLUE    = \033[34m
GREEN   = \033[32m
RED     = \033[31m
RESET   = \033[0m

all: $(NAME)

LIBFT_FILES = \
		libft/ft_atoi \
		libft/ft_bzero \
		libft/ft_calloc \
		libft/ft_count_words \
		libft/ft_free \
		libft/ft_is_white_space \
		libft/ft_isalnum \
		libft/ft_isalpha \
		libft/ft_isascii \
		libft/ft_isdigit \
		libft/ft_itoa \
		libft/ft_memchr \
		libft/ft_memcmp \
		libft/ft_memcpy \
		libft/ft_memmove \
		libft/ft_memrchr \
		libft/ft_memset \
		libft/ft_print_tab \
		libft/ft_putchar_fd \
		libft/ft_putendl_fd \
		libft/ft_putnbr_fd \
		libft/ft_putstr_fd \
		libft/ft_split \
		libft/ft_strchr \
		libft/ft_strcmp \
		libft/ft_strdup \
		libft/ft_striteri \
		libft/ft_strjoin \
		libft/ft_strlcat \
		libft/ft_strlcpy \
		libft/ft_strlen \
		libft/ft_strmapi \
		libft/ft_strncmp \
		libft/ft_strnstr \
		libft/ft_strrchr \
		libft/ft_strtrim \
		libft/ft_substr \
		libft/ft_tolower \
		libft/ft_toupper \
		ft_printf/ft_printf \
		ft_printf/ft_printf_fd \
		ft_printf/ft_printf_putchar_fd \
		ft_printf/ft_printf_putnbr_fd \
		ft_printf/ft_printf_putnbr_hexa_fd \
		ft_printf/ft_printf_putstr_fd \
		gnl/get_next_line \
		gnl/get_next_line_utils \

LIBFT_SRCS_DIR = ./src/libft/
LIBFT_SRCS = $(addprefix $(LIBFT_SRCS_DIR), $(addsuffix .c, $(LIBFT_FILES)))
LIBFT_OBJS_DIR = ./obj/libft/
LIBFT_OBJS = $(addprefix $(LIBFT_OBJS_DIR), $(addsuffix .o, $(LIBFT_FILES)))


$(LIBFT): $(LIBFT_OBJS)
	@mkdir -p $(LIB_DIR)
	@echo -n "$(CLEAR_LINE)$(BLUE)Compiling libft: $@..." ; \
	$(AR) $@ $^
	@echo -n "$(CLEAR_LINE)$(GREEN)$(CHECK) $@ linked successfully!\n$(RESET)" ;

$(LIBFT_OBJS_DIR)%.o: $(LIBFT_SRCS_DIR)%.c
	@echo -n "$(CLEAR_LINE)$(BLUE)Compiling: $<..." ; \
	mkdir -p $(dir $@) ; \
	mkdir -p $(LIBFT_OBJS_DIR) ; \
	$(CC) $(CFLAGS) -c $< -o $@ ; 

libft: $(LIBFT)

libft_clean:
	@echo -n "$(CLEAR_LINE)$(BLUE)$(CLEAN) removing libft obj\n$(RESET)"
	@$(RM) $(LIBFT_OBJS_DIR)
	@rmdir ./obj 2>/dev/null || true

libft_fclean: libft_clean
	@echo -n "$(CLEAR_LINE)$(BLUE)$(CLEAN) removing libft lib\n$(RESET)"
	@$(RM) $(LIBFT)
	@rmdir ./lib 2>/dev/null || true

libft_re: libft_fclean $(LIBFT)

MINISHELL_FILES = main

MINISHELL_SRCS_DIR = ./src/minishell/
MINISHELL_SRCS = $(addprefix $(MINISHELL_SRCS_DIR), $(addsuffix .c, $(MINISHELL_FILES)))
MINISHELL_OBJS_DIR = ./obj/minishell/
MINISHELL_OBJS = $(addprefix $(MINISHELL_OBJS_DIR), $(addsuffix .o, $(MINISHELL_FILES)))

$(NAME): $(LIBFT) $(MINISHELL_OBJS)
	@echo -n "$(CLEAR_LINE)$(BLUE)Linking: $@..." ; \
	$(CC) $(CFLAGS) -o $@ $(MINISHELL_OBJS) -L./lib -lft
	@echo "\n$(BOLD)$(BLUE)"
	@echo "  ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
	@echo "  ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
	@echo "  ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
	@echo "  ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
	@echo "  ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
	@echo "  ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"
	@echo "$(RESET)"
	@echo -n "$(CLEAR_LINE)$(GREEN)$(CHECK) $@ linked successfully!\n$(RESET)";

$(MINISHELL_OBJS_DIR)%.o: $(MINISHELL_SRCS_DIR)%.c
	@echo -n "$(CLEAR_LINE)$(BLUE)Compiling: $<..." ; \
	mkdir -p $(dir $@) ; \
	mkdir -p $(MINISHELL_OBJS_DIR) ; \
	$(CC) $(CFLAGS) -c $< -o $@ ;

minishell_clean:
	@echo -n "$(CLEAR_LINE)$(BLUE)$(CLEAN) removing minishell obj\n$(RESET)"
	@$(RM) $(MINISHELL_OBJS_DIR)
	@rmdir ./obj 2>/dev/null || true

minishell_fclean: minishell_clean
	@echo -n "$(BLUE)$(CLEAN) removing minishell exe\n$(RESET)"
	@$(RM) $(NAME)

minishell_re: minishell_fclean $(NAME)

clean: libft_clean minishell_clean
	@echo -n "$(GREEN)$(CHECK) object clean!$(RESET)\n"

fclean: clean libft_fclean minishell_fclean
	@echo -n "$(CLEAR_LINE)$(GREEN)$(CHECK) evrything clean!\n$(RESET)"

re: fclean $(NAME)

all: $(NAME)

.PHONY: all \
	minishell_clean minishell_fclean minishell_re \
	libft libft_clean libft_fclean libft_re \
	clean fclean re