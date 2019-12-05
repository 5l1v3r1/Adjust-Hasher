#include <sodium.h>
#include <cstdio>
#include <iostream>
#include <string>

#define MESSAGE ((const unsigned char *) "Arbitrary data to hash")
#define MESSAGE_LEN 22

void print_hex(const unsigned char *s)
{
  while(*s)
    printf("%02x", (unsigned int) *s++);
  printf("\n");
}

int main(void)
{
    if (sodium_init() < 0) {
        /* panic! the library couldn't be initialized, it is not safe to use */
        printf("error");
        exit(-1);
    }
    
    std::string str;
    std::cout << "Please, enter your string: ";
    std::getline (std::cin,str);

    unsigned char hash[crypto_generichash_BYTES];

    crypto_generichash(hash, sizeof hash,
                    (const unsigned char*)str.c_str(), str.length(),
                    NULL, 0);
    
    print_hex(hash);
    

    return 0;
}