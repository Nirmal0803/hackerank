#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 101

int String_len(char *Sentence){
    int len=0;
    while(Sentence[len]!='\0'){
        len++;
    }
    return len;
}

void handle_space(char *Sentence){
    int i=0;
    int j=0;
    int flag=0;
    while(Sentence[i]==' '){
        i++;
    }
    while(Sentence[i]!='\0'){
        if(Sentence[i]==' '){
            if(flag==0){
                Sentence[j++]=' ';
            }
            flag=1;
        }
        else{
            Sentence[j++]=Sentence[i];
                flag=0;
        }
        i++;
    }
    if(j>0 && Sentence[j-1]==' '){
        j--;
    }
    
    Sentence[j]='\0';
}

void reverse_words(char *Sentence){
    char temp[MAX_LEN]={0};
    int tempIndex=0;
    int end=String_len(Sentence)-1;
    
    while(end>=0){
        int dest=end;
        while(end>=0 && Sentence[end]!=' '){
            end--;
        }
        int start=end;
        for(int i=start+1;i<=dest && tempIndex<MAX_LEN-1;i++){
            temp[tempIndex++]=Sentence[i];
            
        }
        if(end>=0 && tempIndex<MAX_LEN-1){
            temp[tempIndex++]=' ';
        }
        end--;
    }
    

    temp[tempIndex]='\0';
    
   int i=0;
    while(temp[i]!='\0'){
        Sentence[i] = temp[i];
        i++;
    }
    Sentence[i]='\0';

}

int main() {
    
    
    char Sentence[MAX_LEN]={0};
    scanf("%[^\n]",Sentence);
   
   
    handle_space(Sentence);
     if (Sentence[0]!='\0') {
    reverse_words(Sentence);
    printf("%s\n",Sentence);}
    
    return 0;
}
