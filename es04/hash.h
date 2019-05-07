#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define LINE_LENGTH 120
#define KEY_LENGTH 4

uint32_t hash_modulus(const uint8_t *data, uint32_t n);
uint32_t hash_murmur3_32(const uint8_t *key, size_t len, uint32_t seed);
uint8_t rol(uint8_t num);

#endif // HASH_H_INCLUDED
