BUILDS 	:= ./builds
CC 		:= gcc
FLAGS 	:= -Wall -Wextra -Werror -Wfatal-errors -O3 -std=c99
LIBS 	:= -I "./include/hamming/" -I "./include/" -I "./include/slidingWindow/"

SRC 	:= $(wildcard src/common/*.c)
RECIVR_	:= $(wildcard src/receiver/*.c)
SENDER_	:= $(wildcard src/sender/*.c)

SENDER	:= $(BUILDS)/Sender
RECIVR	:= $(BUILDS)/Receiver

INPUT 	:= extras/msg.txt
INTER 	:= extras/encoded.bin
OUTPT 	:= extras/text.txt
EXPNO 	:= 3

all: clean $(SENDER) $(RECIVR)

sender: $(SENDER)
receiver: $(RECIVR)

run_sender: $(SENDER)
	@$(SENDER) $(INPUT) $(INTER) $(EXPNO)

run_receiver: $(RECIVR)
	@$(RECIVR) $(INTER) $(OUTPT) $(EXPNO)

run_diff:
	@diff $(INPUT) $(OUTPT)

tester: all run_sender run_receiver run_diff

clean: | $(BUILDS)
	@rm -f $(BUILDS)/*
	@rm -f $(INTER)
	@rm -f $(OUTPT)

$(SENDER): | $(BUILDS)
	@$(CC) $(FLAGS) $(SENDER_) $(SRC) $(LIBS) -o $@

$(RECIVR): | $(BUILDS)
	@$(CC) $(FLAGS) $(RECIVR_) $(SRC) $(LIBS) -o $@

$(BUILDS):
	@mkdir -p builds