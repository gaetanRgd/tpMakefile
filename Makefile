LDFLAGS = -time -g
CFLAGS = -Wall -Wextra
CFLAGS := $(CFLAGS) -Werror -Wno-unused-parameter

main: chainedlist.o ruleset.o infiniteruleset.o ruletab.o rule_function.o

chainedlist.o: chainedlist.c chainedlist.h 
	gcc $(CFLAGS) -c $<

ruleset.o: ruleset.c ruleset.h rule_struct.h
	gcc $(CFLAGS) -c $<

infiniteruleset.o: infiniteruleset.c infiniteruleset.h ruleset.h rule_struct.h
	gcc $(CFLAGS) -c $<

ruletab.o: ruletab.c ruletab.h rule_struct.h
	gcc $(CFLAGS) -c $<

rule_function.o: rule_function.c rule_struct.h ruletab.h chainedlist.h
	gcc $(CFLAGS) -c $<

clean :
	rm -f *.o
	rm -f *.h.gch
.PHONY: clean