# background

## background-position

| 속성          | 설명                                                                                                                                    |
| ------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| left top      | 왼쪽 상단                                                                                                                               |
| left center   | 왼쪽 중앙                                                                                                                               |
| left bottom   | 왼쪽 맨아래                                                                                                                             |
| right top     | 오른쪽 상단                                                                                                                             |
| right center  | 오른쪽 중앙                                                                                                                             |
| right bottom  | 오른쪽 아래                                                                                                                             |
| center top    | 가운데 상단                                                                                                                             |
| center center | 정 가운데                                                                                                                               |
| center bottom | 가운데 맨아래                                                                                                                           |
| x% y%         | x는 가로위치, y는 세로위치. <br/> 0% 0% 는 left top 과 같음.<br/> 100% 100% 는 right bottom과 같음.<br/> 한가지만 지정하면 나머지는 50% |

cm, px, in, pt, px, em등의 단위와 섞어서 지정도 가능

# (css) background-position속성

배경 이미지 위치 조절하기

background-position: <수평 위치> <수직 위치>;

수평 위치 : left | center | right | <백분율> | <길이 값>

수직 위치 : top | center | bottom | <백분율> | <길이 값>

ex)

background-position: center bottom; // 배경 이미지를 브라우저 창의 중앙 하단에 배치

background-position: 0% 0%; // 배경 이미지를 넣으려는 요소의 왼쪽 모소리에 배경 이미지의 왼쪽 모서리를 맞춥니다.

background-position: 30% 60%; // 배경 이미지를 넣으려는 요소의 왼쪽 모서리로부터 가로 30%, 세로 60%의 위치에 배경 이미지의 가로, 세로가 30% 60%인 위치를 맞춥니다.

background-position: 30px 20px; // 가로 30픽셀, 세로 20픽셀의 위치에 배경 이미지의 왼쪽 상단 모서리를 맞춥니다.

# (css) background-size 속성

배경 이미지 크기 조절하기

배경 이미지를 여러 크기로 조절할 수 있음

background-size: auto | contain | cover | <크기 값> | <백분율>

속성 값

설명

auto

원래 배경이미지 크기만큼 표시(초기값)

contain

요소 안에 배경 이미지가 다 들어오도록 이미지를 확대/축소

cover

배경 이미지로 요소를 모두 덮도록 이미지를 확대/축소

<크기 값>

너비 값과 높이 값을 지정. 너비 값만 지정할 경우, 원래 배경 이미지 크기를 기준으로 비율을 자동으로 계산해 높이 값을 지정

<백분율>

배경 이미지가 들어갈 요소의 크기를 기준으로 백분율 값을 지정하고, 그 크기에 맞도록 배경 이미지를 확대하거나 축소

ex)

background-size: auto;

background-size: 200px 150px;

background-size: 60% 40%;

background-size: contain;

background-size: cover;

background-size: 100% 100%

# (css) background-repeat 속성

배경 이미지 반복 방법 지정하기

background-repeat : repeat | repeat-x | repeat-y | no-repeat

속성 값

설명

repeat

브라우저 화면에 가득 찰 때까지 배경 이미지를 가로와 세로로 반복(초기값)

repeat-x

창 너비와 같아질 때까지 배경 이미지를 가로로 반복

repeat-y

창 높이와 같아질 때까지 배경 이미지를 세로로 반복

no-repeat

배경 이미지를 한번만 표시하고 반복하지 않습니다.

# background-image 속성

웹 요소에 배경 이미지 넣기

background-image: url(파일 경로)

```css
body {
  background-image: url('bg1.png');
}

#area {
  background-image: url('bg2.png');
}
```

url에 http://로 시작하는 절대 경로도 사용할 수 있음.

배경 이미지는 여러 개를 사용할 수 있는데 이럴 경우, 첫 번째 이미지부터 순서대로 표시합니다.

이미지가 채우려는 요소 크기보다 작을 경우, 해당 요소를 가득 채울 정도로 가로와 세로로 반복됩니다.

# (css) background-clip 속성

배경 적용 범위 조절하기

background-clip: border-box | padding-box | content-box

속성 값

설명

border-box

테두리(border)까지 적용(초기값)

padding-box

테두리를 뺀 padding 범위까지 적용

content-box

박스 모델에서 내용 부분에만 적용

# background-color 속성

background-color: <색상>

background-color:#00ff00; // 16진수: 세밀히 색상 조절

background-color: rgb(0,255,0); // rgba: 필요하면 투명도도 함께 조절 가능

background-color: green; // 색상 이름: 원색 사용
