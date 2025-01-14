#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int NumOfCompanies;
    int NumOfCountries;
    scanf("%d",&NumOfCompanies);
    scanf("%d",&NumOfCountries);
    
    char Arr[NumOfCompanies][100];
    int Revenue[NumOfCompanies][NumOfCountries];
    
    for(int i=0;i<NumOfCompanies;i++){
        scanf("%s",Arr[i]);
            for(int j=0;j<NumOfCountries;j++){
        scanf("%d",&Revenue[i][j]);
                
            }
    }
    
    
    int Total[NumOfCompanies];
    
     for(int i=0;i<NumOfCompanies;i++)
     {
           Total[i]=0;
    }
       
       
       for(int i=0;i<NumOfCompanies;i++){
            for(int j=0;j<NumOfCountries;j++){
                Total[i]+=Revenue[i][j];
                
            }
           
       }
           int MaxRevenue=0;
           for(int i=0;i<NumOfCompanies;i++){
               if(Total[i]>MaxRevenue){
                   MaxRevenue=Total[i];
               }
           }
           
           for(int i=0;i<NumOfCompanies;i++){
               if(Total[i]==MaxRevenue){
                   printf("%s\n",Arr[i]);
               }
           }
           
    
    return 0;
}
