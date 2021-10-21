EXECUTABLE = 	gomoku

SRC_DIR =		src/

SRC_LIB =		libraries/lib

SRC_SD =		shared/models/Position.cpp			

SRC_GE = 		game_engine/Game.cpp				\
				game_engine/DoubleThree.cpp			\
				game_engine/CaptureStone.cpp		\
				game_engine/Mandatory.cpp			\
				game_engine/GameOver.cpp			\
				game_engine/UniqueFive.cpp			\
				game_engine/TwoFives.cpp			

SRC_IA =		ia/IA.cpp						

SRC_UI =		ui/UI.cpp

SRC_FILES = 	gomoku.cpp	 						\
				$(SRC_SD)							\
				$(SRC_GE)							\
				$(SRC_IA)							\
				$(SRC_UI)
						
SRC = 			$(addprefix $(SRC_DIR), $(SRC_FILES))

HEADER_SD =		shared/models						\
				shared/exceptions					\
				shared/

HEADER_GE =		game_engine

HEADER_IA =		ia

HEADER_UI =		ui

HEADER_LIB =	libraries/include

HEADER_DIR =	$(HEADER_SD)						\
				$(HEADER_GE)						\
				$(HEADER_IA)						\
				$(HEADER_UI)

HEADER_SRC =	$(addprefix $(SRC_DIR), $(HEADER_DIR))

HEADER_INC =    $(addprefix -I, $(HEADER_SRC) $(HEADER_LIB))

LIB = $(addprefix -L, $(SRC_LIB))

LIB_VERSION_INC = $(addprefix -l, $(LIB_VERSION_SRC))

LIB_VERSION_SRC = 	SDL2-2.0.0 						\
				SDL2_image

OBJ = $(SRC:.cpp=.o)

CC = 			g++
CFLAGS = 		-std=c++11 -lncurses -Qunused-arguments 
GTKMM = 		`pkg-config gtkmm-3.0 --cflags --libs`

RED = 			\033[0;31m
GREEN = 		\033[0;32m
YELLOW = 		\033[0;33m
BLUE = 			\033[0;34m
END = 			\033[0m

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE) $(LIB_VERSION_INC)
	@echo "$(BLUE)$(EXECUTABLE)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.cpp
	@echo "$(YELLOW)Compiling$(END) $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@$(CC) $(CFLAGS) $(HEADER_INC) $(LIB) -o $@ -c $<
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(EXECUTABLE)

re: clean all
