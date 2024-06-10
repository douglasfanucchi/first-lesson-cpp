NAME=phonebook

all: $(NAME)

files := Contact.cpp PhoneBook.cpp
test_files := unit/Contact.cpp unit/PhoneBook.cpp unit/Program.cpp asserts.cpp
test_files := $(addprefix tests/, $(test_files))

$(NAME): $(files) main.cpp
	@g++ -I ./ $(files) main.cpp -o $@

e2e: $(NAME)
	@./tests/e2e/Program.sh $(realpath $(NAME))

unit: tests.cpp $(files) $(test_files)
	@g++ -I . -I ./tests tests.cpp $(files) $(test_files) -o unit
	@./unit
	@rm -rf unit

clean:
	@rm -rf $(NAME)

re: clean all
