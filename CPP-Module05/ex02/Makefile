#	====================		Directories		====================

SOURCES = srcs
HEADERS = headers
OBJECTS_DIRECTORY = objs

#	====================		Files      		====================

NAME = ex02

FILES = main.cpp Bureaucrat.cpp AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp

OBJECTS = $(addprefix $(OBJECTS_DIRECTORY)/, $(FILES:.cpp=.o))

#	====================		Flags      		====================

COMPILER = c++

I = -I $(HEADERS)

FLAGS = -Wall -Wextra -Werror -std=c++98

WBLOCK = --no-print-directory

RM = rm -rf

#	====================		Colors     		====================

GREEN = \033[0;32m
YELLOW = \033[0;33m
B_YELLOW = \033[1;33m
RESET = \033[0m

#	====================		Rules      		====================

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(COMPILER) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)[Executable Created]$(RESET)"

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES)/%.cpp
	@$(COMPILER) $(FLAGS) $(I) -c $< -o $@

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

clean:
	@$(RM) $(OBJECTS_DIRECTORY)
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) binary files deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) deleted$(RESET)"

re: fclean all

leak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re leak