CFLAGC = -Wall -Wextra -Werror
CC = gcc
c_obj=$(c_src:.c=.o)
server = server 
client = client
c_src = minitalk_utils.c

all: $(server) $(client)

$(server):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o $(server)
$(client):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj) 
fclean: clean
	rm -rf $(client) $(server)
re: fclean all