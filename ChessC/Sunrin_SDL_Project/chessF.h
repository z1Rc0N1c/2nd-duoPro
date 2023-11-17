#pragma once

typedef struct Object {
    char team[6];
    int isDead;
    int isPromoted;
    char objectType[10];
    int xPos;
    int yPos;
    int isMovement;
    char PromotedObject[10];
} Object;

void assignMent(Object* objects, const char* team, int objType, int size);
void check_obj(Object* a, int objType, int size, int x, int y);
void move_obj(Object* a, int objType, int size, int x, int y);
