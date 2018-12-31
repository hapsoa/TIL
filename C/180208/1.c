
// 재귀함수: 자기 자신을 호출하는 함수
// 함수는 스택을 이용해서 호출됩니다.

// 재귀 함수를 만들 때 주의할 점.
//  => 종료 조건을 반드시 세워야 한다.
//    (기저 조건)

// C언어 스택의 기본 크기
//   linux: 8M
//   win  : 1M
// => Stackoverflow

void foo(int n)
{
	printf("foo(%d)\n", n);
	// 기저 조건 
	if (n < 0)
		return;

	foo(n - 1);
}

int main()
{
	foo(10);

}





