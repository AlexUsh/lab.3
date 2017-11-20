#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *file;
    file=fopen(argv[1],"r");
    char str[1024];
    char *p;
    char *q;
    int i=1;
    int a = 0;

    if(file == NULL)
	{
		printf("Can't find the file!");
		return -1;
	}
	else
	{
    	while(!feof(file))
    	{
        	fgets(str, 1024, file);
        	q=str;
        	while((p=strstr(q,argv[2]))!=NULL)
        	{
            	printf("%d:%d %s\n", i,p-str+1,argv[2]);
            	q=p+1;
            	a++;
        	}
        	i++;
    	}

    	if(a == 0)
    	{
    		printf("Can't find the substring");
    	}
	}
    fclose(file);
    return 0;
}
