#=======================================#
#[FDF] Fonctions partie principale#
#=======================================#

FDF_SRC = fdf.c

COMMON_SRC = create_tab.c ft_atoi.c ft_split.c ft_strlen.c get_next_line.c get_next_line_utils.c \
				panic_button.c stock_map.c free_tab.c ft_free.c row_len.c ft_printtab.c \
				initiate_window.c end.c hook.c draw_tab.c
				
COMMON_OBJ = ${addprefix ${OBJDIR}, ${COMMON_SRC:%.c=%.o}}

FDF_OBJ = ${addprefix ${OBJDIR}, ${FDF_SRC:%.c=%.o}} ${COMMON_OBJ}

#=======================================#
#[FDF] Fonctions partie principale#
#=======================================#

FDF_BONUS_SRC = fdf_bonus.c color_bonus.c draw_tab_bonus.c hook_bonus.c initiate_window_bonus.c

FDF_BONUS_OBJ = ${addprefix ${OBJDIR}, ${FDF_BONUS_SRC:%.c=%.o}} ${COMMON_OBJ}

#====#
#Tags#
#====#

OBJDIR = ./objs/
BONUSDIR = ./bonus/
SRCDIR = ./src/
COMMONDIR = ./common/
INCLUDES = ./includes/
NAME = fdf
BONUSNAME = fdfbonus
CFLAGS = -Wall -Wextra -Werror ${SANIFLAG} -D BUFFER_SIZE=${BUFFER_SIZE}
SANIFLAG = -fsanitize=address -g
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
BUFFER_SIZE = 10000

#=========#
#Commandes#
#=========#					

${OBJDIR}%.o : ${SRCDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}
${OBJDIR}%.o : ${BONUSDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${OBJDIR}%.o : ${COMMONDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}: 						${OBJDIR} ${FDF_OBJ}
								@gcc ${CFLAGS} ${FDF_OBJ} ${MLXFLAGS} -o ${NAME}
								@printf "\e[32;3m$@ successfully build\e[0m\n"

${BONUSNAME}: 					${OBJDIR} ${FDF_BONUS_OBJ}
								@gcc ${CFLAGS} ${FDF_BONUS_OBJ} ${MLXFLAGS} -o ${BONUSNAME}
								@printf "\e[32;3m$@ successfully build\e[0m\n"

${OBJDIR}:						
								@mkdir -p ${OBJDIR}

all:							${NAME}

bonus:							${BONUSNAME}								

clean:
								@rm -rf ${OBJDIR}
								@printf "\e[31;3mClean files\e[0m\n"

fclean:							clean
								@rm -f ${NAME}
								@rm -f ${BONUSNAME}
								@printf "\e[31;3mClean exec\e[0m\n"

re:								fclean all

.PHONY:							all clean fclean re bonus
