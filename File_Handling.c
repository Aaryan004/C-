#include <stdio.h>
#include <stdlib.h>
int main(){
FILE* ftr;
char a[100];
ftr=fopen("TheNotebook.txt","r");
if(ftr==NULL){
    printf("The file is not opened. The program will exit now");
    exit(0);
}else {
while(fgetc(ftr)!=EOF){
fgets(a,100,ftr);
printf("%s",a);
}
printf("The text has been printed successfully.");
fclose(ftr);
}
return;
}
