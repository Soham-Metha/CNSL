BUILDS 	:= ./builds
CC 		:= gcc
FLAGS 	:= -Wall -Wextra -Werror -Wfatal-errors -O3 -std=c99
SRC 	:= $(wildcard src/hamming/common/*.c)
S_SRC	:= $(wildcard src/hamming/sender/*.c)
R_SRC	:= $(wildcard src/hamming/receiver/*.c)
LIBS 	:= -I "./include/hamming/"

SENDER 	:= $(BUILDS)/HammingSender
RECEIVER:= $(BUILDS)/HammingReceiver

MSG_IN	:= ./extras/msg.txt
MSG_EN := ./extras/encoded
MSG_OUT := ./extras/text.txt

all: clean $(SENDER) $(RECEIVER)
sender:  clean $(SENDER)
receiver:  clean $(RECEIVER)
clean: | $(BUILDS)
	@rm -f $(BUILDS)/*

$(SENDER): | $(BUILDS)
	@$(CC) $(FLAGS) $(S_SRC) $(SRC) $(LIBS) -o $@
	@$@ $(MSG_IN) $(MSG_EN)

$(RECEIVER): | $(BUILDS)
	@$(CC) $(FLAGS) $(R_SRC) $(SRC) $(LIBS) -o $@
	@$@ $(MSG_EN) $(MSG_OUT)

$(BUILDS):
	@mkdir -p builds