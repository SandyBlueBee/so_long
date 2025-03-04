# *********************************************************************************************** #
# *                                                                                             * #
# *                                          MAKEFILE 🔨                                        * #
# *                                         👩‍🔧 LIBFT 🏋🏼‍♀️                                         * #
# *                                                                                             * #
# *********************************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

# *********************************************************************************************** #
# ******************************************DIRECTORIES****************************************** #
# *********************************************************************************************** #

OBJ_DIR = build
CHECK_DIR = checkers
TRANS_DIR = transformers
PRINTF_DIR = printf
LL_DIR = linked_list
GNL_DIR = gnl

# *********************************************************************************************** #
# *******************************************SRC FILES******************************************* #
# *********************************************************************************************** #

CHECKERS =		${CHECK_DIR}/ft_isalnum.c \
				${CHECK_DIR}/ft_isalpha.c \
				${CHECK_DIR}/ft_isascii.c \
				${CHECK_DIR}/ft_isdigit.c \
				${CHECK_DIR}/ft_isprint.c \
				${CHECK_DIR}/ft_memchr.c \
				${CHECK_DIR}/ft_memcmp.c \
				${CHECK_DIR}/ft_strchr.c \
				${CHECK_DIR}/ft_strlen.c \
				${CHECK_DIR}/ft_strncmp.c \
				${CHECK_DIR}/ft_strnstr.c \

TRANSFORMERS =	${TRANS_DIR}/ft_atoi.c \
				${TRANS_DIR}/ft_bzero.c \
				${TRANS_DIR}/ft_calloc.c \
				${TRANS_DIR}/ft_itoa.c \
				${TRANS_DIR}/ft_memcpy.c \
				${TRANS_DIR}/ft_memmove.c \
				${TRANS_DIR}/ft_memset.c \
				${TRANS_DIR}/ft_split.c \
				${TRANS_DIR}/ft_strdup.c \
				${TRANS_DIR}/ft_striteri.c \
				${TRANS_DIR}/ft_strjoin.c \
				${TRANS_DIR}/ft_strlcat.c \
				${TRANS_DIR}/ft_strlcpy.c \
				${TRANS_DIR}/ft_strmapi.c \
				${TRANS_DIR}/ft_strrchr.c \
				${TRANS_DIR}/ft_strtrim.c \
				${TRANS_DIR}/ft_substr.c \
				${TRANS_DIR}/ft_tolower.c \
				${TRANS_DIR}/ft_toupper.c \

PRINTF =		${PRINTF_DIR}/ft_printf.c \
				${PRINTF_DIR}/ft_print_uns.c \
				${PRINTF_DIR}/ft_print_hex.c \
				${PRINTF_DIR}/ft_print_p.c \
				${PRINTF_DIR}/ft_char_to_hex.c \
				${PRINTF_DIR}/ft_putchar_fd.c \
				${PRINTF_DIR}/ft_putstr_fd.c \
				${PRINTF_DIR}/ft_putendl_fd.c \
				${PRINTF_DIR}/ft_putnbr_fd.c

LINKED_LIST =  	${LL_DIR}/ft_lstnew.c \
				${LL_DIR}/ft_lstadd_front.c \
				${LL_DIR}/ft_lstsize.c \
				${LL_DIR}/ft_lstlast.c \
				${LL_DIR}/ft_lstadd_back.c \
				${LL_DIR}/ft_lstdelone.c \
				${LL_DIR}/ft_lstclear.c \
				${LL_DIR}/ft_lstiter.c \
				${LL_DIR}/ft_lstmap.c \

GETNEXTLINE =	${GNL_DIR}/get_next_line.c

SOURCES = $(CHECKERS) $(TRANSFORMERS) $(PRINTF) $(LINKED_LIST) $(GETNEXTLINE)

# Replace source file paths with object file paths
OBJ = $(patsubst $(CHECK_DIR)/%.c, $(OBJ_DIR)/%.o, $(CHECKERS)) \
      $(patsubst $(TRANS_DIR)/%.c, $(OBJ_DIR)/%.o, $(TRANSFORMERS)) \
      $(patsubst $(PRINTF_DIR)/%.c, $(OBJ_DIR)/%.o, $(PRINTF)) \
      $(patsubst $(LL_DIR)/%.c, $(OBJ_DIR)/%.o, $(LINKED_LIST)) \
      $(patsubst $(GNL_DIR)/%.c, $(OBJ_DIR)/%.o, $(GETNEXTLINE))



# OBJ =	${CHECKERS:${CHECK_DIR}/.c={OBJ_DIR}.o} ${TRANSFORMERS:${TRANS_DIR}/.c={OBJ_DIR}/.o} \
# 				${PRINTF:${PRINTF_DIR}/.c={OBJ_DIR}.o}/ ${LINKED_LIST:${LL_DIR}/.c={OBJ_DIR}/.o} \
# 				${GETNEXTLINE:${GNL_DIR}/.c={OBJ_DIR}/.o} \

HEADERS = libft.h printf/ft_printf.h gnl/get_next_line.h

# *********************************************************************************************** #
# ********************************************MAKE*********************************************** #
# *********************************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(CHECK_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TRANS_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LL_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ]; then rm -rf $(OBJ_DIR); fi

fclean: clean
	@rm -f ${NAME} 

re: fclean all

.PHONY: all bonus clean fclean re