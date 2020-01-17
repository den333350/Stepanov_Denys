#pragma once

#include <vector>
#include <cstring>

#include "Render.hpp"




class Ghost:public Render {
public:
    int x;
    int y;
    int directionX;
    int directionY;

    int GhostMap[31][28];
   
    int px[31*28], py[31*28];
    int lenght;

    

    void Move(bool energy, int color);
    
private:

    void FillGhostMap();

    void CreatePath();

    void SelectRandDirection();
};