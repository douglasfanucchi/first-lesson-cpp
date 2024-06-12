NAME=executable

files=tests.cpp Account.cpp

all: $(NAME)

$(NAME): $(files)
	@g++ $(files) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all
