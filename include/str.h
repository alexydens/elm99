/* Include guard */
#ifndef ELM_SLICE_H
#define ELM_SLICE_H

/* For C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* Base */
#include "base.h"
#include "arena_alloc.h"

/* String string structure */
typedef struct {
  char* ptr;
  u32 size;
} str_t;

/* Create string from literal */
extern str_t string_from(arena_t* arena, const char* literal);
/* Create string from stdin with a maximum of max bytes */
extern str_t string_input(arena_t* arena, u32 max);
/* Create string by reading full file */
extern str_t string_file(arena_t* arena, const char* path);
/* Create string by reading size bytes of file */
extern str_t string_file_part(arena_t* arena, const char* path, u32 size);
/* Create string by copying existing string */
extern str_t string_copy(arena_t* arena, const str_t string);
/* Create string by concatenating two other strings */
extern str_t string_concat(
    arena_t* arena,
    const str_t str1,
    const str_t str2
);

/* Write string to file */
extern void file_write_string(const char* path, const str_t string);
/* Append string to file */
extern void file_append_string(const char* path, const str_t string);
/* Print a string */
extern void print_string(const str_t string);

/* Compare two strings bool is equal */
extern bool string_compare(const str_t str1, const str_t str2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: ELM_SLICE_H */
