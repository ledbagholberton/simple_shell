# Project Shell Simple (alias Shelley)

Shelley is a simple shell running in Linux environment which is able to run Kernel commands and some builtin commands 
which be described in last sections of this document.

Shelley's code is C language and it's construction is part of advanced projects from first cohort (I - 2019) of Holberton School in Bogota, Colombia.

![](header.png)

## How to start

Clone this repository in a new directory in your machine. 

<b> git clone https://github.com/ledbagholberton/simple_shell.git </b>

Run the "make" command to compile all the c files and copy help files in $HOME directory

<b> make </b>

Now the executable file <hsh> was generated and it will run to Shelley.

<b> ./hsh </b>

## Usage example

Shelley execute kernel commands in non-interactive mode. 


Shelley execute builtin commands in non interacive mode.


Shelley execute kernel commands in interactive mode.


Shelley execute builtin commands in interactive mode.

##Functions used

<b>built_exit</b>          - Builtin function exit

<b>built_cd</b>            - Builtin function cd

<b>cd_parent<b>           - Builtin function cd in parent

<b>built_history</b>       - Builtin function history 


<b> ========== engine.c ========== </b>

<b>valid_command</b>       - validation function (kernel or builtin)

<b>_which</b>              - path 

<b>check_cd</b>            - support to change dir

<b>_strdup</b>             - string copy

<b>get_path</b>            - get home from environ var


<b> ========== env_func.c ========== </b>

<b>create_env</b>          - make a copy from environ var

<b>_env</b>                - Builtin function env


<b> ========== error.c ========== </b>

<b>pperror</b>             - our perror function

<b> ========== _getline.c ========== </b>

<b>get_home</b>            - return $HOME

<b>delete_delim</b>        - support to _strtok

<b>_strcopy</b>            - our strcopy

<b>_realloc</b>            - our realloc

<b>_getline</b>            - our getline

<b> ========== main.c ========== </b>

<b>main</b>                - main function

<b>.init_file</b>           - initialization of variables

<b>CTRLC</b>               - Ctrl-C function

<b> ========== shell.c ========== </b>

<b>invoke_shell</b>        - starting shell

<b>hand_status</b>         - handling status from exit builtin

<b>print_prompt</b>        - printing prompt 

<b>check_interactive</b>   - support to interactive mode

<b> ========== string_op.c ========== </b>

<b>split</b>               - split of strings

<b>_strncmp</b>            - our strcmp

<b>str_concat</b>          - concatenation of strings

<b>_atoi</b>               - our atoi functions

<<b>_strlen</b>             - our strlen function

<b> ========== _strtok.c ========== </b>

<b>is_in_delim</b>         - support to _strtok function

<b>look_first_char</b>     - support to -strtok function

<b>look_first_delim</b>    - support to -strtok function

<b>look_last_delim</b>     - support to -strtok function

<b>_strtok</b>             - our strtok function

## Release History

* 0.0.1
    * (15-04-2019) First version

## Authors

Giovanny Perez - [@ledbag] Holberton School Colombia Student
Haroldo Velez - [@harovlz] Holberton School Colombia Student

Distributed under the XYZ license. See ``LICENSE`` for more information.

[https://github.com/yourname/github-link](https://github.com/dbader/)
