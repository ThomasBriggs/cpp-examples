#include <stdio.h>
int main()
{
	char*c="#include <stdio.h>%cint main()%c{%c%cchar*c=%c%s%c;%c%cprintf(c,10,10,10,9,34,c,34,10,9,10,9,10,10);%c%creturn 0;%c}%c";
	printf(c,10,10,10,9,34,c,34,10,9,10,9,10,10);
	return 0;
}