// (C) 2010 tmiz.net
#include <stdio.h>
#include <stdlib.h>
#include "Table.h"
 
__USING_NAMESPACE_15_PAZZLE
 
int main()
{
    Table t;
    t.randomize(13);
    t.printTable();
 
    int i = 100;
    while (i--) {
	char buf[100];
	printf("Time:%d  Next Number => ", i);
	scanf("%s", buf);
	int iNum = atoi(buf);
	t.moveNumber(iNum);
	t.printTable();
	if (t.getState() == 1) {
	    printf("Congratulations. You win the game.\n");
	    return 0;
	}
    }
    printf("Time Over\n");
    return 0;
}
