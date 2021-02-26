class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i=31;i>=0;--i) {
            if ((1<<i)&n) res |= 1<<(31-i);
        }
        return res;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i=31;i>=0;--i,n>>=1) {
            if (n&1) res |= 1<<i;
        }
        return res;
    }
};

// Using bit manipulation:

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n&0xffff0000)>>16) | ((n&0x0000ffff)<<16);
        n = ((n&0xff00ff00)>>8) | ((n&0x00ff00ff)<<8);
        n = ((n&0xf0f0f0f0)>>4) | ((n&0x0f0f0f0f)<<4);
        n = ((n&0xcccccccc)>>2) | ((n&0x33333333)<<2);
        n = ((n&0xaaaaaaaa)>>1) | ((n&0x55555555)<<1);
        return n;
    }
};