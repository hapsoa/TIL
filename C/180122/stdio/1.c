
// C type
//  1. 현대적인 프로그래밍 언어에서 타입에 대한 이해가 매우 중요합니다.
//     C
//     type: 메모리의 크기

// int(word): CPU가 한번에 처리할 수 있는 데이터의 크기.

// 4 
// 0000 0100

// 51
//  = 32 + 16 + 2
//  =  2^5 + 2^4 + 2^1
// 00 110 011
// => 0x33
// => 063

// -42
// 3
//  => 음수를 표현하는 방법은 + / -
//  1000 0000  => -0
//  0000 0000  => +0
// MSB                  

// 0xFFFF
// signed: -1
// unsigned: 

// 0xFFFFFF
// => 얼마?
//  1111 1111 1111 1111 1111 1111
// => 0000 0000 0000 0000
//  +                   1
//  => -1

// 0000 0011 : 3
// 1111 1100 : -3
// 0000 0000 : 0
// 1111 1111 : 0

// 0000 0011
// ~3 + 1
// 1111 1100
//         1
// 1111 1101


// 음수 표현 방식
//  1. 절대 부호법
//  2. 1의 보수법
//  3. 2의 보수법  - O

//     signed / unsigned
//     정수 타입     16bit     32bit     64bit
//     signed / unsigned char: 1byte
//     short      :            2byte 
//     int        :  2byte     4byte     4byte
//     long       :  4byte     4byte     windows: 4byte / linux: 8byte    
//     long long  :            8byte     8byte

//     실수 타입 - floating point type(부동 소수점)
//      : 연산시 오차가 계속 발생한다.
//     float    -> 4byte
//     double   -> 8byte

//     42       => int
//     3.14     => double
//     3.14f    => float

//     문자 타입 - char














