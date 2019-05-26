# Problem Set 2: Caesar

## Running Program

**Program**: caesar
**Purpose**: Program enables to encrypt messages using caesar's cipher. At the time the user executes the program, the user should decide by providing a command line-argument, on what the key should be and the secret message they'll provide at runtime. 
**Assumptions**: Don't assume that the user's key is going to be a number, though assume if there is an number input than it is a positive integer. 

For example, if user inputs a key of `1` and a plaintext of `HELLO`, output:
```c
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
```

Another ouput with user input of key `13` and a plaintext message `hello, world`:
```c        
$ ./caesar 13
plaintext:  hello, world
ciphertext: uryyb, jbeyq
```

**NOTE:** Neither the comma nor the space were "shifted" by the cipher, only the alphabetical characters were rotated. 

## Pseudocode
1. Check that program was run with one command-line argument
2. Iterate over the provided argument to make sure all characters are digits
3. Convert that command-line argument from a string to an int
4. Prompt user for plaintext
5. Iterate over each character of the plaintext:
    - If it is an uppercase letter, rotate it, preserving case, then print out the rotated character
    - If it is a lowercase letter, rotate it, preserving case, then print out the rotated character
    - If it is neither, print out the character as is
6. Print a newline

## Problem Context

Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of place:
- For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. 
- And so, to say HELLO to someone, Caesar might write IFMMP. 
- Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places. 

**The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters** (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called _plaintext._ Encrypted text is generally called ciphertext. And the secret used is called a **key.**

| **plaintext**    | **H** | **E** | **L** | **L** | **O** |
|--------------|---|---|---|---|---|
| + key        | 1 | 1 | 1 | 1 | 1 |
| = ciphertext | I | F | M | M | P |

More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by **_k positions_**. More formally, if p is some plaintext (i.e., an unencrypted message), pi is the ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, ci, in the ciphertext, c, is computed as:
> ci = (pi + k) % 26
wherein `% 26` here means "remainder when dividing by 26". 

This formula makes the cipher seem more complicated than it is, but it's really just a concise way of expressing the algorithm concisely:
- Think of A (a) as 0, B (b) as 1, ..., H (h) as 7 and Z (z) as 25. 
- Suppose I want to say **"Hi"** confidentially using, a key, k, of 3. 
- Plaintext, _p_, is Hi in which case my plaintext's first character, p0, is H (_aka._ 7) and my plaintext's second character, p1, is I (_aka._ 8). 
- Then, ciphertext's first character. c0, is thus K, and ciphertext's second character, c1, is thus L. 

