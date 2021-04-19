#ifndef MD5_H
#define MD5_H

#include <cstdint>
#include <string>

class md5 {
    public:
        // constructors
        md5() : finalized(false), count { 0, 0 }, state { 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476 }  {
        }
        md5(const std::string &text) : finalized(false), count { 0, 0 }, state { 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476 } {
            update(text.c_str(), text.length());
            finalize();
        }

        // set methods
        void update(const char *buf, uint32_t length);
        void update(const unsigned char *buf, uint32_t length);
        md5& finalize();

        // get methods
        std::string toString() const;

    private:
        // data
        enum {blocksize = 64}; // VC6 won't eat a const static int here, also better than a define in header

        bool finalized;            // maybe find a way to remove it adds some complexity
        uint8_t buffer[blocksize]; // bytes that didn't fit in last 64 byte chunk
        uint32_t count[2];         // 64bit counter for number of bits (lo, hi), c++11 has uint64_t now upgrade?
        uint32_t state[4];         // digest so far
        uint8_t digest[16];        // the result

        // helper functions that rely on class data
        void transform(const uint8_t block[blocksize]);
};


#endif
