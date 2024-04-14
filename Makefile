###############################################################################
######                            PROPERTIES                             ######
###############################################################################

CXX			= c++
RM			= rm -rf
CXXFLAGS	= -Wall -Wextra -Werror -MD -MP -g
LINKFLAGS	= -lncursesw
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= ft_shmup
SRCSDIR		= srcs
SRCS		= \
			${SRCSDIR}/entity/utils/BaseEntity.cpp \
			${SRCSDIR}/entity/utils/Point.cpp \
			${SRCSDIR}/entity/utils/Bullet.cpp \
			${SRCSDIR}/entity/player/Player.cpp \
			${SRCSDIR}/entity/enemy/Enemy.cpp \
			${SRCSDIR}/entity/enemy/EnemyFactory.cpp \
			${SRCSDIR}/Game.cpp \
			${SRCSDIR}/main.cpp

OBJSDIR		= objs
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.d))

###############################################################################
######                               RULES                               ######
###############################################################################

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CXX) $(LINKFLAGS) -o $@ $^

${OBJSDIR}/%.o	: %.cpp
		@mkdir -p $(dir $@)
		${CXX} ${CXXFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	:
		$(RM) $(OBJSDIR) $(NAME)

re		:
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

run		:
		$(MAKE) re
		./$(NAME)

test	:
		$(MAKE) re
		valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

-include $(DEPS)

.PHONY: all clean fclean bonus re test run
