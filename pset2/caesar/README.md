# Problem Set 2: Caesar

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
