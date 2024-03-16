/* Elm headers */
#include <base.h>
#include <arena_alloc.h>
#include <str.h>

/* libc headers */
#include <stdio.h>
#include <stdlib.h>

int main() {
  arena_t arena = create_arena(NULL, 1024 * 4);
  str_t string = string_from(&arena, "...!!!...!!!");
  file_append_string("copy_of_makefile", string);

  arena_free(&arena);
  return 0;
}
