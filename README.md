# SimpleCrypt
Simple encrypting system based on Feistel cipher. 

Details: 

This system gets any message as parameter in any language (just don't use spacebars, i hadn't fix it yet!).

Then it generates a random-based disposable 56-bit key. Then key enhances to 64-bit via "permutation-with-extension-using-a-matrix" technology.

After that, hash of message enhancing to be 64-multiple (if it wasn't) by adding 1 as first enhancing symbol and zeroes as other symbols.

Then enhanced hashsum transforms via transformate matrix in blocks with 32bit-size and encrypts by XOR with enhanced key. 

After all, 64-bit XOR-result converts in encrypted hash-sum as decimal number;


You can modify this system to encrypt message too if you need. I did this Just 4 Fun.
