#ifndef face_hpp
#define face_hpp

#include <stdio.h>

class face
{
public:
    void receive_coordonates(float x, float y, float z, char place, char color);
    void get_coordonates();
    private :
    float base_x;
    float base_y;
    float base_z;
    float final_x;
    float final_y;
    float final_z;
};

#endif /* face_hpp */



