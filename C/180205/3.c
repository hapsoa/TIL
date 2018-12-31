
#include <stdio.h>
#include <ctype.h>

void word_count(char* buf, int* count)
{
	char* p = buf;
	while (*p)
	{
		// if (*p == ' ' || *p == '\t' || *p == '\n')
		if (isspace(*p))
			++*count;
		++p;
	}
}

int main()
{
	char buf[64];
	int count = 0;
	while (fgets(buf, sizeof buf, stdin) != NULL)
		word_count(buf, &count);

	printf("count: %d\n", count);
}
