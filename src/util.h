#include <raylib.h>

#define ScaleRect(rect, scale) ({ \
    Rectangle scaled = {rect.x * scale, rect.y * scale, rect.width * scale, rect.height * scale}; \
    scaled; \
})