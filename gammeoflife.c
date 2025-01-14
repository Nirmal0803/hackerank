#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int** ExtractMatrix(char InputStr[],int *row,int *col){
    *row=1;
    int i=0;
    int Nums[100];
    int index=0;
    while(InputStr[i]!='\0'){
        if(InputStr[i]==','){
            (*row)++;
            i++;
            continue;
        }
        
        if(InputStr[i]=='[' || InputStr[i]==']' || InputStr[i]==' '){
            i++;
            continue;
        }
        int Number=InputStr[i]-'0';
        
        Nums[index++]=Number;
        i++;
    }
    int totalCount=index;
    *col=totalCount/(*row);
    
    int **Matrix=(int **)malloc((*row)*(sizeof(int *)));
    for(int i=0;i<(*row);i++){
       Matrix[i]=(int *)malloc((*col)*sizeof(int ));
    }
    int ind=0;
    for(int i=0;i<(*row);i++){
        for(int j=0;j<(*col);j++){
            Matrix[i][j]=Nums[ind++];
        }
    }
    
    return Matrix;
}

void SecondGeneration(int **Matrix,int row,int col){
    
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           
            int countLive=0;
            for(int k=-1;k<=1;k++){
               for(int l=-1;l<=1;l++){
                   if(k==0 && l==0){
                       continue;
                   }
                   if(i+k>=0 && j+l>=0 && i+k<row && j+l<col){
                   if(Matrix[i+k][j+l]==1 || Matrix[i+k][j+l]=='#'){
                       countLive++;
                   }
                   }
                   
               }
           }
              // printf("%d ",countLive);
            if(countLive<2 && Matrix[i][j]==1){
                Matrix[i][j]='#';
            }
            if((countLive==2 || countLive==3) && Matrix[i][j]==1){
                continue;
            }
            if(countLive>3 && Matrix[i][j]==1){
                Matrix[i][j]='#';
            }
            if(countLive==3 && Matrix[i][j]==0){
                Matrix[i][j]='$';
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(Matrix[i][j]=='#'){
                Matrix[i][j]=0;
            }
           if(Matrix[i][j]=='$'){
                Matrix[i][j]=1;
            }
        }
    }
    
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    char InputStr[100];
    scanf("%[^\n]",InputStr);
    int row;
    int col;
    int **Matrix=ExtractMatrix(InputStr,&row,&col);
    
    SecondGeneration(Matrix,row,col);
    
    printf("[");
    for(int i=0;i<row;i++){
        printf("[");
        for(int j=0;j<col;j++){
            printf("%d",Matrix[i][j]);
            if(j!=col-1){
                printf(" ");
            }
        }
        printf("]");
        if(i!=row-1){
            printf(",");
        }
    }
    printf("]");
    
    
    
    for(int i = 0; i < row; i++) {
        free(Matrix[i]);
    }
    free(Matrix);

    return 0;
    
    
}
