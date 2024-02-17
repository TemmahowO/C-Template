#include "tem_strings.h"
#include <stdio.h>
#include <stdlib.h>

/* getline: read a line into s, return lenght*/
int getlines(char string[], int limit){
    int c = 0;
    int i = 0;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        string[i] = c;

    }
    if (c == '\n') {
        string[i] = c;
        ++i;
    }
    string[i] = '\0';
    
    return i;
}

/* getnum: read numbers into string. Returns str -> int 
! LIMITATIONS: 
! can't covnverts negative numbers
! uses a deprecated function (atoi doesn't know what to do when the input isn't a number.)
*/
int getnum(char string[], int limit){
    int c = 0; 
    int i = 0;
    int string_lenght = 0;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        if (c >= '0' && c <= '9'){
            string[string_lenght] = c;
            ++string_lenght;
        }

    }

    return atoi(string);
}

/* copy: copy "from" into "to": assume "to" is big enough. */
void copy(char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


/* Counts the amount of characters within a string.*/
int count_string(char string_array[], int limit){
    int i; 
    int no_of_chars = 0;

    for (i = 0;i <= limit; ++i){
        ++no_of_chars;
        
        if (string_array[i] == '\0'){
            return no_of_chars - 2;
        }
    }
}

/* Variation of the copy() function. Just backwards*/
void reverse(char from[], char to[], int total_lenght){
    int to_index = 0;
    int from_length = total_lenght;
    
    while(to_index < total_lenght){
        to[to_index] = from[from_length - 2]; /* -2 to account for the '\0' and the newline*/
        --from_length;
        ++to_index;
    }
    to[to_index] = '\0';

}

void reset_string(char string[], int limit){
    int i = 0;

    for(i = 0; i < limit-1; ++i){
        string[i] = '\0';
    }
}

void print_string(char string[], int lim){
    int i;
    for(i = 0; i < lim; ++i){
        printf("%d ", string[i]);
    }
    printf("\n");
}