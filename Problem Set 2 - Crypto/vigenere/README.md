# Vigenere
Vigenere cipher has extra security than caesar cipher where it does not use a single numeric key but instead uses a **_key word_**. 

Each of those characters in key word represents a different key, for example 'a' represents a shift in 0 although it is the first letter in the alphabet -- computer scientists start counting from 0 not 1. Furthermore, 'b' represents a shift in 1 and so on...

For example, a keyword of 'dog' represents 3 keys:
- Where keys: 3, 14 and 6. 
- If I wanted to encrypt a message using this key, I would rotate the **first letter of that secret message by 3 places, second letter by 14 places, and third letter by 6 places... and then we would loop back to the key again i.e. use D, then, O and G again.

## Context
Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a **_keyword_**).

In other words, if p is some plaintext and k is a keyword (i.e., an alphabetical string, whereby A (or a) represents 0, B (or b) represents 1, C (or c) represents 2, …, and Z (or z) represents 25), then each letter, ci, in the ciphertext, c, is computed as:

> ci = (pi + kj) % 26

**Note this cipher’s use of kj as opposed to just k. And if k is shorter than p, then the letters in k must be reused cyclically as many times as it takes to encrypt p.**

### Example
In other words, if Vigenère himself wanted to say HELLO to someone confidentially, using a keyword of, say, ABC, he would encrypt the H with a key of 0 (i.e., A), the E with a key of 1 (i.e., B), and the first L with a key of 2 (i.e., C), at which point he’d be out of letters in the keyword, and so he’d reuse (part of) it to encrypt the second L with a key of 0 (i.e., A) again, and the O with a key of 1 (i.e., B) again. And so he’d write HELLO as HFNLP, per the below:

| plaintext     | H | E | L | L | O |
|---------------|---|---|---|---|---|
| + key         | A | B | C | A | B |
| (shift value) | 0 | 1 | 2 | 0 | 1 |
| = ciphertext  | H | F | N | L | P |

## Running the Program
Writing a program called `vigenere` that enables you to encrypt messages using Vigenère’s cipher. 

At the time the user executes the program, they should decide, by providing a command-line argument, on what the keyword should be for the secret message they’ll provide at runtime.

Examples of how program might work:
```c
$ ./vigenere bacon
plaintext:  Meet me at the park at eleven am
ciphertext: Negh zf av huf pcfx bt gzrwep oz
```

**or for when they don't provide keyword that is not fully alphabetic:**
```c
$ ./vigenere 13
Usage: ./vigenere keyword
```

**or when they don't provide keyword at all:**
```c
$ ./vigenere
Usage: ./vigenere keyword
```

**or for when they provide too many keywords:**
```c
$ ./vigenere bacon and eggs
Usage: ./vigenere keyword
```
## Concept
One difference between Caesar’s and Vigenère’s ciphers is that the key for Vigenère’s cipher is a **series of letters, rather than a number.**

So let’s make sure that the user actually gave us a keyword!
- Modify the check you implemented in Caesar to instead ensure every character of the keyword is alphabetic, rather than a digit. 
- If any of them isn’t, print `Usage: ./vigenere keyword` and **return a non-zero value** as we did before. 
- If they are all alphabetic, after checking you should print Success and then, return 0; immediately (for now), since our enciphering code is not quite ready to work just yet, so we won’t have our program execute it.

## Getting the shift value
Let’s for now assume that the user is providing single-character keywords. Can we convert that character into the correct shift value? Let’s do so by writing a function.

Near the top of your file, below the #include lines, let’s declare the prototype for a new function whose purpose is to do just that. It will take a **_single character as input, and it will output the shift value for that character._**

```c
int shift(char c);
```

Now we’ve declared a function called `shift` that takes a single character (`c`) as input, and will output an integer.

In the function is where we’ll do the work of **converting that character to its positional integer value (so, again, A or a would be 0, B or b would be 1, Z or z would be 25, etc.)**

To test this out, delete the line where you printed "Success" (but leave the return 0; for now), and in place of the just-deleted line, add the below lines to test whether your code works.

```c
int key = shift(argv[1][0]);
printf("%i\n", key);
```






