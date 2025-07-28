BUILDS 	:= ./builds
CC 		:= gcc
FLAGS 	:= -Wall -Wextra -Werror -Wfatal-errors -O3 -std=c99
SRC 	:= $(wildcard src/common/*.c)
S_SRC	:= $(wildcard src/hamming/sender/*.c)
R_SRC	:= $(wildcard src/hamming/receiver/*.c)
T_SRC	:= $(wildcard tests/*.c)
LIBS 	:= -I "./include/hamming/" -I "./include/"

SENDER 	:= $(BUILDS)/HammingSender
RECEIVER:= $(BUILDS)/HammingReceiver
TESTER 	:= $(BUILDS)/Tester

MSG_IN	:= ./extras/msg.txt
MSG_EN := ./extras/encoded
MSG_OUT := ./extras/text.txt

all: clean $(SENDER) $(RECEIVER)
tester: clean $(SENDER) $(RECEIVER) $(TESTER)
sender:  clean $(SENDER)
receiver:  clean $(RECEIVER)
clean: | $(BUILDS)
	@rm -f $(BUILDS)/*

$(SENDER): | $(BUILDS)
	@$(CC) $(FLAGS) $(S_SRC) $(SRC) $(LIBS) -o $@

$(RECEIVER): | $(BUILDS)
	@$(CC) $(FLAGS) $(R_SRC) $(SRC) $(LIBS) -o $@

$(TESTER): | $(BUILDS)
	@$(CC) $(FLAGS) $(T_SRC) $(LIBS) -o $@
	@$@ $(SENDER) $(RECEIVER) $(MSG_IN) $(MSG_EN) $(MSG_OUT) 

$(BUILDS):
	@mkdir -p builds