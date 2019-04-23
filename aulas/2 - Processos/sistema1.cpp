#include <stdlib.h>
#include <stdio.h>

int main (){
	printf("Inicio \n");
	printf("Finalizou com o seguinte codigo: %d\n",system ("ls -la"));
    system("../tempo/./sleep &");
    system("ps");
	exit (0);
}


