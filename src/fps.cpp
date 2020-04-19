#include "fps.h"

namespace Engine {

    FrameRateSecond::FrameRateSecond(int fps) {
        frame_delay = 1000 / fps;
    }

    void FrameRateSecond::update_timer() {
        frame_start = SDL_GetTicks();
    }

    void FrameRateSecond::handle_fps() {

        frame_time = SDL_GetTicks() - frame_start;

        if(frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }
};
