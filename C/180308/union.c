// struct
// union - 공용체
// enum - 사용자 정의 타입

struct user {
	char* name;
	int age;
};  // 16


// 공용체는 멤버 중 가장 큰 크기를 가지는 멤버의 크기를 가진다.
// => 8 byte

// 공용체의 사용 목적
// 1. 여러 개의 타입 중 하나의 타입에 데이터만 필요한 경우 
//   => 마지막에 대입된 데이터만 유효하다.
// 2. 바이트 단위에 데이터를 분해할 때 사용할 수 있다.
union data {
	int n;
	struct {
		unsigned char a;
		unsigned char b;
		unsigned char c;
		unsigned char d;
	} byte;
};

// C Union -> Variant

int main()
{
	union data data;
	data.n = 0x12345678;

	printf("%x\n", data.byte.a);
	printf("%x\n", data.byte.b);
	printf("%x\n", data.byte.c);
	printf("%x\n", data.byte.d);
}












#if 0
union data {
	int a;
	char b;
	double c;
}; 

int main()
{
	printf("%ld\n", sizeof(union data));
	union data d;
	d.c = 3.14;

	d.b = 'A';
	d.a = 42;

	printf("%lf\n", d.c);

}
#endif
