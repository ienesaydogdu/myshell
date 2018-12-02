#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[],char **envp){
    int a = atoi(argv[0]);
    int b = atoi(argv[1]);
    int sonuc = a*b;
	printf("%d * %d = %d\n",a,b,sonuc);
	return 0;
}
