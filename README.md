
## **Operating Systems Lab (PCC-CS592)**
This repository contains all of my codes from the course **Operating Systems Laboratory (PCC-CS592)** which was a part of our 5th Semester B.Tech CSE Curriculum.

 - Shell Scripting has been done in **Bourne-again Shell (BASH)**
 - System Programming has been done in **C Langauge** 
 - Apart from **bash**, Assignment-4 will involve writing **awk** scripts as well.

The syllabus is broadly divided into 2 parts: 1. **Shell Scripting** and 2. **System Programming (Inter-Process Communication(IPC), Process and Thread Management)**.

## Instructions for Users:
### Basic Vim Customization:
To make your experience with Vim better you may add the following lines to your `.vimrc` file located at `/home/<your_username>`. It is a hidden file and to view it you must use `ls -a` command.
The commands are:

    set autoindent
    set smartindent
    set number
    set mouse=a

I have also added this sample `.vimrc` file that you can copy/paste.

### Running Shell Scripts from the terminal:

To run your bash scripts from the terminal, either change the permissions first, i.e. assign execute permission to the user using the `chmod` command or run directly using the `bash` command.
For example: 

    chmod u+x <my_script_name>.sh
and then run using:

    ./<my_script_name>.sh

OR

Simply run using:

    bash <my_script_name>.sh

To run awk scripts, use the commmand 

    awk -f <my_script_name>.awk input_file

### Running the C codes:
To compile C programs from the terminal which use the library pthread.h to deal with semaphores:

    gcc <my_C_program_name>.c -lpthread -o <executable_name>
 For general C programs:

     gcc <my_C_program_name>.c -o <executable_name>

   To run:
   

    ./<executable_name>
   To run in the background (This enables you to have access to the terminal while the process is running the background):
   

    ./<executable_name> &
This will be particularly useful to check for Zombie processes because you will be required to run the `ps -f f` command while one of the processes is still in execution.
### Important Header Files for System Programming
I have listed all the important header files that are particularly important for running the programs in this course:

    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<unistd.h>
    #include<fcntl.h>
    #include<semaphore.h>
    #include<pthread.h>
    #include<sys/wait.h>
    #include<sys/types.h>
    #include<sys/stat.h>
    #include<signal.h>
