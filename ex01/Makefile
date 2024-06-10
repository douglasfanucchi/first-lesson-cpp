NAME=phonebook

all: $(NAME)

files := Contact.cpp PhoneBook.cpp
test_files := unit/Contact.cpp unit/PhoneBook.cpp asserts.cpp
test_files := $(addprefix tests/, $(test_files))

$(NAME): $(files) main.cpp
	@g++ -I ./ $(files) main.cpp -o $@

unit: tests.cpp $(files) $(test_files)
	@g++ -I . -I ./tests tests.cpp $(files) $(test_files) -o unit
	@./unit
	@rm -rf unit

clean:
	@rm -rf $(NAME)

re: clean all
