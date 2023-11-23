CLIENT = client.out
CLIENT2 = client2.out
SERVER = server.out

CLIENT_SRC_DIR = client
SERVER_SRC_DIR = server

CLIENT_OUTPUT_DIR = obj/client
SERVER_OUTPUT_DIR = obj/server

SRCS_CLIENT = $(CLIENT_SRC_DIR)/client.c	
SRCS_CLIENT2 = $(CLIENT_SRC_DIR)/client2.c		
							
SRCS_SERVER = $(SERVER_SRC_DIR)/server.c

OBJS_CLIENT = $(SRCS_CLIENT:$(CLIENT_SRC_DIR)/%.c=$(CLIENT_OUTPUT_DIR)/%.o)
OBJS_CLIENT2 = $(SRCS_CLIENT:$(CLIENT_SRC_DIR)/%.c=$(CLIENT_OUTPUT_DIR)/%.o)
OBJS_SERVER = $(SRCS_SERVER:$(SERVER_SRC_DIR)/%.c=$(SERVER_OUTPUT_DIR)/%.o)

LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -I libft


$(SERVER_OUTPUT_DIR)/$(SERVER): $(OBJS_SERVER)
	@make -sC libft
	@$(CC) $(OBJS_SERVER) $(LIBFT) -o $@

$(CLIENT_OUTPUT_DIR)/$(CLIENT): $(OBJS_CLIENT)
	@make -sC libft
	@$(CC) $(OBJS_CLIENT) $(LIBFT) -o $@

$(CLIENT_OUTPUT_DIR)/$(CLIENT2): $(OBJS_CLIENT2)
	@make -sC libft
	@$(CC) $(OBJS_CLIENT) $(LIBFT) -o $@

$(CLIENT_OUTPUT_DIR)/%.o: $(CLIENT_SRC_DIR)/%.c
	@mkdir -p $(CLIENT_OUTPUT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OUTPUT_DIR)/%.o: $(SERVER_SRC_DIR)/%.c
	@mkdir -p $(SERVER_OUTPUT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


all: $(SERVER_OUTPUT_DIR)/$(SERVER) $(CLIENT_OUTPUT_DIR)/$(CLIENT) $(CLIENT_OUTPUT_DIR)/$(CLIENT2)
	@cd obj  && mv ../$(SERVER_OUTPUT_DIR)/$(SERVER) ../ && mv ../$(CLIENT_OUTPUT_DIR)/$(CLIENT) ../ && mv ../$(CLIENT_OUTPUT_DIR)/$(CLIENT2) ../
	
clean:
	@make clean -sC libft
	@rm -rf $(CLIENT_OUTPUT_DIR)
	@rm -rf $(SERVER_OUTPUT_DIR)

fclean: clean
	@make fclean -sC libft
	@rm -f $(CLIENT)
	@rm -f $(CLIENT2)
	@rm -f $(SERVER)

re: fclean all	

.PHONY: all bonus clean fclean re server client norminette



