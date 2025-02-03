/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:56:49 by ange              #+#    #+#             */
/*   Updated: 2025/02/03 17:26:16 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif
# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif
# ifndef STDBOOL_H
#  define STDBOOL_H
#  include <stdbool.h>
# endif
# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif
# define HEX_ADRESS_SIZE 16
# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif
# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# define HEX_ADRESS_SIZE 16

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define BUFFER_NON_EMPTY 1
# define BUFFER_EMPTY_BC_END_OF_FILE 0
# define BUFFER_EMPTY_BC_READ_FAILURE -1

# define GNL_SUCCESS 1
# define GNL_ERROR -1

# define EOL_FOUNDED 1
# define EOL_NOT_FOUNDED 0

# define KEEP_LOOPING 1
# define STOP_LOOPING 0
# define NO_LINE_YET 0
# define THERE_IS_ALREADY_LINE 1

typedef unsigned char		t_octet;

/*gnl*/
int			ft_fill_buffer(char *buffer, int fd);
int			ft_destroy_and_create_line(char **line, char *buffer);
int			ft_fill_from_buffer_to_line(char *line, char *buffer);
int			getting_next_line_loop(char **line, char *buffer, int fd);
char		*get_next_line(int fd);
void		*ft_calloc(size_t element_count, size_t element_size);
size_t		ft_buffer_len(char *buffer);
bool		ft_is_buffer_empty(char *buffer);
/*ft_printf*/
void		ft_printf_putchar_fd(char c, int fd, int *char_nb);
void		ft_printf_putstr_fd(char *str, int fd, int *char_nb);
void		ft_printf_put_int_fd(int n, int fd, int *char_nb);
void		ft_printf_put_unsigned_int_fd(unsigned int n, int fd, int *char_nb);
void		ft_printf_put_caphex_fd(unsigned int n, int fd, int *char_nb);
void		ft_printf_put_lowhex_fd(unsigned int n, int fd, int *char_nb);
void		ft_printf_put_hex_adress_fd(unsigned long adress, int fd,
				int *char_nb);
int			ft_printf_fd(int fd, const char *str, ...);
int			ft_printf(const char *str, ...);
/*libft*/
int			ft_isdigit(int integer_to_check);
int			ft_isalpha(int integer_to_check);
int			ft_isalnum(int integer_to_check);
int			ft_isascii(int integer_to_check);
int			ft_isprint(int integer_to_check);
int			ft_is_white_space(int c);
size_t		ft_strlen(const char *string_to_get_len);
void		*ft_memset(void *memory_zone_to_set,
				int octet_set_value, size_t number_of_octet_to_set);
void		*ft_bzero(void *general_pointer, size_t null_octet_number);
void		*ft_memcpy(void *memory_destination,
				const void *memory_source,
				size_t number_of_octet_to_copy);
void		*ft_memmove(void *destimation_memory,
				const void *source_memory, size_t number_of_octet_to_copy);
size_t		ft_strlcpy(char *destination_string,
				const char *source_string, size_t buffer_size);
size_t		ft_strlcat(char *destination_string,
				const char *source_string, size_t buffer_size);
int			ft_toupper(int character_to_upper);
int			ft_tolower(int character_to_lower);
char		*ft_strchr(const char *source_string, int character_to_find);
char		*ft_strrchr(const char *source_string, int character_to_find);
int			ft_strcmp(const char *str1,
				const char *str2);
int			ft_strncmp(const char *string_source_1,
				const char *string_source_2,
				size_t number_of_character_to_compare_at_max);
char		*ft_strnstr(const char *source_string,
				const char *sub_string, size_t len);
void		*ft_memchr(const void *memory_to_check,
				int octet_to_look_for, size_t number_of_octet_to_check);
void		*ft_memrchr(const void *memory_to_check,
				int octet_to_look_for, size_t number_of_octet_to_check);
int			ft_atoi(const char *string);
void		*ft_calloc(size_t elementCount, size_t elementSize);
char		*ft_strdup(const char *source);
char		*ft_strtrim(char const *source, char const *pattern);
void		ft_free_tab(char **tab);
void		ft_free(void *ptr);
size_t		ft_count_words(const char *src, char separator);
char		**ft_split(const char *string_to_split, char delimiter);
void		ft_print_tab(char *tab_name, char **tab);
void		ft_putchar_fd(char character_to_put, int file_descriptor);
char		*ft_itoa(int integer);
char		*ft_strmapi(char const *source_string,
				char (*functionToApply)(unsigned int, char));
void		ft_striteri(char *source, void (*function_to_apply)(unsigned int,
					char*));
void		ft_putstr_fd(char *string_to_put, int file_descriptor);
void		ft_putendl_fd(char *string_to_put, int file_descriptor);
void		ft_putnbr_fd(int number_to_put, int file_descriptor);
int			ft_memcmp(void *memory_1, void *memory_2,
				size_t number_octet_to_compare);
char		*ft_substr(char const *source,
				unsigned int substrimgStartIndex, size_t substringMaxLen);
char		*ft_strjoin(char const *prefix, char const *suffix);

#endif