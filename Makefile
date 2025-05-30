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
		libft/ft_tablen \
		libft/ft_tolower \
		libft/ft_toupper \
		\
		ft_printf/ft_printf \
		ft_printf/ft_printf_fd \
		ft_printf/ft_printf_putchar_fd \
		ft_printf/ft_printf_putnbr_fd \
		ft_printf/ft_printf_putnbr_hexa_fd \
		ft_printf/ft_printf_putstr_fd \
		\
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

MINISHELL_FILES = 	main \
					get_and_store_user_input \
					print_result_for_dev \
					\
					data/create_space/init_data \
					data/create_space/create_lexer_space \
					data/create_space/create_linked_env_space \
					data/create_space/create_user_input_space \
					data/create_space/create_parsing_space \
					data/create_space/create_exec_space \
					data/create_space/create_export_space \
					\
					data/free_space/free_lexer_space \
					data/free_space/free_linked_env_space \
					data/free_space/free_user_input_space \
					data/free_space/free_data \
					data/free_space/free_parsing_space \
					data/free_space/free_exec_space \
					data/free_space/free_export_space \
					\
					data/fatal_error_clean_exit \
					data/non_fatal_error_clean \
					\
					\
					double_linked_list/dll_clear_list \
					double_linked_list/dll_clear_node \
					double_linked_list/dll_find_node \
					double_linked_list/dll_insert_tail \
					double_linked_list/dll_len \
					double_linked_list/dll_new_list \
					double_linked_list/dll_new_node \
					double_linked_list/dll_print_list \
					\
					\
					env/env_var_to_env_content \
					env/free_env_content \
					env/create_linked_env \
					\
					\
					lexer/lexer \
					lexer/rename_string_tk_in_appropriate_tk \
					lexer/lexer_state_machine \
					lexer/get_next_token_and_insert_tail \
					lexer/get_next_token_content \
					lexer/get_token_type \
					lexer/free_token_content \
					lexer/print_token_content \
					lexer/delete_all_space_tk \
					lexer/convert_lonely_dq_and_sq_to_str \
					lexer/set_up_if_heredoc_should_expend_later \
					\
					lexer/token_bool_utils/is_a_pipe_token \
					lexer/token_bool_utils/is_a_redir_token \
					lexer/token_bool_utils/is_a_quote_token \
					lexer/token_bool_utils/is_a_string_token \
					lexer/token_bool_utils/is_a_file_token \
					lexer/token_bool_utils/is_a_cmd_token \
					lexer/token_bool_utils/is_a_arg_token \
					lexer/token_bool_utils/is_a_heredoc_token \
					lexer/token_bool_utils/is_a_space_token \
					\
					lexer/character_utils/actual_character \
					lexer/character_utils/next_character \
					lexer/character_utils/actual_character_offset \
					lexer/character_utils/moov_cursor_forward_of_one \
					\
					lexer/get_next_token_value/get_next_space_value \
					lexer/get_next_token_value/get_next_append_value \
					lexer/get_next_token_value/get_next_input_value \
					lexer/get_next_token_value/get_next_heredoc_value \
					lexer/get_next_token_value/get_next_output_value \
					lexer/get_next_token_value/get_next_string_value \
					lexer/get_next_token_value/get_next_db_quote_value \
					lexer/get_next_token_value/get_next_s_quote_value \
					lexer/get_next_token_value/get_next_pipe_value \
					\
					lexer/merge_str_dq_sq/merge_str_dq_sq \
					lexer/merge_str_dq_sq/ft_strjoin_dq_sq \
					\
					lexer/check_syntax_error/check_unclose_quote \
					lexer/check_syntax_error/check_each_command_has_content \
					lexer/check_syntax_error/check_redir_followed_by_string \
					\
					\
					expend/expend \
					expend/expend_value \
					expend/replace_dollar_in_expend_list \
					expend/create_expend_list \
					expend/merge_expend_list \
					\
					\
					parsing/parsing \
					parsing/create_segment_dll \
					parsing/free_segment_content \
					parsing/free_redir_tab \
					\
					parsing/add_next_segment_to_segment_dll/add_cmd_name_to_segment \
					parsing/add_next_segment_to_segment_dll/add_cmd_arg_to_segment \
					parsing/add_next_segment_to_segment_dll/add_redir_tab_to_segment \
					parsing/add_next_segment_to_segment_dll/add_next_segment_to_segment_dll \
					parsing/add_next_segment_to_segment_dll/count_cmd_arg_nb_in_this_segment \
					parsing/add_next_segment_to_segment_dll/count_redir_nb_in_this_segment \
					\
					parsing/utils/get_first_token_of_segment \
					parsing/utils/get_token_value \
					parsing/utils/print_segment_content \
					\
					\
					exec/exec \
					\
					exec/utils/free_cmd_content \
					exec/utils/print_cmd_content \
					\
					exec/build_cmd_list/build_cmd_list \
					exec/build_cmd_list/convert_segment_in_cmd \
					exec/build_cmd_list/fill_fd \
					exec/build_cmd_list/heredoc \
					exec/build_cmd_list/set_all_pipes \
					exec/build_cmd_list/set_pipe_in_a_cmd \
					exec/build_cmd_list/set_builtin_cmd_to_be_exec_in_parent_process \
					exec/build_cmd_list/set_builtin_cmd_to_skip \
					exec/build_cmd_list/go_throught_cmd_dll_and_process_heredoc \
					\
					exec/build_cmd_list/open/append_open \
					exec/build_cmd_list/open/heredoc_open \
					exec/build_cmd_list/open/infile_open \
					exec/build_cmd_list/open/truncate_open \
					\
					exec/exec_cmd/exec_cmd \
					exec/exec_cmd/is_builtin \
					exec/exec_cmd/child_process \
					exec/exec_cmd/parent_process \
					exec/exec_cmd/convert_env_dll_into_env_str_tab \
					exec/exec_cmd/add_absolute_path_to_cmd_name \
					exec/exec_cmd/ft_strjoin_with_separator \
					exec/exec_cmd/close_cmd_fd \
					exec/exec_cmd/launch_builtin \
					exec/exec_cmd/launch_non_builtin \
					exec/exec_cmd/check_and_search_for_abs_path \
					\
					exec/builtins/echo \
					exec/builtins/pwd \
					exec/builtins/cd \
					exec/builtins/env \
					exec/builtins/export \
					exec/builtins/unset \
					exec/builtins/exit \
					exec/builtins/utils \
					exec/builtins/utils_export \
					exec/builtins/set_last_exit_code \
					\
					\
					signal/ignore_sigquit \
					signal/catch_last_signal \
					signal/set_signals_heredoc \
					signal/set_signals_interactive \
					signal/set_signals_noninteractive \

MINISHELL_SRCS_DIR = ./src/minishell/
MINISHELL_SRCS = $(addprefix $(MINISHELL_SRCS_DIR), $(addsuffix .c, $(MINISHELL_FILES)))
MINISHELL_OBJS_DIR = ./obj/minishell/
MINISHELL_OBJS = $(addprefix $(MINISHELL_OBJS_DIR), $(addsuffix .o, $(MINISHELL_FILES)))

$(NAME): $(LIBFT) $(MINISHELL_OBJS)
	@echo -n "$(CLEAR_LINE)$(BLUE)Linking: $@..." ; \
	$(CC) $(CFLAGS) -o $@ $(MINISHELL_OBJS) -L./lib -lft -lreadline 
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
