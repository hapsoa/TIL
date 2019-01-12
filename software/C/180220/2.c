#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
	char* name;
	int age;
};

void init_user(struct user* u)
{
	name = "Unnamed";
	age  = 0;
}

int main()
{
	struct user* user = malloc(sizeof(struct user));
	init_user(user);
}
