LDFLAGS = -time -g -lm
CFLAGS = -Wall -Wextra
CFLAGS := $(CFLAGS) -Werror -Wno-unused-parameter

mymake: mymake.o cible.o graphe.o lecture.o datastructure/safemalloc.o datastructure/buffer.o datastructure/linkedlist.o datastructure/chainedlist.o datastructure/ruleset.o datastructure/infiniteruleset.o datastructure/ruletab.o datastructure/rule_function.o
	gcc $(LDFLAGS) $^ -o $@

datastructure/buffer.o: datastructure/buffer.c datastructure/buffer.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/linkedlist.o: datastructure/linkedlist.c datastructure/linkedlist.h datastructure/safemalloc.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/radixlist.o: datastructure/radixlist.c datastructure/safemalloc.h datastructure/rule_struct.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/safemalloc.o: datastructure/safemalloc.c
	gcc $(CFLAGS) -c $< -o $@

datastructure/chainedlist.o: datastructure/chainedlist.c datastructure/chainedlist.h datastructure/safemalloc.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/ruleset.o: datastructure/ruleset.c datastructure/ruleset.h datastructure/rule_struct.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/infiniteruleset.o: datastructure/infiniteruleset.c datastructure/infiniteruleset.h datastructure/safemalloc.h datastructure/ruleset.h datastructure/rule_struct.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/ruletab.o: datastructure/ruletab.c datastructure/ruletab.h datastructure/rule_struct.h datastructure/safemalloc.h datastructure/buffer.h
	gcc $(CFLAGS) -c $< -o $@

datastructure/rule_function.o: datastructure/rule_function.c datastructure/rule_struct.h datastructure/safemalloc.h datastructure/ruletab.h datastructure/chainedlist.h
	gcc $(CFLAGS) -c $< -o $@

mymake.o: mymake.c lecture.h datastructure/ruleset.h datastructure/ruletab.h graphe.h cible.h
	gcc $(CFLAGS) -c $< -o $@

cible.o: cible.c cible.h datastructure/rule_struct.h datastructure/rule_function.h datastructure/ruleset.h datastructure/ruletab.h
	gcc $(CFLAGS) -c $<

graphe.o: graphe.c graphe.h datastructure/ruletab.h
	gcc $(CFLAGS) -c $<

lecture.o: lecture.c lecture.h datastructure/rule_struct.h datastructure/rule_function.h datastructure/ruleset.h datastructure/ruletab.h
	gcc $(CFLAGS) -c $<

clean :
	find . -type f -name '*.o' -exec rm {} +
	find . -type f -name '*.h.gch' -exec rm {} +
	find . -type f -name 'vgcore.*' -exec rm {} +
.PHONY: clean

