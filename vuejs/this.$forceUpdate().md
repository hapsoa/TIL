# this.\$forceUpdate()

component의 prop이 object인 경우 해당 object의 property를 외부에서 변경시 component의 DOM rendering 변화가 이루어지지 않는 경우.

부모 컴포넌트에서 prop object데이터의 property를 변경하고 자식 컴포넌트 내에서 this.\$forceUpdate()를 호출한다.

computed로 해결할 수 있을 지도 모르는데, 아직까지 해결법을 찾지 못하고 있음
