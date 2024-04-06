# Key generation research
## Sources/Libraries
### Crypto Library 8.9
-   https://www.cryptopp.com/ - https://github.com/weidai11/cryptopp
Crypto++ (also known as CryptoPP) is a free and open-source C++ library of cryptographic algorithms and schemes. The library was created by Wei Dai and offers a 
wide range of cryptographic functions that include symmetric encryption (like AES and DES), asymmetric encryption (RSA, ECC), hash functions (SHA-1, SHA-256), message
authentication codes (HMAC), and more.

From a theoretical standpoint, the library is designed to be easy to use, integrate, and extend. It uses templates and abstract classes extensively, so you can plug in
your own algorithms or replace built-in ones with your versions if needed. It's also designed with an emphasis on high performance and provides secure primitives 
to protect data.

Here's a practical example of you can use Crypto++ to generate an HMAC with SHA256:

```
#include "hmac.h"
#include "sha.h"
#include "hex.h"
#include "filters.h"
#include <iostream>
#include <string>

int main() {
    using namespace CryptoPP;

    // The secret key for HMAC
    byte key[] = {'s', 'e', 'c', 'r', 'e', 't'};
    // The message to authenticate
    std::string message = "The quick brown fox jumps over the lazy dog";

    // Create an HMAC object with the given key and SHA256 as the hash
    HMAC<SHA256> hmac(key, sizeof(key));

    // String to store the hex-encoded result
    std::string mac;

    // Create a filter that will calculate the HMAC
    StringSource ss(message, true, 
        new HashFilter(hmac,
            new HexEncoder(
                new StringSink(mac)
            ) // HexEncoder
        ) // HashFilter
    ); // StringSource

    // Output the result
    std::cout << "HMAC: " << mac << std::endl;

    return 0;
}
```


In this code:
-   The 'HMAC' class template is instantiated with 'SHA256' as the hash function.
-   The 'StringSource' class is used to push the message through a 'HashFilter' that calculates the HMAC and then through a 'HexEncoder' that encodes the HMAC in hexademical.
-   The result is then retrieved a 'StringSink' which simply puts the hex-encoded HMAc into a 'std::string'.

#### Implementing crypto++ in the project
Here's how you might use it to generate a SHA-256 hash and compile a simple program:

1.  **Installing the library**: Befre you can use Crypto++, you'll need to have it installed on your system. If you're on a UNIX-like system, you can often
install it via your package manager. For example, you might use: `sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils`. On windows, you
might download pre-built binaries or build the library from source.

2. **Writing the Code**: Below is an example of how you can use Crypto++ to generate a SHA-256 hash of a string.
```
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <iostream>
#include <string>

int main() {
    using namespace CryptoPP;
    std::string message = "Hello, World!";
    std::string digest;

    SHA256 hash;
    StringSource ss(message, true, 
        new HashFilter(hash,
            new HexEncoder(
                new StringSink(digest)
            )
        )
    );

    std::cout << "Message: " << message << std::endl;
    std::cout << "SHA-256: " << digest << std::endl;

    return 0;
}
```

3. **Compiling the Code:** You'll need to compile your program with the Crypto++ library. Assuming you have g++ and Crypto++ installed, you might compile your 
program like so: ´g++ -o sha_example sha_example.cpp -lcryptopp´. Replace '**sha_example.cpp**' with the name of your source file. The '**lcryptopp**' flag links 
the Crypto++ library with your program.

4. **Running the program:** Once compiled, you can run your program directly from the command line: `./sha_example`

This will print out the SHA-256 hash of "Hello, world!" in hexadecimal format. The crypto++ library is powerful and flexible, but it can be complex because it offers so much functionality. It's
a good idea to read the documentation and understand the basics of cryptographic primitives before using them in a production environment.