NAME=phonebook

all: $(NAME)

files := Contact.cpp PhoneBook.cpp Program.cpp
files := $(addprefix src/, $(files))
test_files := unit/Contact.cpp unit/PhoneBook.cpp unit/Program.cpp asserts.cpp tests.cpp
test_files := $(addprefix tests/, $(test_files))

$(NAME): $(files) src/main.cpp
	@g++ -std=c++98 -I ./src $(files) src/main.cpp -o $@

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))

unit: $(files) $(test_files)
	@g++ -std=c++98 -I ./src -I ./tests $(files) $(test_files) -o unit
	@./unit
	@rm -rf unit

clean:
	@rm -rf $(NAME)

re: clean all
