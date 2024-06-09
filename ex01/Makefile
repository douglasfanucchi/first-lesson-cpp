NAME=test

all: $(NAME)

files := Contact.cpp
test_files := unit/Contact.cpp asserts.cpp
test_files := $(addprefix tests/, $(test_files))

$(NAME): tests.cpp $(files) $(test_files)
	g++ -I ./ -I ./tests tests.cpp $(files) $(test_files) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all
