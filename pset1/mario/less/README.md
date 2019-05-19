# program: mario 
## pseudocode
input: how tall is the pyramid (height)
param:// positive integer 

output: 
e.g. input is 4. Thus, starting from 1, increment each line by 1 up till 4 with hash signs. 

Note: Build program to take in positive integer. If non positive, re-prompt the user till positive integer is inputted. 

1. prompt user for input height
2. if height is <1 or >8 (or not an integer) go back to step 1. 
3. iterate from 1 through height -- on iteration i, print i hash and then a newline 

## Notes
Creating pyramid usinf hashes 

```
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```
Allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 4 when prompted:
```
$ ./mario
Height: 4
   #
  ##
 ###
####
```

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate

## Prompting for Input
Whatever your pseudocode, let’s first write only the C code that prompts (and re-prompts, as needed) the user for input.

Specifically, modify mario.c at right in such a way that it prompts the user for the pyramid’s height, storing their input in a variable, re-prompting the user again and again as needed if their input is not a positive integer between 1 and 8, inclusive. Then, simply print the value of that variable, thereby confirming (for yourself) that you’ve indeed stored the user’s input successfully, a la the below.

```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
Stored: 4
```
