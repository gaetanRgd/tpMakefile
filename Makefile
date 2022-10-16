mymake: mymake.o cible.o graphe.o lecture.o datastructure/safemalloc.o datastructure/buffer.o datastructure/chainedlist.o datastructure/ruleset.o datastructure/infiniteruleset.o datastructure/ruletab.o datastructure/rule_function.o
	gcc -time -g -lm mymake.o cible.o graphe.o lecture.o datastructure/safemalloc.o datastructure/buffer.o datastructure/chainedlist.o datastructure/ruleset.o datastructure/infiniteruleset.o datastructure/ruletab.o datastructure/rule_function.o -o mymake_bymymake

datastructure/buffer.o: datastructure/buffer.c datastructure/buffer.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c datastructure/buffer.c -o datastructure/buffer.o

datastructure/safemalloc.o: datastructure/safemalloc.c
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c datastructure/safemalloc.c -o datastructure/safemalloc.o

datastructure/chainedlist.o: datastructure/chainedlist.c datastructure/chainedlist.h datastructure/safemalloc.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c datastructure/chainedlist.c -o datastructure/chainedlist.o

datastructure/ruleset.o: datastructure/ruleset.c datastructure/ruleset.h datastructure/rule_struct.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c datastructure/ruleset.c -o datastructure/ruleset.o

datastructure/infiniteruleset.o: datastructure/infiniteruleset.c datastructure/infiniteruleset.h datastructure/safemalloc.h datastructure/ruleset.h datastructure/rule_struct.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c datastructure/infiniteruleset.c -o datastructure/infiniteruleset.o

datastructure/ruletab.o: datastructure/ruletab.c datastructure/ruletab.h datastructure/rule_struct.h datastructure/safemalloc. datastructure/buffer.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c datastructure/ruletab.c -o datastructure/ruletab.o

datastructure/rule_function.o: datastructure/rule_function.c datastructure/rule_struct.h datastructure/safemalloc.h datastructure/ruletab.h datastructure/chainedlist.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c datastructure/rule_function.c -o datastructure/rule_function.o

mymake.o: mymake.c lecture.h datastructure/ruleset.h datastructure/ruletab.h graphe.h cible.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c mymake.c -o mymake.o

cible.o: cible.c cible.h datastructure/rule_struct.h datastructure/rule_function.h datastructure/ruleset.h datastructure/ruletab.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c cible.c

graphe.o: graphe.c graphe.h datastructure/ruletab.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c graphe.c

lecture.o: lecture.c lecture.h datastructure/rule_struct.h datastructure/rule_function.h datastructure/ruleset.h datastructure/ruletab.h
	gcc -Wall -Wextra -Werror -Wno-unused-parameter -c lecture.c

