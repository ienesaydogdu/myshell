#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[],char **envp){
    int rakam = atoi(argv[0]);
    
    if(rakam==0)printf("0 >> sıfır\n");
    else if(rakam==1)printf("1 >> bir\n");
	else if(rakam==2)printf("2 >> iki\n");
    else if(rakam==3)printf("3 >> üç\n");
    else if(rakam==4)printf("4 >> dört\n");
    else if(rakam==5)printf("5 >> beş\n");
    else if(rakam==6)printf("6 >> altı\n");
    else if(rakam==7)printf("7 >> yedi\n");
    else if(rakam==8)printf("8 >> sekiz\n");
    else if(rakam==9)printf("9 >> dokuz\n");
    else printf("Girilen değer rakam değildir.\n");
	return 0;
}
