#include "contador.h"

void A_0(){
    uint32_t img[5][5]={
    { 0x000000,   0x200000,   0x200000,   0x200000,   0x000000 },
    { 0x200000,   0x000000,   0x000000,   0x000000,   0x200000 },
    { 0x200000,   0x000000,   0x000000,   0x000000,   0x200000 },
    { 0x200000,   0x000000,   0x000000,   0x000000,   0x200000 },
    { 0x000000,   0x200000,   0x200000,   0x200000,   0x000000 }

    };
    renderRGBMatrix(img);
   
    
   
}