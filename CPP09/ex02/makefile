CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -g -fsanitize=address,undefined
NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp

OBJS = ${SRCS:.cpp=.o}

all:	$(NAME)

$(NAME):	${OBJS}
		$(CXX) $(CXXFLAGS) -o $(NAME) ${OBJS}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -rf ${OBJS}
fclean: clean
	rm -rf ${NAME}

re: fclean all
