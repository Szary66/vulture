#pragma once

#include <cinttypes>
#include "windows/WindowEvents.hpp"

namespace vulture{
    namespace window{
        class IEventHandler{
        public:
            virtual void onShown(const WindowEvent::Shown &){}
            virtual void onExposed(const WindowEvent::Exposed &){}
            virtual void onMoved(const WindowEvent::Moved &){}
            virtual void onResized(const WindowEvent::Resized &){}
            virtual void onMinimized(const WindowEvent::Minimized &){}
            virtual void onMaximized(const WindowEvent::Maximized &){}
            virtual void onRestored(const WindowEvent::Restored &){}
            virtual void onClosed(const WindowEvent::Closed &){}
        };
    }
}
