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

### OpenSSL - Cryptography and SSL/TLS Toolkit
OpenSSL works by implementing a wide range of cryptographic algorithms used in various Internet standards, including symmetric 
encryption, public key cryptography, key agreement, and more. It uses a library 'libcrypto' for these implementations. When using 
OpenSSL in a project, you typically perform operations like encryption or hashing through high-level API functions, such as those 
provided by the 'EVP' interface. These functions abstract the underlying cryptographic algorithms and allow for flexible use of 
different algorithms with minimal changes to your code.

For a practical implementation, you would start b choosing the appropriate cryptographic algorithm for your needs (e.g., AES for 
encryption, SHA256 for hashing) and then use the corresponding OpenSSL functions to perform the operation. For example, to
encrypt data, you would use functions like 'EVP_EncryptInit_ex', 'EVP_EncryptUpdate', and 'EVP_EncryptFinal_ex', providing them 
with your data and encryption keys. Similarly, for hasing you would use 'EVP_DigestInit_ex', 'EVP_DigestUpdate', and 'EVP_Digestfinal_ex'.

You would also need to handle key generation, management, and potentially the use of hardware security module (HSM) for storing 
cryptographic keys securely. OpenSSL supports a variety of key management techniques, including the use of PEM files for storing 
keys and certificates.

To get started with OpenSSL in your project, refer to the official OpenSSL documentation for detailed guidance on using its APIs 
and implementing cryptographic functions securely: OpenSSL Crypto Documentation - https://www.openssl.org/docs/man3.0/man7/crypto.html.

Here's a complete example demonstrating basic encryption and decryption using OpenSSL's AES algorithm in C++. This code snippet
performs AES-256-CBC encryption and decryption of a string.

```#include <iostream>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <vector>
#include <string>

class SimpleAES {
public:
    SimpleAES(const std::vector<unsigned char>& key, const std::vector<unsigned char>& iv) : key(key), iv(iv) {}

    std::vector<unsigned char> encrypt(const std::string& plaintext) {
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        std::vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);
        int len;
        int ciphertext_len;

        if(!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key.data(), iv.data())) {
            // Handle errors
        }

        if(!EVP_EncryptUpdate(ctx, ciphertext.data(), &len, reinterpret_cast<const unsigned char*>(plaintext.data()), plaintext.size())) {
            // Handle errors
        }
        ciphertext_len = len;

        if(!EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len)) {
            // Handle errors
        }
        ciphertext_len += len;
        ciphertext.resize(ciphertext_len);

        EVP_CIPHER_CTX_free(ctx);

        return ciphertext;
    }

    std::string decrypt(const std::vector<unsigned char>& ciphertext) {
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        std::vector<unsigned char> plaintext(ciphertext.size());
        int len;
        int plaintext_len;

        if(!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key.data(), iv.data())) {
            // Handle errors
        }

        if(!EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext.data(), ciphertext.size())) {
            // Handle errors
        }
        plaintext_len = len;

        if(!EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len)) {
            // Handle errors
        }
        plaintext_len += len;
        plaintext.resize(plaintext_len);

        EVP_CIPHER_CTX_free(ctx);

        return std::string(plaintext.begin(), plaintext.end());
    }

private:
    std::vector<unsigned char> key;
    std::vector<unsigned char> iv;
};

int main() {
    std::vector<unsigned char> key = {/* 32 bytes AES key */};
    std::vector<unsigned char> iv = {/* 16 bytes AES IV */};
    SimpleAES aes(key, iv);

    std::string plaintext = "Hello, OpenSSL AES!";
    auto ciphertext = aes.encrypt(plaintext);
    std::string decryptedText = aes.decrypt(ciphertext);

    std::cout << "Original: " << plaintext << std::endl;
    std::cout << "Decrypted: " << decryptedText << std::endl;

    return 0;
}

```

In this example, 'SimpleAES' is a class that encapsulates AES encryption and decryption functionalities using OpenSSL. Remember to replace the placeholder 'key' and 'iv' with your actual encryption key and initialization vector, and ensure you have installed
OpenSSL and linked it properly with your C++ project. This example skips over complexities, such as error handling and key management, which are critical in real-world applications.