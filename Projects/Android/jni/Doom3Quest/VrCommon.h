#if !defined(vrcommon_h)
#define vrcommon_h

#include <VrApi_Input.h>

#include <android/log.h>

#include "mathlib.h"
#include "VrClientInfo.h"

#define LOG_TAG "D3QUESTVR"

#ifndef NDEBUG
#define DEBUG 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ALOGE(...) __android_log_print( ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__ )

#if DEBUG
#define ALOGV(...) __android_log_print( ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__ )
#else
#define ALOGV(...)
#endif

#define TIC_RATE 60

float playerHeight;
float playerYaw;

bool showingScreenLayer;

float radians(float deg);

float degrees(float rad);

bool isMultiplayer();

double GetTimeInMilliSeconds();

float length(float x, float y);

float nonLinearFilter(float in);

bool between(float min, float val, float max);

void rotateAboutOrigin(float v1, float v2, float rotation, vec2_t out);

void QuatToYawPitchRoll(ovrQuatf q, vec3_t rotation, vec3_t out);

void handleTrackedControllerButton_AsButton(ovrInputStateTrackedRemote *trackedRemoteState,
                                   ovrInputStateTrackedRemote *prevTrackedRemoteState,
                                   bool mouse, uint32_t button, int key);

void handleTrackedControllerButton_AsKey(ovrInputStateTrackedRemote *trackedRemoteState,
                                   ovrInputStateTrackedRemote *prevTrackedRemoteState,
                                   uint32_t button, int key);

void handleTrackedControllerButton_AsToggleButton(ovrInputStateTrackedRemote *trackedRemoteState,
                                   ovrInputStateTrackedRemote *prevTrackedRemoteState,
                                   uint32_t button, int key);

void handleTrackedControllerButton_AsImpulse(ovrInputStateTrackedRemote * trackedRemoteState,
        ovrInputStateTrackedRemote * prevTrackedRemoteState, uint32_t button, int key);


void controlMouse(ovrInputStateTrackedRemote *newState, ovrInputStateTrackedRemote *oldState);


//Called from engine code
bool Doom3Quest_useScreenLayer();

void Doom3Quest_GetScreenRes(int *width, int *height);

void Doom3Quest_Vibrate(int duration, int channel, float intensity);

bool Doom3Quest_processMessageQueue();

void Doom3Quest_FrameSetup();

void Doom3Quest_setUseScreenLayer(int screen);

void Doom3Quest_processHaptics();

void Doom3Quest_getHMDOrientation();

void Doom3Quest_getTrackedRemotesOrientation(int vr_control_scheme);

void Doom3Quest_ResyncClientYawWithGameYaw();

void Doom3Quest_prepareEyeBuffer(int eye);

void Doom3Quest_finishEyeBuffer(int eye);

void Doom3Quest_submitFrame();

void GPUDropSync();

void GPUWaitSync();

#ifdef __cplusplus
}
#endif

#endif //vrcommon_h