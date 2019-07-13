# .gitignore

.gitignore 파일을 만들어 깃허브에 업로드 하지 않을 파일을 설정할 수 있다.


아래의 git 명령들을 실행해주면 .gitignore의 파일들이 적용되어 원격 저장소에서 사라진다.

```
$ git rm -r --cached .
$ git add .
$ git commit -m "Apply .gitignore"
$ git push
```