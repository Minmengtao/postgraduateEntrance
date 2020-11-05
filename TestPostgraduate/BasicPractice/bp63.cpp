#include<stdio.h>
int reverse(char);
int main(){
    int m;
    scanf("%d\n",&m);
    while(m--){
        char s;
        s=getchar();
        reverse(s);
        printf("\n");
    }
    return 0;
}
int reverse(char s){
    if(s=='\n')
        return 0;
    else{
        char a=getchar();
        reverse(a);
        printf("%c",s);
    }
}