LDFLAGS = -time -g
CFLAGS = -Wall -Wextra -Wno-unused-parameter
CFLAGS := $(CFLAGS) -Werror

main : main.o a.o b.o c.o d.o
	gcc $(LDFLAGS) $^ -o $@
	make clean

main.o : main.c c.h d.h
	gcc $(CFLAGS) -c $<

a.o : a.c a.h
	gcc $(CFLAGS) -c $<

b.o : b.c b.h
	gcc $(CFLAGS) -c $<

c.o : c.c c.h
	gcc $(CFLAGS) -c $<

d.o : d.c d.h
	gcc $(CFLAGS) -c $<

clean :
	rm -f *.o
	rm -f *.h.gch
.PHONY: clean
