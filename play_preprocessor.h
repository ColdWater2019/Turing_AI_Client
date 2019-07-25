#ifndef PLAY_PREPROCESSOR_H
#define PLAY_PREPROCESSOR_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *target;
    const char *tag;
    int frame_size;
    char *type;
} play_preprocessor_cfg_t;

struct play_preprocessor {
    const char *type;
    int (*init)(struct play_preprocessor *self, play_preprocessor_cfg_t *cfg);
    int (*read)(struct play_preprocessor *self, char *data, size_t data_len);
    void (*destroy)(struct play_preprocessor *self);
    void *userdata;
};

typedef struct play_preprocessor play_preprocessor_t;


#ifdef __cplusplus
}
#endif
#endif
