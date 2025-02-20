#ifndef STD_LIB_H
#define STD_LIB_H

uint8_t strlen(const char* ptr);
uint8_t strnlen(const char* ptr, int max);

char* strncpy(char* dest, const char* src, int count);
char* strcpy(char* dest, const char* src);

#endif