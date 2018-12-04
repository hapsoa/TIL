# TypeScript Overview

TypeScript = Language

타입스크립트는 ' 프로그래밍 언어 ' 입니다.

타입스크립트는 ' Compiled Language ' 입니다.

전통적인 Compiled Language 와는 다른 점이 많습니다.

그래서 ' Transpile ' 이라는 용어를 사용하기도 합니다.

자바스크립트는 ' Interpreted Language ' 입니다.


| Compiled | Interpreted |
|--|--|
| 컴파일이 필요 O | 컴파일이 필요 X  |
| 컴파일러가 필요 O | 컴파일러가 필요 X |
| 컴파일하는 시점 O => 컴파일 타임 | 컴파일하는 시점 X |
| 컴파일된 결과물을 실행 | 코드 자체를 실행 |
| 컴파일된 결과물을 실행하는 시점 | 코드를 실행하는 시점 o = 런타임 |


#### 정적 타입 언어 VS 동적 타입 언어

## Traditional Compiled Language
컴파일 언어라고 한다.

C, C++, Go, C#, Java, ...

프로그래머가 작성한 ' Source Code ' 를 기계어로 변환하는 과정을  ' Compile ' 이라고 한다.

기계어로 변환된 결과물을 ' Object Code ' (목적 코드)라 한다.

' Compile ' 하는 프로그램을 ' Compiler ' 라고 한다.

' Compile ' 하는 동안을 ' Compile Time ' 이라고 한다.

컴파일된 코드는 프로세서에 따라 다르다.

소스 코드에서는 OS 에 따라 라이브러리가 다르다.

컴파일된 코드는 작은 크기에 최적화된다.

일반적으로 실행시 기계어로 바꾸는 방식(인터프리터 언어)보다 빠르다.

실행시 기계어로 바꿔주는 연산이 필요없기 때문이다.

<br>

## Traditional Compiled Language
컴파일된 코드들은 ' Linking ' 이라는 과정을 통해 실행 파일로 만들어 진다.

컴파일된 여러 목적 코드들을 합치고 라이브러리를 추가한다.

' Linking ' 하는 프로그램을 ' Linker ' 라고 한다.

컴파일이라는 말을 링킹까지 포함하여 말하기도 한다.

컴파일된 코드는 프로세서에 의존적이다.

컴파일된 코드는 작은 크기에 최적화된다.

일반적으로 실행시 기계어로 바꾸는 방식(인터프리터 언어)보다 빠르다.

실행시 기계어로 바꿔주는 연산이 필요없기 때문이다.

<br>

TS --- 컴파일러 --->> JS


