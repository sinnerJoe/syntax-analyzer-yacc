#ifndef UTILITY_H
#define UTILITY_H

#include "string.h"
#include "malloc.h"
#include <ctype.h>
#include <math.h>



char* copyString(char *src){
    int index = -1;
    for(int i=0; i<strlen(src); i++){
        if( src[i]==' '){
            index=i;
            src[i] = '\0';
            break;
        }
    }
    char * dest;
    if(index == -1)
        dest = (char*)malloc(40);
    else
        dest = (char*)malloc(index+1);
    strcpy(dest, src);
    if(index!=-1)
        src[index] = ' ';
    return dest;
    
}

void clearChars(char* ptr, unsigned nr){
    memset(ptr, 0, nr);
}





#endif
