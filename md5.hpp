#ifndef MD5_H
#define MD5_H

#include <cstdint>
#include <string>

class md5 {
    public:
        // constructors
        md5();
        md5(const std::string& text);

        // set methods
        void update(const char *buf, uint32_t length);
        void update(const unsigned char *buf, uint32_t length);
        md5& finalize();

        // get methods
        std::string toString() const;

    private:
        // data
        enum {blocksize = 64}; // VC6 won't eat a const static int here

        bool finalized; // maybe find a way to remove it adds some complexity
        uint8_t buffer[blocksize]; // bytes that didn't fit in last 64 byte chunk
        uint32_t count[2];   // 64bit counter for number of bits (lo, hi)
        uint32_t state[4];   // digest so far
        uint8_t digest[16]; // the result

        // helper methods probably can remove header declaration
        static void decode(uint32_t output[], const uint8_t input[], uint32_t len);
        static void encode(uint8_t output[], const uint32_t input[], uint32_t len);
        void transform(const uint8_t block[blocksize]);
};


#endif
