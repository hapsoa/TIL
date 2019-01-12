#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[32];
	int  kor;
	int  eng;
	int  math;
};

int kor_ascending_compare(const void* a, const void* b);
int kor_descending_compare(const void* a, const void* b);
int eng_ascending_compare(const void* a, const void* b);
int eng_descending_compare(const void* a, const void* b);

int main()
{
	struct student students[100];
	int n = 0;
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "file open error...\n");
		return -1;
	}

	while (fscanf(fp, "%s %d %d %d", 
		students[n].name, 
		&students[n].kor, 
		&students[n].eng, 
		&students[n].math) == 4)
	{
		++n;
	}

	fclose(fp);

	int cmd;
	scanf("%d", &cmd);
	// 함수 포인터와 배열 포인터의 표현식은 복잡합니다.
	// typedef 를 이용하면 간단하게 사용할 수 있습니다.

	// int (*compare[4])(const void*, const void*) = {

	typedef int (*compare_t)(const void*, const void*);
	compare_t compare[4] = {
		&kor_ascending_compare,
		&kor_descending_compare,
		&eng_ascending_compare,
		&eng_descending_compare
	};
	printf("cmd: %d\n", cmd);

	if (cmd >= 1 && cmd <= 4) {
		qsort(students, n, sizeof(struct student), compare[cmd - 1]);
	}

	for (int i = 0 ; i < n ; ++i)
		printf("%10s %5d %5d %5d\n", 
				students[i].name,
				students[i].kor,
				students[i].eng, 
				students[i].math);
}

int kor_ascending_compare(const void* a, const void* b)
{
	struct student* s1 = (struct student*)a;
	struct student* s2 = (struct student*)b;

	return s1->kor - s2->kor;
}

int kor_descending_compare(const void* a, const void* b)
{
	struct student* s1 = (struct student*)a;
	struct student* s2 = (struct student*)b;

	return s2->kor - s1->kor;
}

int eng_ascending_compare(const void* a, const void* b)
{
	struct student* s1 = (struct student*)a;
	struct student* s2 = (struct student*)b;

	return s1->eng - s2->eng;
}

int eng_descending_compare(const void* a, const void* b)
{
	struct student* s1 = (struct student*)a;
	struct student* s2 = (struct student*)b;

	return s2->eng - s1->eng;
}






