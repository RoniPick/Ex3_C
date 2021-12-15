#include <stdio.h>
#include "stringlib.h"

#define TXT 1024
#define WORD 30
#define maxLength 2048 // for the length of the array *2 of the GematriaSequences. (if we get a word with only 1 letter and a text with 1024 times the same letter of the word, we need to have space for 1024 times the letter and 1024 times the sequence "~")
#define A 65
#define Z 90
#define a 97
#define z 122

char g[maxLength]; // for the gematria function's output
char at[maxLength]; // for the atbash function's output
char an[maxLength]; // for the anagram function output
char wAtbash[WORD];
char wAtbashReverse[WORD];


void
AtbashSequences ()
{
    int wordLength = 0;
    for (int i = 0; i < maxLength; i++)
    {
        at[i] = 0;
    }

    for (int i = 0; i < WORD; i++)
    {
        if (w[i] >= A && w[i] <= Z)
        {
            wAtbash[i] = A - w[i] + Z;
            wordLength++;
        }
        else if (w[i] >= a && w[i] <= z)
        {
            wAtbash[i] = a - w[i] + z;
            wordLength++;
        }
    }

    for (int i = 0; i < wordLength; i++)
    {
        wAtbashReverse[i] = wAtbash[wordLength - i - 1];
    }

    // wordLength length of the word
    // wAtbash[] original word at atBash language
    // wAtbashReverse[] original word at atBash language but reversed
    // currWordSP pointer to the beginning of the curr word
    // currWordEP pointer to the end of the curr word
    // AOCA, amountOfCharsAdded, amount of chars added to the in a curr word.
    // newTextLength length of the output text -> MAX 2048

    int start = 0;
    int end = wordLength;
    int curr = 0;
    int AOCA = 0;
    int newTextLength = 0;
    int numOfSpaces = 0;
    // char[wordLength] checkWord;
    int counter = 0;
    int lastAdded = 0;
    int lastAddedP = 0;
    int firstTime = 0;
    int index = 0;
    int g = 0;
    int spaces;

    while (start < TXT && end < TXT && newTextLength < 9){
        // if(newTextLength == 8){
        //     int i = 0;

        // }
        if ((t[curr] > 64 && t[curr] < 91) ||
            (t[curr] > 96 && t[curr] < 123) || (t[curr] == 32)){
            if(curr == 10){
                g = 0;
            }
            curr = start;
            counter = 0;
            while (counter < wordLength){
                g = t[curr];
                if ((t[curr] > 64 && t[curr] < 91) ||
                    (t[curr] > 96 && t[curr] < 123) || (t[curr] == 32)){
                    if(t[curr] == wAtbash[counter]){
                        curr++;
                        counter++;
                    }
                    else if(t[curr] == 32 && counter != 0){
                        curr++;
                    }
                    else {
                        counter = 0;
                        break;
                    }
                }
                else {
                    curr++;
                    break;
                }
            }
            if (counter == wordLength){
                int i = 0;
                while (start < curr){
                    if(t[start] == wAtbash[i]){
                        at[start] = t[start];
                        printf("%c", at[start]);
                        start++;
                        i++;
                        newTextLength++;
                    }
                    else if (t[start] == 32){
                        at[start] = t[start];
                        printf("%c", at[start]);
                        start++;
                        newTextLength++;
                    }
                }
                at[start] = '~';
                newTextLength++;
                printf("%c", at[start]);
            }



            start = curr;
            counter = 0;
            while (counter < wordLength){
                g = t[curr];
                if ((t[curr] > 64 && t[curr] < 91) ||
                    (t[curr] > 96 && t[curr] < 123) || (t[curr] == 32)){
                    if(t[curr] == wAtbashReverse[counter]){
                        curr++;
                        counter++;
                    }
                    else if(t[curr] == 32 && counter != 0){
                        curr++;
                    }
                    else {
                        counter = 0;
                        break;
                    }
                }
                else {
                    curr++;
                    break;
                }
            }
            if (counter == wordLength){
                int i = 0;
                while (start < curr){
                    if(t[start] == wAtbashReverse[i]){
                        at[start] = t[start];
                        printf("%c", at[start]);
                        start++;
                        i++;
                        newTextLength++;
                    }
                    else if (t[start] == 32){
                        at[start] = t[start];
                        printf("%c", at[start]);
                        start++;
                        newTextLength++;
                    }
                }
                at[start] = '~';
                newTextLength++;
                printf("%c", at[start]);
            }
            curr++;
            start = curr;
        }
        else  {
            curr++;
            start = curr;
        }
    }

    printf("Atbash Sequences : ");
    printf("%d", newTextLength);
    int i = 0;
    while (i < newTextLength) {
        printf("%c", at[i]);
        i++;
    }
    printf("\n");
}


void GematriaSequences(char *w, char *t, char *ABC){
    for(int i=0; i<maxLength; i++){
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
            if(counter==0){ // if the size of the word is at least 2 chars but the chars are not letters e.g. ' ' or '/' so we restart the counting
                start++;
                end = start;
            }

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
    printf("Gematria Sequences: ");
    int i=0;
    while(i<l){
        printf("%c", g[i]);
        i++;
    }
    printf("\n");

}

void AnagramSequences(char *w, char *t, char *ABC, int wordLength){
    for(int i=0; i<maxLength; i++){
        an[i] = 0;
    }

    int start=0;
    int end=0;
    int l=0;
    int counter=0;
    int size = 0; // for the end-start length
    int wordSize = sum(w); // the word's gimatric sum
    while(start<TXT && end<TXT){
        size = end-start;
        if(t[end]>64 && t[end]<91 || t[end]>96 && t[end]<123){
            for(int i=0; i<26; i++){
                if(t[end] == ABC[i] || t[end] == ABC[i]+32)
                    counter+=i+1;
            }
        }

        if(counter == wordSize){
            int temp=start;
            int wLength=0;
            int letters=0;
            for(int i=0; i<wordLength; i++){
                for(int j=0; j<size; j++){
                    if(w[i] == t[temp]){
                        wLength++;
                        letters++;
                        break; //moving to the next char in the word
                    }
                    else if(w[i] == ' ' && i!=0){
                        wLength++;
                    }
                    temp++;
                }
                temp = start;
            }
            if(wLength == size && letters+1==wordLength){
                temp = start;
                while(temp<=end){
                    an[l] = t[temp];
                    l++;
                    temp++;
                }
                an[l] = '~';
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

    l--;
    printf("Anagram Sequences: ");
    int i=0;
    while(i<l){
        printf("%c", an[i]);
        i++;
    }

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
