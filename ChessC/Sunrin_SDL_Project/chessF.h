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
void move_obj(struct GameScene* gameScene);
