#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCISSOR  -1
#define ROCK     0
#define PAPER    4

// -3, 0, 3 => 비김
struct player
{
	int money;
	int value;
};

int play()
{
	return rand() % 3;
}

void process(struct player* p, int n)
{
	int sum = 0;
	for (int i = 0 ; i < n ; ++i)
		sum += p[i].value;

	if (sum == 0 || sum % 3 == 0)
		return;

	if (sum % 4 == 0)
	{

	}
	
	if (sum < 0)
	{

	}

	
		
	
	
}

int main()
{
	struct player players[3] = {
		{3000, },
		{3000, },
		{3000, },
	};

	srand(time(NULL));

	while (1)
	{
		scanf("%d", &players[0].value);		
		for (int i = 1 ; i < 2; ++i)
			players[i].value = play();

	}

}






