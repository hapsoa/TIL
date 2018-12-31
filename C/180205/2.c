
#include <stdio.h>
#include <string.h>

// strstr
// hello world good day to die show me the money
//      hellh
int count_word(char* buf, char* word)
{
	int count = 0;
	int len = strlen(word);
	while (*buf)
	{
		if (strncmp(buf, word, len) == 0)
			++count;

		buf++;
	}

	return count;
}

int main()
{
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "file open error...\n");
		return -1;
	}

	char word[64];
	scanf("%s", word);

	int count = 0;
	char buf[4096];
	while (fgets(buf, 4096, fp) != NULL)
	{
		count += count_word(buf, word);
	}

	printf("count: %d\n", count);
	fclose(fp);
}
