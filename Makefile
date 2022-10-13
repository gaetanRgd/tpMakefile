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

cible.o: cible.c cible.h datastructure/rule_struct.h datastructure/rule_function.h datastructure/ruleset.h
	gcc $(CFLAGS) -c $<

graphe.o: graphe.c graphe.h datastructure/ruletab.h
	gcc $(CFLAGS) -c $<

lecture.o: lecture.c lecture.h datastructure/rule_struct.h datastructure/rule_function.h datastructure/ruleset.h datastructure/ruletab.h
	gcc $(CFLAGS) -c $<


clean :
<<<<<<< HEAD
	find . -type f -name '*.o' -exec rm {} +
	find . -type f -name '*.h.gch' -exec rm {} +
.PHONY: clean
=======
<<<<<<< HEAD
	rm -f *.o
	rm -f *.h.gch
.PHONY: clean
=======
	rm -f -r *.o
	rm -f -r *.h.gch
.PHONY: clean
>>>>>>> 049b2c0dce019ca8485634ef2f9d5eda0af6b3a5
>>>>>>> ade760fd468593a50700e331b8a61f87349a613d
