#ifndef DUISDK_H
#define DUISDK_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include "play_preprocessor.h"
#include "record_writer.h"
#include "playback_device.h"
#include "capture_device.h"

#ifndef DUISDK_EXPORT
#ifdef __GNUC__
#define DUISDK_EXPORT  __attribute ((visibility("default")))
#else
#define DUISDK_EXPORT 
#endif
#endif

typedef enum {
    CMD_RECORDER_START,
    CMD_RECORDER_STOP,
    CMD_PLAYER_PLAY,
    INFO_STATE_INFO
} duisdk_msg_type_t;

typedef struct {
    duisdk_msg_type_t type;
    union {
        struct {
            char *target;
            play_preprocessor_t preprocessor;
            OS_BOOL end_session;
            char *priv_data;
        } player;
        struct {
            char *target;
            char *type;
            record_writer_t writer;
            OS_BOOL end_session;
            char *priv_data;
        } recorder;
    };
} duisdk_msg_t;

typedef void (*duisdk_listen_cb)(duisdk_msg_t *msg, void *userdata);

DUISDK_EXPORT int duisdk_init(const char *cfg, duisdk_listen_cb listen, void *userdata);

DUISDK_EXPORT int duisdk_register_capture(capture_device_t *device);
DUISDK_EXPORT int duisdk_register_playback(playback_device_t *device);
DUISDK_EXPORT int duisdk_external_trigger();
DUISDK_EXPORT int duisdk_recorder_start();
DUISDK_EXPORT int duisdk_recorder_stop();

DUISDK_EXPORT int duisdk_system_reset();

DUISDK_EXPORT int duisdk_native_response(const char *result);

DUISDK_EXPORT int duisdk_player_play(duisdk_msg_t *msg);

DUISDK_EXPORT int duisdk_player_pause();

DUISDK_EXPORT int duisdk_player_resume();

DUISDK_EXPORT int duisdk_player_stop();

DUISDK_EXPORT void duisdk_exit();

#ifdef __cplusplus
}
#endif
#endif
