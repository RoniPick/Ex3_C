#include <stdio.h>
#include <string.h>
#include "stringlib.h"

#define WORD 30
#define TXT 1024
char t[TXT];
char w[WORD];
char ABC[26];

int main(void){

    initialize();

    AtbashSequences();


    return 0;
}


void initialize(){

    int c = 65; //ASCII value of 'A'
    for (int i = 0; i < 26; i++) { //filling the array with the ASCII value of the ALPHABET
        ABC[i] = c;
        c++;
    }

    char input;
    int temp=0;

    while(input!=' ' && input!='\t' && input!='\n'){
        scanf("%c", &input);
        w[temp] = input;
        temp++;
    }

    if(temp<30){
        while(temp<30){
            w[temp] = 0;
            temp++;
        }
    }

    int cur = 0;
    while(input!='~'){
        scanf("%c", &input);
        t[cur] = input;
        cur++;
    }

    if(cur<1024){
        while(cur<1024){
            t[cur] = 0;
            cur++;
        }
    }

}



