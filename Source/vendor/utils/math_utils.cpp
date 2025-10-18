#include <math.h>

float clamp(float value, float min, float max){
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

int lerp(int a, int b, float t){
    return a + (b - a) * t;
}
