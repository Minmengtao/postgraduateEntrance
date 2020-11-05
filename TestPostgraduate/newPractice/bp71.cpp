#include<cstdio>
#include<map>
typedef struct window{
	int x,y,X,Y;
}window;
map<char,window> wo;
char demand,I,top,bottom;

int main(){
	while(~scanf("%c",&demand)){
		if(demand=='w'){
			window w;
			int x,y,X,Y;
			scanf("(%c,%d,%d,%d,%d)",&I,&x,&y,&X,&Y);
			w.x=x;w.y=y;w.X=X;w.Y=Y;
			wo[I]=w;
			top=I;
		}else if(demand=='t'){
			scanf("(%c)",&top);
		}else if(demand=='b'){
			scanf("(%c)",&bottom);
		}else if(demand=='d'){
			scanf("(%c)",&I);
			wo[I]=null;
		}else if(demand=='s'){
		}
	}
	return 0;
}