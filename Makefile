SERVER = server

CLIENT = client

INC = -I ./
SRC_SERVER = server.c
SRC_CLIENT = client.c
UTILS = minitalk_utils.c minitalk_utils2.c

FLAGS = -Wall -Wextra -Werror 

all: $(SERVER) $(CLIENT)

$(SERVER) : 
	@gcc $(FLAGS) $(INC) $(SRC_SERVER) $(UTILS) -o $(SERVER)
$(CLIENT) : 
	@gcc $(FLAGS) $(INC) $(SRC_CLIENT) $(UTILS) -o $(CLIENT)

clean:
	@rm -rf $(SERVER) $(CLIENT) *dSYM *.gch

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all