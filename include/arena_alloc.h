/* Include guard */
#ifndef ELM_ARENA_ALLOC_H
#define ELM_ARENA_ALLOC_H

/* For C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* Base headers */
#include "base.h"

/* Linear allocator struct */
typedef struct {
  void* start;
  void* pos;
  u64 size;
  bool own_alloc;
} arena_t;

/* Create a linear allocator. If no start specified, malloc() will be called. */
extern arena_t create_arena(void* start, u64 size);
/* Destroy and free a linear allocator */
extern void arena_free(arena_t* arena);
/* Allocate size bytes on the linear allocator. If insufficient space, NULL */
extern void* arena_alloc(arena_t* arena, u64 size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: ELM_ARENA_ALLOC_H */
