#pragma once
#include <cinttypes>

namespace vulture{
    class Window{
    public:
        enum Flags : uint32_t{
            FullScreen = 1,
            Shown = 4,
            Hidden = 8,
            BorderLess = 16,
            Resizable = 32,
            Minimized = 64,
            Maximized = 128,
            Input_Grabbed = 256,
            Input_Focus = 512,
            Mouse_Focus = 1024,
            Foreign = 2048,
            FullScreen_Desktop = 4096 | FullScreen
        };
    };
}