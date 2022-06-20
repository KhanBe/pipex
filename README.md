# pipex
Project in 42seoul

## Goal
Pipex 프로그램 작성   
```$> ./pipex file1 cmd1 cmd2 file2```   
```file1```및```file2```는 파일이름   
```cmd1```및```cmd2```는 Shell 명령어   

Pipex는 아래의 명령을 Shell에서 실행되는 것과 동일하게 처리해야 한다.   
```$> < file1 cmd1 | cmd2 > file2```   

```$> ./pipex infile ``ls -l'' ``wc -l'' outfile``` 명령은   
```< infile ls -l | wc -l > outfile```와 동일해야 한다.

### Bonus
다중 파이프 구현하기   
```$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2```   
위 명령어는 다음과 같아야 한다.   
``` $> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2```   

### 사용 가능 함수
1. ```int open(const char *pathname, int flags);```
- pathname : 파일의 경로와 이름, (절대경로, 상대경로 모두 가능)
- flags : 파일을 어떻게 열지 결정하는 플래그, 읽기전용 O_RDONLY, 쓰기전용 O_WRONLY, 읽기쓰기 O_RDWR
- 반환 : 성공적으로 열면 파일 디스크립터 반환, 아니면 음수 반환

2. ```ssize_t read(int fd, void *buf, size_t nbytes);```
- fd : 파일 디스크립터
- buf : 파일에서 읽어 들인 입력값을 저장할 버퍼, 어떤 자료형으로 읽어올지 몰라 void* 형이다.
- nbytes : 얼마만큼 읽어오는 바이트수
- 반환 : 정상적으로 파일내용을 읽어오면 nbytes값 반환, 아니면 0반환

3. ```int close(int fd);```
- fd : 파일 디스크립터
- 반환 : 정상작동시 0반환, 아니면 -1반환

4. ```ssize_t write(int fd, const void *buf, size_t n);```
- fd : 파일 디스크립터
- buf : 파일에 쓰기를 할 내용을 담은 버퍼
- n : 파일에 쓸 바이트 개수
- 반환 : 정상적으로 파일쓰면 n값 반환, 아니면 -1반환

5. ```void *malloc(size_t size);```
- 헤더 : ```stdlib.h```

6. ```void free(void* ptr);```
- 헤더 : ```stdlib.h```

7. ```int dup2(int oldfd, int newfd);```
- 설명 : oldfd 디스크립터에서 newfd로 파일을 복제한다. newfd가 이미 열려있을 경우 close후 복제한다.
- 헤더 : ```unistd.h```
- oldfd : 복사하려는 원본 파일 디스크립터
- newfd : 복사되는 파일 디스크립터
- 반환 : 정상작동 시 -1이외의 값, 아니면 -1반환

8. ```int execve(const char *filename, char *const argv[], char *const envp[]);```
- 헤더 : ```unistd.h```
- 설명 : 현재 실행되는 프로그램의 기능을 끄고 filename 프로그램을 실행한다.
- argv : 인수 목록
- envp : 환경변수 목록

9. ```pid_t fork(void);```
- 설명 : 자식프로세스를 만들기 위해 사용되는 프로세스 생성 함수이다.
- 헤더 : ```unistd.h```
- 반환 : 실패일 때만 -1반환, 부모 프로세스(원본 프로세스)에서는 자식프로세스(생성된 프로세스)의id반환, 자식프로세스에서는 0반환

10. ```void perror(const char *str);```
- str : 출력할 문자열
- 설명 : 에러 메세지를 출력하는 함수이다.

11. ```char *strerror(int errno);```
- 헤더 : ```errno.h```
- errno : 에러 번호
- 반환 : 에러 번호에 상응하는 에러 메세지

12. ```void exit(int status);```
- 헤더 : ```stdlib.h```
- 설명 : c프로그램 종료함수, return은 함수를 종료할 때 사용하고 exit는 프로세스를 종료할 때 사용하고 main함수에서 return은 프로세스를 종료함.

#### pipe
pipe함수는 단방향 통신이라 사용하지 않는 fd는 닫아줘야한다.   
pipe wirter 쪽에서 close를 하면 EOF가 reader한테 넘어간다.   
reader 쪽에서 close를 하면 writer 쪽으로 SIGPIPE 시그널이 간다.   

#### waitpid

#### fcntl
- 파일 처리 헤더

#### sys/wait
- 프로세스 관련 헤더
- 프로세스 
