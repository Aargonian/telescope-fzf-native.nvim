#include <stdbool.h>
#include <stdlib.h>

// TODO(conni2461): WE NEED unicode support
typedef char rune; // ADDITIONAL 32bit char

typedef struct {
  int16_t *data;
  size_t size;
  size_t cap;
} i16_t;

typedef struct {
  int32_t *data;
  size_t size;
  size_t cap;
} i32_t;

typedef struct {
  char *data; // byte or rune, think about this
  size_t size;
} string_t;

typedef struct {
  string_t slice;
  bool in_bytes;
  bool trim_length_known;
  /* u_int16_t trim_length; */

  int32_t index;
} chars_t;

// Helpers for slice
#define slice_def(name, type)                                                  \
  typedef struct {                                                             \
    type *data;                                                                \
    int32_t from;                                                              \
    int32_t to;                                                                \
    int32_t size;                                                              \
  } name##_slice_t;                                                            \
                                                                               \
  name##_slice_t slice_##name(type *input, int32_t from, int32_t to);          \
  name##_slice_t slice_##name##_right(type *input, int32_t to);
slice_def(i16, int16_t);
slice_def(i32, int32_t);
slice_def(str, char);
int32_t index_byte(string_t *string, char b);

// chars_t helpers
int32_t rune_len(rune *arr);
bool is_space(char ch);
int32_t leading_whitespaces(chars_t *chars);
int32_t trailing_whitespaces(chars_t *chars);
void copy_runes(chars_t *chars, i32_t *destination);
void copy_into_i16(i16_t *dest, i16_slice_t *src);

// min + max
int16_t min16(int16_t a, int16_t b);
int16_t max16(int16_t a, int16_t b);
int32_t min32(int32_t a, int32_t b);
int32_t max32(int32_t a, int32_t b);
