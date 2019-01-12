
#include <dlfcn.h>
#include <stdio.h>   // -lc

int main()
{
	dlopen("a", RTLD_NOW);
}
