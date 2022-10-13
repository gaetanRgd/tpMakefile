LDFLAGS = -time -g
CFLAGS = -Wall -Wextra
CFLAGS := $(CFLAGS) -Werror -Wno-unused-parameter

main: datastructure/chainedlist.o datastructure/ruleset.o datastructure/infiniteruleset.o datastructure/ruletab.o datastructure/rule_function.o

datastructure/chainedlist.o: datastructure/chainedlist.c datastructure/chainedlist.h 
	gcc $(CFLAGS) -c $< -o $@

datastructure/ruleset.o: datastructure/ruleset.c datastructure/ruleset.h datastructure/rule_struct.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/infiniteruleset.o: datastructure/infiniteruleset.c datastructure/infiniteruleset.h datastructure/ruleset.h datastructure/rule_struct.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/ruletab.o: datastructure/ruletab.c datastructure/ruletab.h datastructure/rule_struct.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/rule_function.o: datastructure/rule_function.c datastructure/rule_struct.h datastructure/ruletab.h datastructure/chainedlist.h
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o
	rm -f *.h.gch
.PHONY: clean