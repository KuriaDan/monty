## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
0x19. C - Stacks, Queues - LIFO, FIFO
* Stacks - an imlementation of  LIFO.
* Queues - an implementation of FIFO


## Technologies
Project is created with:
* The Monty Language
* C-programming
* Betty Programming style

## Setup
* Compilation
```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

* Execution of monty

```
vagrant@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
vagrant@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
vagrant@ubuntu:~/monty$
```
