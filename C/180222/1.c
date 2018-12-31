#include <stdio.h>
#include <stdlib.h>

struct user
{
	char* name;
	int age;
};

void init_user(struct user* p)
{
	p->name = "Unnamed";
	p->age = 0;
}

void init_user_name_age(struct user* p, char* name, int age) 
{
	p->name = name;
	p->age = age;
}



void print_user(const struct user* p)
{
	printf("User: %s %d\n", p->name, p->age);
}


// foo(10, 20, 30, 40);

int main()
{
	struct user* user = (struct user*)malloc(sizeof(struct user));
	init_user(user);
	print_user(user);
}









