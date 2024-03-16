/*
 * OPTIONAL FEATURES:
 * - define USE_STATIC_ASSERT for static assertions.
 * - define USE_ASSERT for dynamic assertions.
 * - define ASSERT_ONFAIL to change behavior of assertions when they fail.
 */

/* Include guard */
#ifndef ELM_H
#define ELM_H

/* For C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* Context - compiler */
#ifdef __clang__
#define COMPILER_CLANG 1
#endif
#ifdef __GNUC__
#define COMPILER_GCC 1
#endif
#ifdef _MSC_VER_
#define COMPILER_MSVC 1
#endif
#ifndef COMPILER_CLANG
#define COMPILER_CLANG 0
#endif
#ifndef COMPILER_GCC
#define COMPILER_GCC 0
#endif
#ifndef COMPILER_MSVC
#define COMPILER_MSVC 0
#endif
/* Context - Operating system */
#ifdef _WIN32
#define OS_WINDOWS 1
#endif
#ifdef __gnu_linux__
#define OS_LINUX 1
#endif
#ifdef __APPLE__
#define OS_APPLE 1
#endif
#ifndef OS_WINDOWS
#define OS_WINDOWS 0
#endif
#ifndef OS_LINUX
#define OS_LINUX 0
#endif
#ifndef OS_APPLE
#define OS_APPLE 0
#endif

/* Consts */
/* A pointer with a value of 0 */
#ifndef NULL
#define NULL                ((void*)0)
#endif
#define PI                  3.14159265358979  /* Pi */
#define INF                 (1.0f/0.0f)       /* Infinity for floats */
#define INF_LONG            (1.0/0.0)         /* Infinity for doubles */

/* Static assertions */
#if COMPILER_GCC
#define STATIC_ASSERT(EXPR, MSG) _Static_assert(EXPR, MSG)
#endif
#if COMPILER_MSVC
#define STATIC_ASSERT(EXPR, MSG) static_assert(EXPR, MSG)
#endif

/* Basic types */
/* unsiged integers */
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
#ifdef USE_STATIC_ASSERT
STATIC_ASSERT(sizeof(u8) == 1, "sizeof(u8)");
STATIC_ASSERT(sizeof(u16) == 2, "sizeof(u16)");
STATIC_ASSERT(sizeof(u32) == 4, "sizeof(u32)");
STATIC_ASSERT(sizeof(u64) == 8, "sizeof(u64)");
#endif
/* integers */
typedef char                i8;
typedef short               i16;
typedef int                 i32;
typedef long long           i64;
#ifdef USE_STATIC_ASSERT
STATIC_ASSERT(sizeof(i8) == 1, "sizeof(i8)");
STATIC_ASSERT(sizeof(i16) == 2, "sizeof(i16)");
STATIC_ASSERT(sizeof(i32) == 4, "sizeof(i32)");
STATIC_ASSERT(sizeof(i64) == 8, "sizeof(i64)");
#endif
/* floating point numbers */
typedef float               f32;
typedef double              f64;
#ifdef USE_STATIC_ASSERT
STATIC_ASSERT(sizeof(f32) == 4, "sizeof(f32)");
STATIC_ASSERT(sizeof(f64) == 8, "sizeof(f64)");
#endif
/* Boolean */
#if !defined(__cplusplus) && !defined(__STDBOOL_H)
typedef _Bool bool;
enum { false, true };
#endif

/* Utility macros */
/* Make something a statement, from a macro */
#define AS_STMT(S)          do{S}while(0)
/* Clamp v to the range min - max */
#define CLAMP(V, MIN, MAX)  ((V) < (MIN) ? (MIN) : ((V) > (MAX) ? (MAX) : (V)))
/* Swap the values of the two variables */
#define SWAP(A, B)          AS_STMT( __typeof__(A) TMP = (A); A = (B); B = TMP; )
/* Get the bigger of the two values */
#define MAX(A, B)           ((A) > (B) ? (A) : (B))
/* Get the minimum of the two values */
#define MIN(A, B)           ((A) < (B) ? (A) : (B))
/* Linear interpolation */
#define LERP(A, B, X)       ((A) < (B)) ? \
                            ((A) + ((B)-(A)*(X))) \
                            : ((A) + ((A)-(B)*(X)))
/* Assertions */
#ifdef ENABLE_ASSERT
#ifndef ASSERT_ONFAIL
#define ASSERT_ONFAIL       quit(true)
#endif
#define ASSERT(EXPR)        AS_STMT(if (!(EXPR)) ASSERT_ONFAIL;)
#else
#define ASSERT(EXPR)        
#endif

/* Functions */
/* Terminate program */
extern void quit(bool err);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: ELM_H */
