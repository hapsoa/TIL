#include <stdio.h>
// 비트 연산
#define ITEM_SWORD     0
#define ITEM_SHIELD	   1
#define ITEM_DAGGER    2
#define ITEM_ARMOR     3
#define ITEM_BOW       4
#define ITEM_POTION    5

void get_item(unsigned char* items, int no)
{
	// items[no] = 1;

	// 0000 1000
	// no: 3
	// 0000 0000
	//      1000
	// 0000 1000

	// no:5
	// 0000 1000
	//   10 0000
	// 0010 1000
	// *items = *items | (1 << no); 
	*items |= 1 << no;
}

void lost_item(unsigned char* items, int no)
{
	// *items = *items & ~(1 << no);
	*items &= ~(1 << no);
	// 0010 1000
	// 1101 1111 &
	// 0000 1000
	// ~(1 << no)  & 
}

// 오른쪽 쉬프트
// 1. signed (arithmetic shift)      >>
//  => 부호 비트의 값이 채워진다.
// 2. unsigned (logical shift)       >>>
//  => 0


int has_item(unsigned char* items, int no)
{
	return (*items >> no) & 0x1;
	// 0000 0000
	// >> 3
	// 0000 0000
	// 0000 0001 &
	// => 0
}


int main()
{
	unsigned char items;
	
	get_item(&items, ITEM_SHIELD);
	printf("%d\n", has_item(&items, ITEM_SHIELD));
	lost_item(&items, ITEM_SHIELD);
	printf("%d\n", has_item(&items, ITEM_SHIELD));
}

#if 0
int main()
{
	char items[6] = { 0, };

	items[ITEM_SWORD] = 1;
	items[ITEM_ARMOR] = 1;
}
#endif
