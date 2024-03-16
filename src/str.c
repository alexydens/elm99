/* Implements str.h */
#include <str.h>

/* libc headers */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/* Create string from literal */
str_t string_from(arena_t* arena, const char* literal) {
  str_t string;
  string.size = strlen(literal);
  string.ptr = arena_alloc(arena, strlen(literal));
  memcpy(string.ptr, literal, strlen(literal));
  return string;
}
/* Create string from stdin with a maximum of max bytes */
str_t string_input(arena_t* arena, u32 max) {
  str_t string;
  char* res = malloc(max);
  u64 bytes_in = read(STDIN_FILENO, res, max);
  string.ptr = arena_alloc(arena, bytes_in);
  memcpy(string.ptr, res, bytes_in);
  string.size = strlen(string.ptr);
  free(res);
  return string;
}
/* Create string by reading full file */
str_t string_file(arena_t* arena, const char* path) {
  str_t string = {0};
  u64 size;
  FILE* ptr = fopen(path, "r");
  if (!ptr) return string;
  fseek(ptr, 0L, SEEK_END);
  size = ftell(ptr);
  fseek(ptr, 0L, SEEK_SET);
  string.ptr = arena_alloc(arena, size);
  string.size = size;
  fread(string.ptr, size, 1, ptr);
  fclose(ptr);
  return string;
}
/* Create string by reading size bytes of file */
str_t string_file_part(arena_t* arena, const char* path, u32 size) {
  str_t string = {0};
  char* res = malloc(size);
  FILE* ptr = fopen(path, "r");
  if (!ptr) return string;
  u64 bytes_in = fread(res, 1, size, ptr);
  string.ptr = arena_alloc(arena, bytes_in);
  memcpy(string.ptr, res, bytes_in);
  string.size = strlen(string.ptr);
  free(res);
  fclose(ptr);
  return string;
}
/* Create string by copying existing string */
str_t string_copy(arena_t* arena, const str_t string) {
  str_t str;
  str.size = string.size;
  str.ptr = arena_alloc(arena, str.size);
  memcpy(str.ptr, string.ptr, str.size);
  return str;
}
/* Create string by concatenating two other strings */
str_t string_concat(
    arena_t* arena,
    const str_t str1,
    const str_t str2
) {
  str_t string;
  string.size = str1.size + str2.size;
  string.ptr = arena_alloc(arena, string.size);
  memcpy(string.ptr, str1.ptr, str1.size);
  memcpy(string.ptr+str1.size, str2.ptr, str2.size);
  return string;
}

/* Write string to file */
void file_write_string(const char* path, const str_t string) {
  FILE* ptr = fopen(path, "w");
  if (!ptr) return;
  fwrite(string.ptr, string.size, 1, ptr);
  fclose(ptr);
}
/* Append string to file */
void file_append_string(const char* path, const str_t string) {
  FILE* ptr = fopen(path, "a");
  if (!ptr) return;
  fwrite(string.ptr, string.size, 1, ptr);
  fclose(ptr);
}
/* Print a string */
void print_string(const str_t string) {
  printf("%.*s", string.size, string.ptr);
}

/* Compare two strings bool is equal */
bool string_compare(const str_t str1, const str_t str2) {
  u64 i;
  bool res = true;
  if (str1.size != str2.size) return false;
  for (i = 0; i < str1.size; i++) {
    if (str1.ptr[i] != str2.ptr[i]) res = false;
  }
  return res;
}
