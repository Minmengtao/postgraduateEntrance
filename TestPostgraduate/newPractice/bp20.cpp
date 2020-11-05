#include <stdio.h>

int getResult(int a, int b, int weishu[])

{

    int i=0;
	for(int j=0;j<=99;j++)
		if((a*100+j)%b==0)
			weishu[i++]=j;
	return i;

}

int main()

{

    int a, b, weishu[100],count,i;

    scanf("%d%d", &a, &b);

    count=getResult(a,b,weishu);

    for(i=0; i<count; i++)

    {

        if (i>0)

            printf(" ");

        printf("%02d", weishu[i]);

    }

    printf("\n");

    return 0;

}