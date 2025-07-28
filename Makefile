BUILDS 	:= ./builds
CC 		:= gcc
FLAGS 	:= -Wall -Wextra -Werror -Wfatal-errors -O3 -std=c99
SRC 	:= $(wildcard src/common/*.c)
S_SRC	:= $(wildcard src/hamming/sender/*.c)
R_SRC	:= $(wildcard src/hamming/receiver/*.c)
T_SRC	:= $(wildcard tests/*.c)
LIBS 	:= -I "./include/hamming/" -I "./include/"

H_SENDER:= $(BUILDS)/HammingSender
H_RECEVR:= $(BUILDS)/HammingReceiver
H_TESTER:= $(BUILDS)/HammingTester

MSG_IN	:= ./extras/msg.txt
MSG_EN := ./extras/encoded
MSG_OUT := ./extras/text.txt

all: clean $(H_SENDER) $(H_RECEVR)
tester: clean $(H_SENDER) $(H_RECEVR) $(H_TESTER)
sender:  clean $(H_SENDER)
receiver:  clean $(H_RECEVR)
clean: | $(BUILDS)
	@rm -f $(BUILDS)/*

$(H_SENDER): | $(BUILDS)
	@$(CC) $(FLAGS) $(S_SRC) $(SRC) $(LIBS) -o $@

$(H_RECEVR): | $(BUILDS)
	@$(CC) $(FLAGS) $(R_SRC) $(SRC) $(LIBS) -o $@

$(H_TESTER): | $(BUILDS)
	@$(CC) $(FLAGS) $(T_SRC) $(LIBS) -o $@
	@$@ $(H_SENDER) $(H_RECEVR) $(MSG_IN) $(MSG_EN) $(MSG_OUT) 

$(BUILDS):
	@mkdir -p builds