/*#include<stdio.h>
#include<string.h>
int main(){
	int i,n;
	char A[530000]="A",B[100000]="",sign='A';
	scanf("%d",&n);
	for(i=1;i<n;i++){
		strcpy(B,A);
		int len=strlen(A);
		sign++;
		A[len]=sign;
		strcat(A,B);
	}
	printf("%s\n",A);
	return 0;
}*/
#include<stdio.h>
void print(int n);
int main(){
    int n;
    scanf("%d",&n);
    print(n);
    printf("\n");
    return 0;
}
void print(int n){
    if(n==0) 
        return;
    print(n-1);
    printf("%c",'A'+n-1);
    print(n-1);
}