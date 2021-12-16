EXECUTABLE = 	gomoku

SRC_DIR =		src/

SRC_SD =		shared/models/Position.cpp			

SRC_GE = 		game_engine/Game.cpp				\
				game_engine/DoubleThree.cpp			\
				game_engine/CaptureStone.cpp		\
				game_engine/Mandatory.cpp			\
				game_engine/GameOver.cpp			\
				game_engine/UniqueFive.cpp			\
				game_engine/TwoFives.cpp			\
				game_engine/Data.cpp			

SRC_AI =		ai/AI.cpp							\
				ai/SearchSpace.cpp

SRC_UI =		ui/UI.cpp							\
				ui/Click.cpp						\
				ui/DisplayInfo.cpp					\
				ui/DisplayGame.cpp					\
				ui/Button.cpp

SRC_FILES = 	gomoku.cpp	 						\
				$(SRC_SD)							\
				$(SRC_GE)							\
				$(SRC_AI)							\
				$(SRC_UI)

SRC = 			$(addprefix $(SRC_DIR), $(SRC_FILES))

HEADER_SD =		shared/models						\
				shared/exceptions					\
				shared/

HEADER_GE =		game_engine

HEADER_AI =		AI

HEADER_UI =		ui

HEADER_DIR =	$(HEADER_SD)						\
				$(HEADER_GE)						\
				$(HEADER_AI)						\
				$(HEADER_UI)

HEADER_SRC =	$(addprefix $(SRC_DIR), $(HEADER_DIR))

HEADER_INC =    $(addprefix -I, $(HEADER_SRC))

FRAMEWORK_INC = $(addprefix -l, $(FRAMEWORK))

FRAMEWORK = 	SDL2-2.0.0 						\
				SDL2_image						\
				SDL2_ttf						

OBJ = $(SRC:.cpp=.o)

CC = 			g++ -g
CFLAGS = 		-std=c++11 -lncurses -Qunused-arguments 
GTKMM = 		`pkg-config gtkmm-3.0 --cflags --libs`

RED = 			\033[0;31m
GREEN = 		\033[0;32m
YELLOW = 		\033[0;33m
BLUE = 			\033[0;34m
END = 			\033[0m

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE) $(FRAMEWORK_INC)
	@echo "$(BLUE)$(EXECUTABLE)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.cpp
	@echo "$(YELLOW)Compiling$(END) $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@$(CC) $(CFLAGS) $(HEADER_INC) -o $@ -c $<
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(EXECUTABLE)

re: clean all
