#include "contador.h"

void A_8(){
    uint32_t img1[5][5]={
    { 0x000000,   0x002000,   0x002000,   0x002000,   0x000000 },
    { 0x000000,   0x002000,   0x000000,   0x002000,   0x000000 },
    { 0x000000,   0x002000,   0x002000,   0x002000,   0x000000 },
    { 0x000000,   0x002000,   0x000000,   0x002000,   0x000000 },
    { 0x000000,   0x002000,   0x002000,   0x002000,   0x000000 }
    };
    renderRGBMatrix(img1);
   
}