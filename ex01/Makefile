NAME=test

all: $(NAME)

$(NAME): tests.cpp PhoneBook.cpp Contact.cpp tests/unit/Contact.cpp
	g++ -I ./ tests.cpp PhoneBook.cpp Contact.cpp tests/unit/Contact.cpp -o $(NAME)
