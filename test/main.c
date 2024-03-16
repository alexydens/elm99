/* Elm headers */
#include <base.h>
#include <arena_alloc.h>
#include <str.h>

/* libc headers */
#include <stdio.h>
#include <stdlib.h>

int main() {
  arena_t arena = create_arena(NULL, 1024 * 4);
  str_t string = string_file(&arena, ".ccls");
  printf("::");
  print_string(string);
  printf("\n");

  arena_free(&arena);
  return 0;
}
