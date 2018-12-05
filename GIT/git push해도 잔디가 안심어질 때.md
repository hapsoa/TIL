# git push해도 잔디가 안심어질 때

포맷해서 깃 유저 정보가 없으면, git push 해도 잔디가 심어지지 않는다.

```
터미널에서 이렇게 쳐서 확인해보면 아무것도 없다
vi ~/.gitconfig
```

그래서 터미널 명령어를 친다.

```
git config --global user.name "Jaejong Heo"
git config --global user.email hapsoa@gmail.com
```

