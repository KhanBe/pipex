# pipex
Project in 42seoul

## Goal
Pipex 프로그램 작성   
```$> ./pipex file1 cmd1 cmd2 file2```
```file1```및```file2```는 파일이름   
```cmd1```및```cmd2```는 Shell 명령어

Pipex는 아래의 명령을 Shell에서 실행되는 것과 동일하게 처리해야 한다.
```$> < file1 cmd1 | cmd2 > file2```

```$> ./pipex infile ``ls -l'' ``wc -l'' outfile``` 명령은 ```< infile ls -l | wc -l > outfile```와 동일해야 한다.

### Bonus
다중 파이프 구현하기
```$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2```
위 명령어는 다음과 같아야 한다.
``` $> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2```
