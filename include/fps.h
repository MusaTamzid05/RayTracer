#ifndef FPS_H
#define FPS_H

#include <SDL2/SDL.h>

namespace Engine {

    class FrameRateSecond {

        public:
            FrameRateSecond(int fps = 60);

            void update_timer();
            void handle_fps();

        private:
            float frame_delay;
            Uint32 frame_start;
            int frame_time;

    };

};


#endif
