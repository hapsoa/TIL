# branch

```
git branch : branch 상태 보기

git branch + [브랜치이름] : 해당 이름의 브랜치를 만든다.

git checkout + [브랜치이름] : 해당 브랜치에 들어간다.

git merge + [commit id] : HEAD가 있는 branch가 commitId의 커밋을 가지고와 병합한다.

git branch -d + [브랜치이름] : 필요없는 branch를 삭제할 수 있다.
git branch -D + [브랜치이름] : 필요없는 branch를 '강제'삭제할 수 있다.
(작업된 사항이나 commit 한 이력이 남아있는 경우, 해당 command로 branch가 삭제되지 않는 경우가 있습니다. 이러한 경우에는 강제로 branch를 삭제할 수 있습니다.)
git push origin :[브랜치이름] : remote branch를 삭제한다.


A브랜치에서 B브랜치를 병합한다 (= A로 B를 가져온다. A<-B)
git merge B브랜치명 (ex. git merge hapsoa)
```

## 동시에 여러 작업하기

```
// issue2, issue3 branch를 만든다.
git branch issue2
git branch issue3

git checkout issue2

코드를 편집한다.

git add .
git commit -m "update at issue2 branch"

// 해당 branch를 저장소 remote branch에도 생성한다.
git push origin issue2

// local의 branch를 retmoe branch와 연동하는 작업을 수행한다.
git branch --set-upstream-to origin/issue2



// 다른 컴퓨터에서
// remote branch들을 조회할 수 있다.
git branch -r

// remote branch의 이름을 그대로 유지하면서 가져온다.
git checkout -t origin/hapsoa
(// 다른 컴퓨터에서 branch를 hapsoa를 생성하면서 origin/hapsoa remote branch를 가지고 온다.
git checkout -b hapsoa origin/hapsoa)
```

<br>

## 함께하는 프로젝트에서 다른 컴퓨터로 내 하던 작업 옮기기

```
// 현재 컴퓨터의 작업내역을 github에 올리기
git branch hapsoa
git checkout hapsoa

git add .
git commit -m "update"

git push origin hapsoa
git branch --set-upstream-to origin/hapsoa


// 다른 컴퓨터에서 작업내역을 불러오기
git branch -r
git checkout -t origin/hapsoa


// 다른컴퓨터에서 작업하기
git checkout hapsoa

git add .
git commit -m "update"


// origin/master에서 hapsoa branch를 가져와 병합하기
git merge hapsoa


// branch 삭제하기
git branch -d + [브랜치이름]
git push origin :[브랜치이름]
```
