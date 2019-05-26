# Linux Command Line
- CS50 IDE is a cloud-based machine running Ubuntu, one of the many flavors of the Linux OS. 
- Many modern linux distributions have graphial user interfaces (GUI) to allow easy mouse-based navigation. 
- Still, as a programmer you'll likely be using terminal window frequently and you can do many of the same tasks with keyboard commands. 

## Linux Commands
Some of the most important keyboard-based commands for working within the IDE or any UNIX-based system:
- `ls <directory>`: This command accesses the contents of the current directory.
- `cd <directory>`: Short for "change directory", this command changes your directory to **<directory>**, which I can specify on my workspace or operating system. The shorthand name for the parent directory of current directory is **..**
- `pwd`: If curious about the current directory that I'm working on, I can type pwd (present working directory). 
- `mkdir <directory>`: Short for "make directory", this command will create a new subdirectory called **<directory>** located in the current directory.
- `cp <source> <destination>`: Short for "copy", this command will allow you to create a duplicate of the file you specify as **<source>**, which it will save in **<destination>**. 
        - If you wish to copy entire directories, modify the command to **cp -r <source directory> <destination_directory>**. The "-r" stands for _recursive_, and tells cp to dive down into the directory and copy everything inside of it (including subdirectories it may contain.)
        - The **-r** tells the cp command to recursively dive down into the directory and make a copy of everything. 
- `rm <file>`: Comamnd is short for "remove". 
        - To delete entire directories, just use the **-r** flag. `rm -r <directory>`. 
- `mv <source> <destination>`: short for "move", this command effectively rename a file, moving it from <source> to <desintation>. 
        - Basically, this is used to rename files from <source> to another name <destination>
