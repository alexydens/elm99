/* Implements arena_alloc.h */
#include <arena_alloc.h>

/* libc headers */
#include <stdlib.h>

/* Create a linear allocator. If no start specified, malloc() will be called. */
arena_t create_arena(void* start, u64 size) {
  arena_t arena = {0};
  if (!size) return arena;
  if (start) {
    arena.start = start;
    arena.own_alloc = false;
  }
  else {
    arena.start = malloc(size);
    arena.own_alloc = true;
  }
  arena.size = size;
  arena.pos = arena.start;
  return arena;
}
/* Destroy and free a linear allocator */
void arena_free(arena_t* arena) {
  if (arena->own_alloc) free(arena->start);
  arena->start = NULL;
  arena->pos = NULL;
  arena->size = 0L;
  arena->own_alloc = false;
}
/* Allocate size bytes on the linear allocator. If insufficient space, NULL */
void* arena_alloc(arena_t* arena, u64 size) {
  void* old_pos = arena->pos;
  arena->pos = (void*)((char*)arena->pos + size);
  return old_pos;
}
