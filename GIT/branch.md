# branch

git branch : branch 상태 보기

git branch + [브랜치이름] : 해당 이름의 브랜치를 만든다.

git checkout + [브랜치이름] : 해당 브랜치에 들어간다.

git merge + [commit id] : HEAD가 있는 branch가 commitId의 커밋을 가지고와 병합한다.

git branch -d + [브랜치이름] : 필요없는 branch를 삭제할 수 이싸.

## 동시에 여러 작업하기

```
// issue2, issue3 branch를 만든다.
git branch issue2
git branch issue3

git checkout issue2

git add .
git commit -m "update at issue2 branch"

```

