#include <stdio.h>


void function(char *source, char *integers, char *nonInteger)
{
	int a = 0;
	int b = 0;
	for(int i = 0; source[i]!='\0';i++)
	{
		if((int)source[i]>47 && (int)source[i]<58)
		{
			integers[a] = source[i];
			a++;
		}
		else
		{
			nonInteger[b] = source[i];
			b++;
		}
	}
	integers[a] = '\0';
	nonInteger[b] = '\0';
	printf("Integers:%s nonIntegers:%s\n",integers, nonInteger);
}

int main()
{
	char source[] = "abc123def456gh!";
	char integers[256];
	char nonIntegers[256];

	function(source, integers, nonIntegers);

}
