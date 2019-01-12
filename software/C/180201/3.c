#include <stdio.h>

//  * 사용자 정의 타입
//   1. struct
//     => OOP - class
//   2. union
//     => OOP - varient
//   3. enum
//     => OOP - enum

// 배열
//  : 같은 타입의 변수가 여러개 필요한 경우

// 구조체
//  : 서로 다른 타입의 변수가 여러 개 필요한 경우
//    하나의 개념으로 묶어서 관리하고 싶다.
//  => 데이터 캡슐화

// struct user    ->  int 같은 타입과 동일하게 사용할 있다.
#if 0
struct user
{
	char name[32];
	int  age;
};

typedef struct user User; 

typedef struct 
{
	char name[32];
	int age;
} User;
#endif

typedef struct user
{
	char name[32];
	int age;
	// .. 50개
	int height;
} User;

// 문제가 있다. 
// 아래 코드는 user의 구조체의 크기가 클 수록,
// 오버헤드가 있다.
// 아래처럼 사용해도 되지만, 주소를 전달한다면
// 8 바이트만 사용하면 된다.
void print_user(const struct user* user)
{
	// user->age = 42; - compile errro!!
	printf("%s %d %d\n", user->name, user->age, user->height);
}

#if 0
void input_user(struct user user)
{
	scanf("%s %d", user.name, &user.age);
}
#endif

void input_user(struct user* p)
{
	// scanf("%s %d", (*p).name, &(*p).age);
	scanf("%s %d", p->name, &p->age);
}

int main()
{
	// struct user user1 = { "Tom", 42, ..... 180 };
	// User user = { "Tom", 42 };
	User user = {
		.height = 180
	};

	input_user(&user);
	print_user(&user);
}

#if 0
int main()
{
	char name[32];
	int age;

	scanf("%s", name);
	scanf("%d", &age);

	printf("%s %d\n", name, age);
}
#endif
