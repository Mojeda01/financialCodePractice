# The idea

1. Generate some value
2. Have the value stored in some file
3. Being able to send that value to other files, using an identifier for the file
4. and then transfering that value. (subtracting it from the sender and then adding to receiver).
5. The files can nothave a negative value, you can only subtract what is sent and added to what has been received.

## How to design it?
Develope some simple logic and then expand on it.

## value holding file - JSON design
-   ID: a randomly generated key using the your name as a unique identifier for key generation.
-   Name: your name to the value holding file
-   Credits/Amount: the amount of credits/value you have.
