#include <stdlib.h>
#include <stdio.h>

#include "lecture.h"
#include "ruleset.h"


int main(int argc, char **argv){
    Ruleset e=lecture("Makefile");
    if(argv[1]==NULL){
        make("main",e);
    }
    else {
        make(argv[1],e);
    }
    return 0;
}
