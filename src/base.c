/* Implements base.h */
#include <base.h>

/* libc headers */
#include <stdlib.h>

/* Terminate program */
void quit(bool err) {
  exit(err ? EXIT_FAILURE : EXIT_SUCCESS);
}
