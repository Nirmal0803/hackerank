#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 101

bool compare_string(char *first_word,char * sec_word){
    for(int i=0;first_word[i]!='\0' ;i++){
        if(first_word[i]!=sec_word[i]){
            return false;
        }
    }
    return true;
}

int counting_words( char *Sentence , char word[][MAX_LEN+1]){
    int countWord=0;
    int j=0;
    for(int i=0;Sentence[i]!='\0';i++){
        if(Sentence[i]==' ' && j>0){
            word[countWord][j]='\0';
            countWord++;
            j=0;
            }
        else{
            word[countWord][j++]=Sentence[i];
        }
    }
    if(j>0){
        word[countWord++][j]='\0';
        
    }
    
    return countWord;
}


void unique_word(char Word[][MAX_LEN+1],int countWord){
    int flag[MAX_LEN]={0};
    for(int i=0;i<countWord;i++){
        for(int j=0;j<countWord;j++){
            if(compare_string(Word[i],Word[j])){
                flag[i]++;
            }
        }
    }
    
    for(int i=0;i<countWord;i++){
        if(flag[i]==1){
            printf("%s\n",Word[i]);
            return;
        }
    }
    printf(" ");
}
void handle_space(char *Sentence){
    int i=0; 
    int j=0;
    while(Sentence[i]==' '){
        i++;
    }

    while (Sentence[i]!='\0'){
        if (Sentence[i]!=' '){
            Sentence[j++]=Sentence[i];
        }
        else if(Sentence[i]==' ' && Sentence[i + 1]!=' '){
            Sentence[j++]=' ';
        }
        i++;
    }

    if (j>0 && Sentence[j-1]==' ') {
        j--;
    }
    Sentence[j]='\0';
}



int main() {

   char Sentence[MAX_LEN];
    scanf("%[^\n]",Sentence);
    char Word[MAX_LEN][MAX_LEN+1];
    
    handle_space(Sentence);
    
    int TotalWord=counting_words(Sentence,Word);
    unique_word(Word,TotalWord);
    return 0;
}
