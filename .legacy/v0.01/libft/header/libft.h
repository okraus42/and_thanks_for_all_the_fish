/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:43:29 by okraus            #+#    #+#             */
/*   Updated: 2023/06/17 15:55:52 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

// INCLUDES

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

// DEFINITIONS
// GET_NEXT_LINE definitions

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

// FT_PRINTF definitions
# define F_TYPS 	"cspdiuxXBPC%"
# define F_FLGS 	"0#-+. "
# define BASE_CAP	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define BASE_SML	"0123456789abcdefghijklmnopqrstuvwxyz"

// STRUCTURES
// LIBFT structure

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// FT_PRINTF structure

typedef struct s_output
{
	char	*string;
	int		len;
	int		precision;
	int		padsize;
	int		dash;
	int		zero;
	int		period;
	int		hash;
	int		space;
	int		plus;
	char	type;
	int		base;
}			t_output;

// EXTRA structure

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

// PROTOTYPES
// LIBFT prototypes

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, unsigned long n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// EXTRA prototypes

// double list
void			ft_dlstadd(t_dlist **dlst, t_dlist *new);
void			ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void			ft_dlstclear2(t_dlist **dlst);
void			ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void			ft_dlstdelone2(t_dlist *dlst);
void			ft_dlstmovein(t_dlist **dlst_dst, t_dlist *dlst_src);
void			ft_dlstmoveout(t_dlist **dlst_src);
void			ft_dlstmoveone(t_dlist **dlst_dst, t_dlist **dlst_src);
t_dlist			*ft_dlstnew(void *content);

// evil malloc & calloc
void			*ft_evil_malloc(size_t size);
void			*ft_evil_malloc_plus(size_t size, size_t padding);
void			*ft_evil_calloc(size_t nmemb, size_t size);
void			*ft_evil_calloc_plus(size_t nmemb, size_t size, size_t padding);

// math stuff
int				ft_abs(int n);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
void			ft_swap(int *a, int *b);
void			ft_uswap(unsigned int *a, unsigned int *b);
unsigned int	ft_atoi_base(const char *base, char *str);
unsigned int	ft_umin(unsigned int a, unsigned int b);
unsigned int	ft_umax(unsigned int a, unsigned int b);
unsigned int	ft_uabsdif(unsigned int a, unsigned int b);

// long long atoi & itoa
long long		ft_latoi(const char *nptr);
char			*ft_litoa(long long n);

// free split
void			ft_free_split(char **split);

// memory
void			*ft_print_memory(void *addr, int fd, unsigned int size);
void			*ft_print_memory_plus(void *addr, int fd, unsigned int size);

// printing array of strings
void			ft_put_strarray(char **arr);

// GET_NEXT_LINE prototypes

char			*read_file(int fd, char *str);
char			*get(char *str);
char			*next(char *str);
char			*get_next_line(int fd);
int				ft_find_char(char *s, char c);
int				ft_strlen_gnl(char *s);
char			*ft_strjoin_gnl(char *s1, char *s2);

// FT_PRINTF prototypes

int				ft_printf_fd(int fd, const char *s, ...);
int				ft_printf(const char *s, ...);
void			ft_putstuff(va_list arg, const char *s, int *q, t_output *t);
void			ft_writestuff(int fd, const char *s, int *q);
int				ft_pf_putchar_fd(char c, int fd, t_output *t);
int				ft_print_char_fd(char s, int fd, t_output *t);
char			*ft_string_pointer(void *mem);
int				ft_putpointer_fd(void *mem, int fd, t_output *t);
int				ft_print_pointer_fd(void *mem, int fd);
int				ft_putstring_fd(char *s, int fd, t_output *t);
int				ft_print_string_fd(char *s, int fd, t_output *t);
int				ft_putunsigned_fd(unsigned int u, int fd, t_output *t);
int				ft_print_unsigned_fd(unsigned int u, int fd, t_output *t);
char			*ft_string_unsigned(unsigned int u);
int				ft_putinteger_fd(int d, int fd, t_output *t);
int				ft_print_integer_fd(int d, int fd, t_output *t);
char			*ft_string_integer(int d);
int				ft_puthexabig_fd(unsigned int h, int fd, t_output *t);
int				ft_print_hexabig_fd(unsigned int h, int fd, t_output *t);
char			*ft_string_hexabig(unsigned int h);
int				ft_puthexasmall_fd(unsigned int h, int fd, t_output *t);
int				ft_print_hexasmall_fd(unsigned int h, int fd, t_output *t);
char			*ft_string_hexasmall(unsigned int h);
void			ft_initialise_struct(t_output *t);
void			ft_dash_struct(t_output *t, int n);
void			ft_prefill_struct(t_output *t, const char *s);
int				ft_get_num(t_output *t, const char *s, int i);
char			*ft_strjoin_freeleft(char *s1, char const *s2);
char			*ft_strjoin_freeright(char const *s1, char *s2);
char			*ft_padchar(char *s, int len, t_output *t);
char			*ft_padint(char *s, t_output *t);
char			*ft_precint(char *s, t_output *t);
int				ft_putbasebig_fd(unsigned int b, int fd, t_output *t);
int				ft_print_basebig_fd(unsigned int b, int fd, t_output *t);
char			*ft_string_basebig(unsigned int b, t_output *t);
int				ft_putbinocthex_fd(void *b, int fd, t_output *t);
int				ft_print_binocthex_fd(unsigned char b, int fd, t_output *t);
char			*ft_string_binocthex(unsigned char b, t_output *t);
int				ft_putcolour_fd(int fd, t_output *t);
int				ft_print_colour_fd(int fd, t_output	*t);
int				ft_print_colour_fd_0(int fd, t_output *t);
int				ft_print_colour_fd_1(int fd, t_output *t);
int				ft_print_colour_fd_2(int fd, t_output *t);
int				ft_print_colour_fd_3(int fd, t_output *t);
int				ft_print_colour_fd_4(int fd, t_output *t);
int				ft_print_colour_fd_5(int fd, t_output *t);
int				ft_print_colour_fd_6(int fd, t_output *t);
int				ft_print_colour_fd_7(int fd, t_output *t);
int				ft_print_colour_fd_8(int fd, t_output *t);
int				ft_print_colour_fd_9(int fd, t_output *t);

#endif
