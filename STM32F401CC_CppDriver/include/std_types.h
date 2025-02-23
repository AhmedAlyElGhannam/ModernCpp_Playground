#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t; 
typedef unsigned long int uint32_t;
typedef unsigned long long int uint64_t;

typedef signed char sint8_t;
typedef signed short int sint16_t;
typedef signed long int sint32_t;

typedef float float32_t;
typedef double float64_t;

#define NULL ((void*)0)

#ifdef __cplusplus
}
#endif

#endif