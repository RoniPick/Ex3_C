#include <stdio.h>
#include <stdlib.h>

#define TXT 1024
#define WORD 30
#define gimatric 2048 // for the length of the array of the GematriaSequences +1 for the end of the word. (if we get a word with only 1 letter and a text with 1024 times the same letter of the word, we need to have space for 1024 times the letter plub 1023 times the sequence "~"
#define A 65
#define Z 90
#define a 97
#define z 122

char t[TXT];
char w[WORD];
char ABC[26];
char g[gimatric];
char at[gimatric];
char tAtbash[WORD];
char tAtbashReverse[WORD];


void AtbashSequences(){
    int counter=0;
    for(int i=0; i<gimatric; i++){
        at[i] = 0;
    }

    for(int i=0; i<WORD; i++){
        if(w[i]>=A && w[i]<=Z){
            tAtbash[i]= A - w[i] + Z;
            counter++;
        }
        else if(w[i]>=a && w[i]<=z){
            tAtbash[i]= a - w[i] + z;
            counter++;
        }
        else{
            tAtbash[i] =  w[i];
        }
    }

    for(int i=0; i<counter; i++){
        tAtbashReverse[i] = tAtbash[counter-i-1];
    }
    int wordSum = sum(tAtbash);
    int start = 0;
    int end = 0;
    int size=0;
    int cur=0;
    int l=0;

    while(start<TXT && end<TXT){// if its in the range of 'a'-'z' ro 'A'-'Z'
        size=end-start;
        if(size==0){
            if(t[start]>64 && t[start]<91 || t[start]>96 && t[start]<123){
                for(int i=0; i<26; i++){
                    if(t[start] == ABC[i] || t[start] == ABC[i]+32)
                        counter+=i+1;
                }
            }
            if(counter == wordSum){
                if(t[start] == tAtbash[0]){//the length of the word is 1 - only 1 char
                    at[l] = t[start];
                    l++;
                    at[l] = '~';
                    l++;
                    start++;
                    end = start;
                    counter = 0;
                }
            }
            else if(counter>wordSum){
                start++;
                end = start;
                counter = 0;
            }
            else{
                end++;
            }
        }
        else{
            if(t[end]>64 && t[end]<91 || t[end]>96 && t[end]<123 || t[end] == ' '){
                for(int i=0; i<26; i++){
                    if(t[end] == ABC[i] || t[end] == ABC[i]+32)
                        counter+=i+1;
                }

                if(counter == wordSum){
                    if(t[end]>64 && t[end]<91 || t[end]>96 && t[end]<123 || t[end] == ' '){
                        int temp = start;
                        while(temp<=end){
                            if(t[temp] == tAtbash[cur]){
                                cur++;
                                temp++;
                            }
                            else if(t[temp] == ' '){
                                temp++;
                            }
                        }

                        if(cur==counter){
                            temp = start;
                            while(temp<=end){
                                at[l] = t[temp];
                                l++;
                                temp++;
                            }
                        }

                        int back = start;
                        while(back<=end){
                            if(t[back] == tAtbashReverse[cur]){
                                cur++;
                                back++;
                            }
                            else if(t[back] == ' '){
                                back++;
                            }
                        }

                        if(cur==counter){
                            back= start;
                            while(back<=end){
                                at[l] = t[back];
                                l++;
                                back++;
                            }
                        }
                        at[l] = '~';
                        l++;
                    }
                    start++;
                    end = start;
                    counter = 0;
                }
                else if(counter>wordSum){
                    start++;
                    end = start;
                    counter = 0;
                }
                else{
                    end++;
                }


            }
            else{
                start++;
                end=start;
            }


        }

    }

    l--;
    at[l] = '#';
    printAtbashArray();


}

void printAtbashArray(){
    printf("Atbash Sequences: ");
    int i=0;
    while(at[i]!='#'){
        printf("%c", at[i]);
        i++;
    }
    printf("\n");
}

void GematriaSequences(){
    for(int i=0; i<gimatric; i++){
        g[i] = 0;
    }

    int start, end;
    int l=0;
    int counter=0;
    int size = 0; // for the end-start length
    int wordSize = sum(w); // the word's gimatric sum
    start = 0;
    end = start;
    while(start<TXT && end<TXT){// if its in the range of 'a'-'z' ro 'A'-'Z'
        size=end-start;
        if(size==0){
            if(t[start]>64 && t[start]<91 || t[start]>96 && t[start]<123){
                for(int i=0; i<26; i++){
                    if(t[start] == ABC[i] || t[start] == ABC[i]+32)
                        counter+=i+1;
                }
            }
            if(counter == wordSize){
                g[l] = t[start];
                l++;
                g[l] = '~';
                l++;
                start++;
                end = start;
                counter = 0;
            }
            else if(counter>wordSize){
                start++;
                end = start;
                counter = 0;
            }
            else{
                end++;
            }
        }
        else{
            if(t[end]>64 && t[end]<91 || t[end]>96 && t[end]<123){
                for(int i=0; i<26; i++){
                    if(t[end] == ABC[i] || t[end] == ABC[i]+32)
                        counter+=i+1;
                }
            }
            if(counter == wordSize){
                if(t[end]>64 && t[end]<91 || t[end]>96 && t[end]<123){
                    int temp = start;
                    while(temp<=end){
                        g[l] = t[temp];
                        l++;
                        temp++;
                    }
                    g[l] = '~';
                    l++;
                }
                start++;
                end = start;
                counter = 0;
            }
            else if(counter>wordSize){
                start++;
                end = start;
                counter = 0;
            }
            else{
                end++;
            }

        }

    }

    l--;
    g[l] = '#';
    printArray();

}

void printArray(){
    printf("Gematria Sequences: ");
    int i=0;
    while(g[i]!='#'){
        printf("%c", g[i]);
        i++;
    }
    printf("\n");
}

int sum(char *w){
    int counter = 0;
    for(int i=0; i<30; i++){
        for(int j=0; j<26; j++){
            if(w[i] == ABC[j] || w[i] == ABC[j]+32)
                counter+=j+1;
        }
    }

    return counter;

}
