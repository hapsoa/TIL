# (css)box-shadow

선택한 요소에 그림자 효과 내기



box-shadow : none | <그림자 값> [, <그림자 값>]*;

<그림자 값> = <수평 거리> <수직 거리> <흐림 정도> <번짐 정도> <색상> inset



수평거리와 수직거리는 필수, 다른건 옵션.


 <수평 거리>

양수 값: 요소의 오른쪽, 음수 값: 요소의 왼쪽 에 그림자 만듬 

 <수직 거리>

양수 값: 요소의 아래쪽, 음수 값: 요소의 위쪽 에 그림자 만듬 

<흐림 정도>

기본 값 0 : 진한 그림자. 값이 커질수록 부드러운 그림자 

 <번짐 정도>

양수 값: 모든 방향으로 퍼져 나감(박스보다 크게 표시) , 음수 값: 모든 방향으로 축소되어 보임.

 <색상>

 inset

안쪽 그림자로 그림 