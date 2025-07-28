BUILDS 	:= ./builds
CC 		:= gcc
FLAGS 	:= -Wall -Wextra -Werror -Wfatal-errors -O3 -std=c99
SRC 	:= $(wildcard src/*.c)
LIBS 	:= -I "./include/"

SENDER 	:= $(BUILDS)/Sender
RECEIVER:= $(BUILDS)/Receiver

MSG_IN	:= ./extras/msg.txt
MSG_EN := ./extras/encoded
MSG_OUT := ./extras/text.txt

all: clean $(SENDER) $(RECEIVER)
sender:  clean $(SENDER)
receiver:  clean $(RECEIVER)
clean: | $(BUILDS)
	@rm -f $(BUILDS)/*

$(SENDER): | $(BUILDS)
	@$(CC) $(FLAGS) $(filter-out src/receiver.c, $(SRC)) $(LIBS) -o $@
	@$@ $(MSG_IN) $(MSG_EN)

$(RECEIVER): | $(BUILDS)
	@$(CC) $(FLAGS) $(filter-out src/sender.c, $(SRC)) $(LIBS) -o $@
	@$@ $(MSG_EN) $(MSG_OUT)

$(BUILDS):
	@mkdir -p builds