#include <stdlib.h>
#include <stdio.h>

#include "lecture.h"
#include "ruleset.h"


int main(int argc, char **argv){
    Ensemble e=lecture(argv[1]);
    make(e.premiereRegle,e);
    return 0;
}