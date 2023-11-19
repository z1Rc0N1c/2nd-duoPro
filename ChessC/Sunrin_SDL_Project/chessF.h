#pragma once

typedef struct Object {
    int team;
    int isPromoted;
    int objectType;
    int xPos;
    int yPos;
    int isMovement;
    char PromotedObject[10];
} Object;

void assignMent(struct GameScene*);
void check_obj(Object* a, int objType, int size, int x, int y);
void move_obj(Object* a, int objType, int size, int x, int y);
