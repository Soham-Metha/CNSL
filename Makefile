BUILDS 	:= ./builds
CC 		:= gcc
FLAGS 	:= -Wall -Wextra -Werror -Wfatal-errors -O3 -std=c99
SRC 	:= $(wildcard src/common/*.c)
H_S_SRC	:= $(wildcard src/hamming/sender/*.c)
H_R_SRC	:= $(wildcard src/hamming/receiver/*.c)
H_T_SRC	:= $(wildcard tests/*.c)
S_S_SRC	:= $(wildcard src/slidingWindow/sender/*.c)
LIBS 	:= -I "./include/hamming/" -I "./include/" -I "./include/slidingWindow/"

H_SENDER:= $(BUILDS)/HammingSender
H_RECEVR:= $(BUILDS)/HammingReceiver
H_TESTER:= $(BUILDS)/HammingTester

S_SENDER:= $(BUILDS)/SlidingSender

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
	@$(CC) $(FLAGS) $(H_S_SRC) $(SRC) $(LIBS) -o $@

$(H_RECEVR): | $(BUILDS)
	@$(CC) $(FLAGS) $(H_R_SRC) $(SRC) $(LIBS) -o $@

$(H_TESTER): | $(BUILDS)
	@$(CC) $(FLAGS) $(H_T_SRC) $(LIBS) -o $@
	@$@ $(H_SENDER) $(H_RECEVR) $(MSG_IN) $(MSG_EN) $(MSG_OUT)

$(S_SENDER): | $(BUILDS)
	@$(CC) $(FLAGS) $(S_S_SRC) $(SRC) $(LIBS) -o $@
	@$@ $(MSG_IN)

$(BUILDS):
	@mkdir -p builds