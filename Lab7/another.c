#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char lines[1000][1000];
    int linecount=0;
    FILE *fp;
    printf("HELLO\n");
    fp=fopen("output.ll","r");
    printf("THE LINES IN THE FILE\n");
    
    while(fgets(lines[linecount],1000,fp)){
        lines[linecount][strlen(lines[linecount])-1]='\0';
        linecount++;
    }
    for(int j=0;j<linecount;j++){
        printf("%d : %s\n",j,lines[j]);
    }
}