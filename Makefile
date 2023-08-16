# define el compilador a utilizar
CC = gcc

# Opciones de compilación
CFLAGS = -g -Wall -Wextra -Werror

# Crea una biblioteca estática utilizando (ar)
# ar -> crea biblioteca
# r -> remplaza o agrega archivos a la biblioteca
# c -> crea biblioteca si no existe
# s -> agrega información de índice a la biblioteca, para acceder más rapido
LIB = ar rcs

# Define la ruta al directorio donde se encuentra libft
LIBFT_DIR = ./libft

# Ruta completa al archivo de la libreria libft++.a
LIBFT = $(LIBFT_DIR)/libft.a

# Define el nombre del programa que se generá
NAME = push_swap

# Define el archivo fuente del programa push_swap
# Agrega aquí todos tus archivos fuente
SRCS = push_swap.c utils_stacks.c utils_movements.c leaks.c utils_algorithm.c\
		utils_towers.c utils_nodes.c utils_cost.c utils_move_a.c utils_swap.c\
		utils_rotate.c utils_push.c utils_cost.c utils_reverse.c utils_move_b.c\
		utils_reverses_nodes.c utils_rotates_nodes.c utils_cost1.c utils_move.c\
		utils_split_stack.c 
		
# Define los archivos objeto generados a partir de los fuente
OBJS = $(SRCS:.c=.o)
.SECONDARY: $(OBJS)
# Agrega los archivos objeto a la lista de archivos secundarios


all: $(LIBFT) $(NAME)

# Compila la libreria libft. -C se utiliza para cambiar de directorio
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Se utiliza el compilador (CC) con las opciones (CFLAGS) para crear
# el programa (NAME) a partir de los archivos objetos ($^)
# Especificando la ubicación de la libreria (LIBFT_DIR) y se enlaza (lft)
# -o especifica el nombre del archivo de salida
# $@ se refiere al objetivo de la regla, nombre del programa (NAME)
# "-o $@" establece el nombre del archivo de salida como el nombre del programa
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

# Regla para compilar todos los archivos fuentes .c en archivos objetos .o
# Se utiliza el compilador (CC) con las flags (CFLAGS) para compilar cada archivo
# fuente ($<) en su archivo objeto ($@). Se especifica la ubicación de los archivos
# de inclusión de la libreria libft (-I$(LIBFT_DIR))
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT_DIR)
	
# utiliza el comando  make  para ejecutar la regla  clean  en el directorio de la
# librería libft. Esto se utiliza para limpiar los archivos objeto generados 
# durante la compilación de la librería. 
# rm -f $(OBJS) : Aquí se utiliza el comando  rm  para eliminar los archivos objeto generados.
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# Esta línea establece la regla  fclean  como una dependencia de la regla  clean 
# Esto significa que al ejecutar  make fclean , primero se ejecutará  make clean 
# se utiliza el comando  make  para ejecutar la regla  fclean  en el directorio de la librería libft
# tiliza para limpiar los archivos generados durante la compilación de la librería.
# utiliza el comando  rm  para eliminar el programa generado
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# al ejecutar  make re , primero se ejecutará  make fclean  y luego  make all .
re: fclean all

# reglas ficticias (phony). Esto se utiliza para evitar conflictos si hay archivos o directorios con los mismos nombres que las reglas. 
.PHONY: all clean fclean re
