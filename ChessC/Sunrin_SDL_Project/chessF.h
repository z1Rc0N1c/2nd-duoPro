#pragma once

typedef struct Object {
    int team;
    int isPromoted;
    int objectType;
    int xPos;
    int yPos;
    int isMovement;
    char PromotedObject[10];
    List* moveAllowedSlots;
    bool isFirstMoved;
} Object;

void assignMent(struct GameScene*);
void check_obj(Object* a, int objType, int size, int x, int y);
void move_obj(GameScene* gameScene);
