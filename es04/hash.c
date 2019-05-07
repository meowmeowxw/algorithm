#include "hash.h"

uint32_t hash_modulus(const uint8_t *data, uint32_t n){
    uint32_t val;

    val= data[0] | (data[1]<< 8) | (data[2]<<16) | (data[3] <<24);
    return (val%n);
}

uint32_t hash_murmur3_32(const uint8_t *key, size_t len, uint32_t seed){
    uint32_t h= seed;
    if(len>3){
        const uint32_t *key_x4= (const uint32_t *)key;
        size_t i= len >> 2;
        do {
            uint32_t k= *key_x4;
            key_x4++;
            k*=0xcc9e2d51;
            k=(k<<15) | (k>>17); // rol of 15
            k*=0x1b873593;
            h^=k;
            h= (h<<13) | (h>>19);
            h= (h*5) + 0xe6546b64;
        } while (--i);
        key=(const uint16_t*)key_x4;
    } else{
        size_t i = len & 3;
        uint32_t k=0;
        key= &key[i-1];
        do{
            k <<= 8;
            k |= *key--;
        }while (--i);
        k*=0xcc9e2d51;
        k= (k<<15) | (k>>17);
        k*=0x1b873593;
        h= h^k;
    }
    h = h ^ len;
    h = h ^ (h >> 16);
    h = h*0x85ebca6b;
    h = h ^ (h >> 13);
    h = h* 0xc2b2ae35;
    h= h ^ (h >> 16);

    return h;
}

