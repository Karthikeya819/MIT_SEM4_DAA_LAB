#include <stdio.h>
#include <string.h>

int StringMatch(char *str1,char *str2){
    int len1 = strlen(str1);int len2 = strlen(str2);
    int i=0,j=0;
    while(j<len2 && i <len1){
        if(str1[i] == str2[j])i++;
        else i=0;
        j++;
    }
    return j;
}

int main(){
    printf("Hello World!");
    char str1[] = "Hello";
    char str2[] = "Hello World!";
    printf("%d",StringMatch(str1,str2));

    return 0;
}