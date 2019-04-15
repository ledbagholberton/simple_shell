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

built_exit          - Builtin function exit

built_cd            - Builtin function cd

cd_parent           - Builtin function cd in parent

built_history       - Builtin function history 


<b> ========== engine.c ========== </b>

valid_command       - validation function (kernel or builtin)

_which              - path 

check_cd            - support to change dir

_strdup             - string copy

get_path            - get home from environ var


<b> ========== env_func.c ========== </b>

create_env          - make a copy from environ var

_env                - Builtin function env


<b> ========== error.c ========== </b>

pperror             - our perror function

<b> ========== _getline.c ========== </b>

get_home            - return $HOME

delete_delim        - support to _strtok

_strcopy            - our strcopy

_realloc            - our realloc

_getline            - our getline

<b> ========== main.c ========== </b>

main                - main function

init_file           - initialization of variables

CTRLC               - Ctrl-C function

<b> ========== shell.c ========== </b>

invoke_shell        - starting shell

hand_status         - handling status from exit builtin

print_prompt        - printing prompt 

check_interactive   - support to interactive mode

<b> ========== string_op.c ========== </b>

split               - split of strings

_strncmp            - our strcmp

str_concat          - concatenation of strings

_atoi               - our atoi functions

_strlen             - our strlen function

<b> ========== _strtok.c ========== </b>

is_in_delim         - support to _strtok function

look_first_char     - support to -strtok function

look_first_delim    - support to -strtok function

look_last_delim     - support to -strtok function

_strtok             - our strtok function

## Release History

* 0.0.1
    * (15-04-2019) First version

## Authors

Giovanny Perez - [@ledbag] Holberton School Colombia Student
Haroldo Velez - [@harovlz] Holberton School Colombia Student

Distributed under the XYZ license. See ``LICENSE`` for more information.

[https://github.com/yourname/github-link](https://github.com/dbader/)
