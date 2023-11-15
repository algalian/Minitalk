CLIENT = client.out
SERVER = server.out

CLIENT_SRC_DIR = client
SERVER_SRC_DIR = server

CLIENT_OUTPUT_DIR = bin/client
SERVER_OUTPUT_DIR = bin/server

SRCS_CLIENT = $(CLIENT_SRC_DIR)/client.c
SRCS_SERVER = $(SERVER_SRC_DIR)/server.c

OBJS_CLIENT = $(SRCS_CLIENT:$(CLIENT_SRC_DIR)/%.c=$(CLIENT_OUTPUT_DIR)/%.o)
OBJS_SERVER = $(SRCS_SERVER:$(SERVER_SRC_DIR)/%.c=$(SERVER_OUTPUT_DIR)/%.o)

LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -I libft

all: $(SERVER_OUTPUT_DIR)/$(SERVER) $(CLIENT_OUTPUT_DIR)/$(CLIENT)

$(SERVER_OUTPUT_DIR)/$(SERVER): $(OBJS_SERVER)
	@make -sC libft
	@$(CC) $(OBJS_SERVER) $(LIBFT) -o $@
	@mv /Users/algalian/Documents/minitalk/bin/server/server.out /Users/algalian/Documents/minitalk 

$(CLIENT_OUTPUT_DIR)/$(CLIENT): $(OBJS_CLIENT)
	@make -sC libft
	@$(CC) $(OBJS_CLIENT) $(LIBFT) -o $@
	@mv /Users/algalian/Documents/minitalk/bin/client/client.out /Users/algalian/Documents/minitalk 

$(CLIENT_OUTPUT_DIR)/%.o: $(CLIENT_SRC_DIR)/%.c
	@mkdir -p $(CLIENT_OUTPUT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OUTPUT_DIR)/%.o: $(SERVER_SRC_DIR)/%.c
	@mkdir -p $(SERVER_OUTPUT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -sC libft
	@rm -rf $(CLIENT_OUTPUT_DIR)
	@rm -rf $(SERVER_OUTPUT_DIR)

fclean: clean
	@make fclean -sC libft
	@rm -f $(CLIENT)
	@rm -f $(SERVER)

re: fclean all