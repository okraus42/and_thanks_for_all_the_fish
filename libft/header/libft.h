/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:43:29 by okraus            #+#    #+#             */
/*   Updated: 2023/11/18 16:43:37 by okraus           ###   ########.fr       */
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
# include <limits.h>

// DEFINITIONS
// GET_NEXT_LINE definitions

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// FT_PRINTF definitions
# define F_TYPES	"cspdiouxXBbPCQ%"
# define F_FLAGS	"0#-+ 'I"
# define F_NUMBERS	"0123456789*"
# define F_MODIFIER	"hlLz"
# define BASE_CAP	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define BASE_SML	"0123456789abcdefghijklmnopqrstuvwxyz"
# define BASE_HEX	"0123456789ABCDEF"

//	MACROS - forbidden?

//# define ABS(Value) (Value < 0 ? -Value : Value)

typedef enum e_print_flag
{
	ZERO = 0x1,
	HASHTAG = 0x2,
	MINUS = 0x4,
	PLUS = 0x8,
	SPACE = 0x10,
	APOSTROPHE = 0x20,
	UPPERCASE_I = 0x40,
	PERIOD = 0x80,
	CIRCUMFLEX = 0x100,
	FLAGC = 0x200,
	FLAG1 = 0x400,
	FLAG2 = 0x800,
	FLAG3 = 0x1000,
	FLAG4 = 0x2000,
	FLAG5 = 0x4000,
	FLAG6 = 0x8000,
}	t_print_flag;

// typedef enum e_print_flag
// {
// 	ZERO = 0x1,						// The value should be zero padded.  
//	For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, the converted
// value is padded on the left with zeros rather than blanks.  If the 0 and -
// flags both appear, the 0 flag is ignored.  If a precision is given with an
// integer conversion (d, i, o, u, x, and X), the 0 flag is ignored.
// 	HASHTAG = 0x2,					// The value should be converted to an 
// "alternate form".  For o conversions, the first character of the output
// string is made zero (by prefixing a 0 if it was not zero already). For x and
// X conversions, a nonzero result has the string "0x" (or "0X" for X
// conversions) prepended to it.  For a, A, e, E, f, F, g, and G conversions,
// the result will always contain a decimal point, even if no digits follow it
// (normally, a decimal point appears in the results of those conversions only
// if a digit follows).  For g and G conversions, trailing zeros are not removed
// from the result as they would otherwise be.
// 	MINUS = 0x4,					// The converted value is to be left
// adjusted on the field boundary.  (The default is right justification.) 
// The converted value is padded on the right with blanks, rather than on the
// left with blanks or zeros.  A - overrides a 0 if both are given.
// 	PLUS = 0x8,						// A sign (+ or -) should always be placed
// before a number produced by a signed conversion.  By default, a sign is used
// only for negative numbers.  A + overrides a space if both are used.
// 	SPACE = 0x10,					// (a space) A blank should be left before
// a positive number (or empty string) produced by a signed conversion.
// 	APOSTROPHE = 0x20,				// For decimal conversion
// (i, d, u, f, F, g, G) the output is to be grouped with thousands' grouping
// characters if the locale information indicates any.
// 	UPPERCASE_I = 0x40,				// ignored for now
// 	PERIOD = 0x80,					//
// 	CIRCUMFLEX = 0x100,				// for base conversion
// 	FLAGC = 0x200,					//
// 	FLAG1 = 0x400,					//
// 	FLAG2 = 0x800,					//
// 	FLAG3 = 0x1000,					//
// 	FLAG4 = 0x2000,					//
// 	FLAG5 = 0x4000,					//
// 	FLAG6 = 0x8000,					//
// }	t_print_flag;

//    Field width
//        An optional decimal digit string (with nonzero first digit)
//        specifying a minimum field width.  If the converted value has
//        fewer characters than the field width, it will be padded with
//        spaces on the left (or right, if the left-adjustment flag has
//        been given).  Instead of a decimal digit string one may write "*"
//        or "*m$" (for some decimal integer m) to specify that the field
//        width is given in the next argument, or in the m-th argument,
//        respectively, which must be of type int.  A negative field width
//        is taken as a '-' flag followed by a positive field width.  In no
//        case does a nonexistent or small field width cause truncation of
//        a field; if the result of a conversion is wider than the field
//        width, the field is expanded to contain the conversion result.

//    Precision
//        An optional precision, in the form of a period ('.')  followed by
//        an optional decimal digit string.  Instead of a decimal digit
//        string one may write "*" or "*m$" (for some decimal integer m) to
//        specify that the precision is given in the next argument, or in
//        the m-th argument, respectively, which must be of type int.  If
//        the precision is given as just '.', the precision is taken to be
//        zero.  A negative precision is taken as if the precision were
//        omitted.  This gives the minimum number of digits to appear for
//        d, i, o, u, x, and X conversions, the number of digits to appear
//        after the radix character for a, A, e, E, f, and F conversions,
//        the maximum number of significant digits for g and G conversions,
//        or the maximum number of characters to be printed from a string
//        for s and S conversions.

//		Base
//		for base conversions b and B, follows a circumflex('^')
//		can be in the range of 2-36, by default, 2 is selected

// typedef enum e_print_type_flag
// {
// 	LOWERCASE_HH = 0x1,				// A following integer conversion
//									// corresponds to a signed char or
//									// unsigned char argument,
// 	LOWERCASE_H = 0x2,				// A following integer conversion
//									// corresponds to a short or 
//									// unsigned short argument
// 	LOWERCASE_L = 0x4,				// A following integer conversion
//									// corresponds to a long or
//									// unsigned long argument
// 	LOWERCASE_LL = 0x8,				// A following integer conversion
//									// corresponds to a long long or
//									// unsigned long long argument,
// 	UPPERCASE_L = 0x10,				// ignored for now A following
//									//a, A, e, E, f, F, g, or G conversion 
//									// corresponds to a long double argument. 
//									// (C99 allows %LF, but SUSv2 does not.)
// 	LLL = 0x18,						//L or ll
// 	LOWERCASE_Z = 0x20,				// A following integer conversion
//									// corresponds to a size_t or
//									// ssize_t argument
// 	LOWERCASE_J = 0x40,				// ignored for now  A following integer
//									//conversion corresponds to an intmax_t or
//									//uintmax_t argument,
// 	LOWERCASE_T = 0x80,				// ignored for now A following integer
//									//conversion corresponds to a ptrdiff_t
//									//argument,
// 	LENGTH_MODIFIER = 0xFF,			// bit mask to see if any
//									// length modification takes place
// 	LOWERCASE_I = 0x100,			//integer
// 	LOWERCASE_D = 0x200,			//integer, decimal
// 	SIGNED_INT = 0x300,				//integer (i, d)
// 	LOWERCASE_O = 0x400,			//octal
// 	LOWERCASE_U = 0x800,			//unsigned
// 	LOWERCASE_X = 0x1000,			//hexadecimal
// 	UPPERCASE_X = 0x2000,			//HEXADECIMAL
// 	CONVERSION_UNSIGNED = 0x3C00,	//unsigned int (ouxX)
// 	CONVERSION_INT = 0x3F00,		// "integer conversion"
//									// stands for d, i, o, u, x, or X
// 	LOWERCASE_E = 0x4000,			//
// 	UPPERCASE_E = 0x8000,			//
// 	LOWERCASE_F = 0x10000,			//
// 	UPPERCASE_F = 0x20000,			//
// 	LOWERCASE_G = 0x40000,			//
// 	UPPERCASE_G = 0x80000,			//
// 	LOWERCASE_A = 0x100000,			//
// 	UPPERCASE_A = 0x200000,			//
// 	CONVERSION_FLOAT = 0x3FC00,		// a, A, e, E, f, F, g, or G
// 	LOWERCASE_C = 0x400000,			//char
// 	LOWERCASE_S = 0x800000,			//string
// 	LOWERCASE_P = 0x1000000,		//pointer
// 	UPPERCASE_C = 0x2000000,		//colours and formating
// 	LOWERCASE_B = 0x4000000,		//binary unsigned int
									//(maybe change to signed base?)
// 	UPPERCASE_B = 0x8000000,		//bases unsigned int
// 	UPPERCASE_P = 0x10000000,		//Fixed point numbers
// 	UPPERCASE_Q = 0x20000000,		// dunno?
// 	PERCENTAGE = 0x40000000			// percentage
// }	t_type_flag;

typedef enum e_print_type_flag
{
	LOWERCASE_HH = 0x1,
	LOWERCASE_H = 0x2,
	LOWERCASE_L = 0x4,
	LOWERCASE_LL = 0x8,
	UPPERCASE_L = 0x10,
	LLL = 0x18,
	LOWERCASE_Z = 0x20,
	LOWERCASE_J = 0x40,
	LOWERCASE_T = 0x80,
	LENGTH_MODIFIER = 0xFF,
	LOWERCASE_I = 0x100,
	LOWERCASE_D = 0x200,
	SIGNED_INT = 0x300,
	LOWERCASE_O = 0x400,
	LOWERCASE_U = 0x800,
	LOWERCASE_X = 0x1000,
	UPPERCASE_X = 0x2000,
	CONVERSION_UNSIGNED = 0x8003C00,
	CONVERSION_INT = 0x3F00,
	LOWERCASE_E = 0x4000,
	UPPERCASE_E = 0x8000,
	LOWERCASE_F = 0x10000,
	UPPERCASE_F = 0x20000,
	LOWERCASE_G = 0x40000,
	UPPERCASE_G = 0x80000,
	LOWERCASE_A = 0x100000,
	UPPERCASE_A = 0x200000,
	CONVERSION_FLOAT = 0x3FC00,
	LOWERCASE_C = 0x400000,
	LOWERCASE_S = 0x800000,
	LOWERCASE_P = 0x1000000,
	UPPERCASE_C = 0x2000000,
	LOWERCASE_B = 0x4000000,
	UPPERCASE_B = 0x8000000,
	UPPERCASE_P = 0x10000000,
	UPPERCASE_Q = 0x20000000,
	PERCENTAGE = 0x40000000
}	t_type_flag;

typedef enum e_print_value_flag
{
	SIGNED_CHAR = 0x1,
	UNSIGNED_CHAR = 0x2,
	SIGNED_SHORT = 0x4,
	UNSIGNED_SHORT = 0x8,
	INT = 0x10,
	UNSIGNED_INT = 0x20,
	LONG = 0x40,
	UNSIGNED_LONG = 0x80,
	LONG_LONG = 0x100,
	UNSIGNED_LONG_LONG = 0x200,
	DOUBLE = 0x400,
	LONG_DOUBLE = 0x800,
	SIZE_T = 0x1000,
	CHAR_POINTER = 0x2000,
	VOID_POINTER = 0x4000,
}	t_value_flag;

typedef union u_value
{
	signed char			sc;
	unsigned char		uc;
	signed short		ss;
	unsigned short		us;
	int					i;
	unsigned int		ui;
	long				l;
	unsigned long		ul;
	long long			ll;
	unsigned long long	ull;
	float				f;
	double				d;
	long double			ld;
	size_t				st;
	char				*s;
	void				*p;
}	t_value;

// STRUCTURES
// LIBFT structure

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// FT_PRINTF structure

// type: 0 - just text, 1 - %[stuff]
typedef struct s_pf_info
{
	const char		*orig;
	char			*out;
	char			*red;
	char			*green;
	char			*blue;
	int				type;
	int				outlen;
	int				flag;
	int				type_flag;
	int				value_flag;
	unsigned int	field_width;
	unsigned int	precision;
	unsigned int	baselen;
	t_value			value;
}				t_pf_info;

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

//EXTRA RGB UNION PRINTF UNION

//enum flags printf

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

// string stuff
char			*ft_stringcopy(char const *str);

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

// split
char			**ft_copy_split(char **split);
void			ft_free_split(char ***splitptr);
void			ft_put_split(char **split);
int				ft_split_add(char ***split, char *s, int n);
int				ft_split_rm(char ***split, int n);
int				ft_splitlen(char **split);

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

//	ft_printf.c
int				ft_printf(const char *s, ...);
//int			ft_fprintf(FILE *restrict stream, const char *s, ...);
int				ft_dprintf(int fd, const char *s, ...);
int				ft_sprintf(char *str, const char *s, ...);
int				ft_snprintf(char *str, size_t size, const char *s, ...);

//	ft_vprintf.c
int				ft_vprintf(const char *s, va_list arg);
//int			ft_vfprintf(FILE *restrict stream, const char *s, va_list arg);
int				ft_vdprintf(int fd, const char *s, va_list arg);
int				ft_vsprintf(char *str, const char *s, va_list arg);
int				ft_vsnprintf(char *str,
					size_t size, const char *s, va_list arg);

//ft_utils?
int				ft_process_list(t_list *lst);
char			*ft_strjoin_freeleft(char *s1, char const *s2);
char			*ft_strjoin_freeright(char const *s1, char *s2);
char			*ft_strjoin_freeboth(char *s1, char *s2);
void			ft_clear_pf_data(void *vdata);
char			*ft_ultoa_base(unsigned long long n,
					char *basestr, int baselen);
char			*ft_ltoa_base(long long n, char *basestr, int baselen);
char			*ft_string_copy_n(char const *str, int n);
char			*ft_print_lst_to_string(t_list *lst, int *len);

int				ft_snpf_strncpy(char *str, char *temp, size_t size, int len);

//	ft_utils_pad.c
int				ft_padright_char(int i, char c, char **s);
int				ft_padleft_char(int i, char c, char **s);
int				ft_padright(int i, char c, char **s);
int				ft_padleft(int i, char c, char **s);

//	ft_utils_flags_prec_width.c
int				ft_signed_flags(t_pf_info *data);
int				ft_unsigned_flags(t_pf_info *data);
int				ft_field_width(t_pf_info *data);
int				ft_process_precision(t_pf_info *data);

//	ft_process_unsigned.c 
int				ft_process_prcu(t_pf_info *data);
int				ft_process_prco(t_pf_info *data);
int				ft_process_prcx(t_pf_info *data);
int				ft_process_prcx2(t_pf_info *data);
int				ft_process_prcb2(t_pf_info *data);

//	ft_process_other.c
int				ft_process_prcint(t_pf_info *data);
int				ft_process_prc(t_pf_info *data);
int				ft_process_prcchr(t_pf_info *data);
int				ft_process_prcstr(t_pf_info *data);
int				ft_process_prcptr(t_pf_info *data);

//	ft_process_colours.c 
int				ft_process_prcclr(t_pf_info *data);

//	ft_init0.c
char			*ft_get_print_string(va_list arg, const char *s, int *len);
void			ft_print_list(t_list *lst);

//	ft_init1.c
t_list			*ft_process_input_string(const char *s);
void			ft_init_flags(int *i, t_pf_info *data);
void			ft_init_field_width(int *i, int *err,
					t_pf_info *data, va_list arg);

//	ft_init2.c
void			ft_init_precision(int *i, int *err,
					t_pf_info *data, va_list arg);
void			ft_init_modifiers(int *i, t_pf_info *data);
int				ft_get_int_value(t_pf_info *data, va_list arg);
int				ft_init_int(char c, t_pf_info *data, va_list arg);

//	ft_init3.c
int				ft_get_unsigned_int_value(t_pf_info *data, va_list arg);
int				ft_init_unsigned(char c, t_pf_info *data, va_list arg);
int				ft_get_double_value(t_pf_info *data, va_list arg);
int				ft_init_double(char c, t_pf_info *data, va_list arg);

//	ft_init4.c
int				ft_init_pointer(char c, t_pf_info *data, va_list arg);
int				ft_init_conversion(int i, t_pf_info *data, va_list arg);
int				ft_init_list(va_list arg, t_list *lst);

//	ft_fixtoa. + temp;
char			*ft_fixtoa(long long n, unsigned int fixbits);
char			*ft_fixstr(long long n, int declen, char *whole, char *decimal);
int				ft_process_prcfix(t_pf_info *data);
int				ft_fix_prec(t_pf_info *data);

// void			ft_putstuff(va_list arg, const char *s, int *q, t_output *t);
// void			ft_writestuff(int fd, const char *s, int *q);
// int				ft_pf_putchar_fd(char c, int fd, t_output *t);
// int				ft_print_char_fd(char s, int fd, t_output *t);
// char			*ft_string_pointer(void *mem);
// int				ft_putpointer_fd(void *mem, int fd, t_output *t);
// int				ft_print_pointer_fd(void *mem, int fd);
// int				ft_putstring_fd(char *s, int fd, t_output *t);
// int				ft_print_string_fd(char *s, int fd, t_output *t);
// int				ft_putunsigned_fd(unsigned int u, int fd, t_output *t);
// int				ft_print_unsigned_fd(unsigned int u, int fd, t_output *t);
// char			*ft_string_unsigned(unsigned int u);
// int				ft_putinteger_fd(int d, int fd, t_output *t);
// int				ft_print_integer_fd(int d, int fd, t_output *t);
// char			*ft_string_integer(int d);
// int				ft_puthexabig_fd(unsigned int h, int fd, t_output *t);
// int				ft_print_hexabig_fd(unsigned int h, int fd, t_output *t);
// char			*ft_string_hexabig(unsigned int h);
// int				ft_puthexasmall_fd(unsigned int h, int fd, t_output *t);
// int				ft_print_hexasmall_fd(unsigned int h, int fd, t_output *t);
// char			*ft_string_hexasmall(unsigned int h);
// void			ft_initialise_struct(t_output *t);
// void			ft_dash_struct(t_output *t, int n);
// void			ft_prefill_struct(t_output *t, const char *s);
// int				ft_get_num(t_output *t, const char *s, int i);

// char			*ft_padchar(char *s, int len, t_output *t);
// char			*ft_padint(char *s, t_output *t);
// char			*ft_precint(char *s, t_output *t);
// int				ft_putbasebig_fd(unsigned int b, int fd, t_output *t);
// int				ft_print_basebig_fd(unsigned int b, int fd, t_output *t);
// char			*ft_string_basebig(unsigned int b, t_output *t);
// int				ft_putbinocthex_fd(void *b, int fd, t_output *t);
// int				ft_print_binocthex_fd(unsigned char b, int fd, t_output *t);
// char			*ft_string_binocthex(unsigned char b, t_output *t);
// int				ft_putcolour_fd(int fd, t_output *t);
// int				ft_print_colour_fd(int fd, t_output	*t);
// int				ft_print_colour_fd_0(int fd, t_output *t);
// int				ft_print_colour_fd_1(int fd, t_output *t);
// int				ft_print_colour_fd_2(int fd, t_output *t);
// int				ft_print_colour_fd_3(int fd, t_output *t);
// int				ft_print_colour_fd_4(int fd, t_output *t);
// int				ft_print_colour_fd_5(int fd, t_output *t);
// int				ft_print_colour_fd_6(int fd, t_output *t);
// int				ft_print_colour_fd_7(int fd, t_output *t);
// int				ft_print_colour_fd_8(int fd, t_output *t);
// int				ft_print_colour_fd_9(int fd, t_output *t);

#endif
