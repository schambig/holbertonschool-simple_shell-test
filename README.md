[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![made-with-Markdown](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](http://commonmark.org)

# Simple shell

![Simple shell](https://i.imgur.com/tfeTUGr.jpg)

# Table of Contents
- [Description](#description)
- [Flowchart](#flowchart)
- [File Structure](#file-structure)
- [System/Library calls](#system-and-library-calls)
- [Installation](#installation)
- [Examples](#examples)
- [Authors](#authors)

## Description
The Simple Shell is a simple UNIX command interpreter written entirely in C. The program runs based on bash commands obtained from the input stream by the user.
Any text seperated by a any number of spaces, tabs or a combination of both is considered to be an argument.
The respective command typed by the user is then parsed and executed as if in a UNIX shell.

**Basic lifetime of a shell**
* Startup the shell
* Wait for user input
* Parse user input
* Execute the command and return the result
* Go back to step 2
You could terminate the shell anytime, just type in the prompt the `exit` command or `Ctrl-D` which is interpreted as an end-of-file `EOF`

## Flowchart

## File structure

| File | Content | Description |
| --- | --- | --- |
| [main.h](main.h) | <pre>header files</pre> | <pre>Contain the structure, prototypes, macros and<br>external variable of the project.</pre> |
| [main_loop.c](main_loop.c) | <pre>int main();</pre> | <pre>Main loop, recieve input from the Command Line Interface<br>parse and execute it.</pre> |
| [tokenizers.c](tokenizers.c) | <pre>char **hsh_tokenizer();<br>char **tokenizer_path();</pre> | <pre>Split the input string into a array of tokens.<br>Split the environment variable PATH into an array of tokens.</pre> |
| [validators.c](validators.c) | <pre>char *validate_input();<br>int validate_spaces();</pre> | <pre>Validate if PATH exists<br>Validate spaces, tabs and line breaks.</pre> |
| [executors.c](executors.c) | <pre>int hsh_execute();<br>int hsh_execute_builtins();</pre> | <pre>Fork process and replace the child with a new program.<br>Choose from an array of builtin functions.</pre> |
| [builtin_functions.c](builtin_functions.c) | <pre>int hsh_cd();<br>int hsh_setenv();<br>int hsh_unsetenv();<br>int hsh_env();<br>int hsh_exit();</pre> | <pre>Change directory.<br>Change or add and environment variable.<br>Delete an environment variable from the environment.<br>Print the environment variables list.<br>Terminate the main loop and exit the shell.</pre> |
| [helper_functions.c](helper_functions.c) | <pre>void sigintH();<br>char *str_concat();<br>void *_realloc();</pre> | <pre>Handles SIGINT (CTRL + C).<br>Concatenate two strings.<br>Reallocate a memory block.</pre> |

## System and Library calls

## Installation
To use this custom _printf function you need `<stdio.h>`, `<stdarg.h>`, `<string.h>` and `<stddef.h>` libraries.

First, clone this repository to your local machine:

```
$ git clone https://github.com/schambig/holbertonschool-printf.git
```

Then, go to the repository folder:

```
$ cd holbertonschool-printf
```

Finally, you can compile it with your C source code:

```
$ gcc *.c [your_code] -o [outfile_name]
```

## Examples


**Character**
* Input:
```
_printf("%c is fun!\n", 'C');
```
 
* Output:
```
C is fun!
```

## Authors
| [<img src="https://avatars.githubusercontent.com/u/98305125?v=4" width=115><br><sub> Johana Herrera </sub>](https://github.com/Johana-RHP) | [<img src="https://avatars.githubusercontent.com/u/103861356?v=4" width=115><br><sub> Drixner Condor </sub>](https://github.com/Drixner) | [<img src="https://avatars.githubusercontent.com/u/98289735?v=4" width=115><br><sub> Salomón Chambi </sub>](https://github.com/schambig) |
| :---: | :---: | :---: |
