#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i;
typedef struct Object{
    char team[6];
    int isDead;
    int isPromoted;
    char objectType[10];
    int objNum;//1은 폰, 2은 룩, 3은 나이트, 4는 비숍, 5은 퀸, 6은 킹
    int xPos;
    int yPos;
    int isMovement;
    char PromotedObject[10];
}Pawn, Rook, Knight, Bishop, Queen, King;
void assignment(struct Object *a, const char *team, int objType, int size) {
    for (i = 0; i < size; i++) {
        strncpy(a[i].team, team, sizeof(a[i].team));
        a[i].team[sizeof(a[i].team) - 1] = '\0';
        a[i].isDead = 0;
        a[i].isPromoted = 0;
        if(strcmp(a[i].team, "white")==0){
            switch (objType) {
                case 1:strcpy(a[i].objectType, "Pawn");a[i].xPos = 2;break;
                case 2:strcpy(a[i].objectType, "Rook");a[i].xPos = 1;break;
                case 3:strcpy(a[i].objectType, "Knight");a[i].xPos = 1;break;
                case 4:strcpy(a[i].objectType, "Bishop");a[i].xPos = 1;break;
                case 5:strcpy(a[i].objectType, "Queen");a[i].xPos = 1;break;
                case 6:strcpy(a[i].objectType, "King");a[i].xPos = 1;break;
                default:break;
            }
        }else{
            switch (objType) {
                case 1:strcpy(a[i].objectType, "Pawn");a[i].xPos = 7;break;
                case 2:strcpy(a[i].objectType, "Rook");a[i].xPos = 8;break;
                case 3:strcpy(a[i].objectType, "Knight");a[i].xPos = 8;break;
                case 4:strcpy(a[i].objectType, "Bishop");a[i].xPos = 8;break;
                case 5:strcpy(a[i].objectType, "Queen");a[i].xPos = 8;break;
                case 6:strcpy(a[i].objectType, "King");a[i].xPos = 8;break;
                default:break;
            }
        }
        if (strcmp(a[i].team, "white") == 0)
            switch (objType) {
                case 1:
                    a[i].yPos = i + 1;
                    break;
                case 2:
                    if (i == 0) { a[i].yPos = 1; }
                    else { a[i].yPos = 8; }
                    break;
                case 3:
                    if (i == 0) { a[i].yPos = 2; }
                    else { a[i].yPos = 7; }
                    break;
                case 4:
                    if (i == 0) { a[i].yPos = 3; }
                    else { a[i].yPos = 6; }
                    break;
                case 5:
                    a[i].yPos = 4;
                    break;
                case 6:
                    a[i].yPos = 5;
                    break;
                default:
                    break;
            }
        else {
            switch (objType) {
                case 1:
                    a[i].yPos = i + 1;
                    break;
                case 2:
                    if (i == 0) { a[i].yPos = 1; }
                    else { a[i].yPos = 8; }
                    break;
                case 3:
                    if (i == 0) { a[i].yPos = 2; }
                    else { a[i].yPos = 7; }
                    break;
                case 4:
                    if (i == 0) { a[i].yPos = 3; }
                    else { a[i].yPos = 6; }
                    break;
                case 5:
                    a[i].yPos = 4;
                    break;
                case 6:
                    a[i].yPos = 5;
                    break;
                default:
                    break;
            }
        }
        a[i].isMovement = 0;
        a[i].PromotedObject[0] = '\0';
    }
}
int size;
int main() {
    Pawn *wPawn, *bPawn;
    Rook *wRook, *bRook;
    Knight *wKnight, *bKnight;
    Bishop *wBishop, *bBishop;
    Queen *wQueen, *bQueen;
    King *wKing, *bKing;
    wPawn = (struct Object *) malloc(8 * sizeof(struct Object));
    bPawn = (struct Object *) malloc(8*sizeof(struct Object));
    wKnight = (struct Object *) malloc(2*sizeof(struct Object));
    bKnight = (struct Object *) malloc(2*sizeof(struct Object));
    wRook = (struct Object *) malloc(2*sizeof(struct Object));
    bRook = (struct Object *) malloc(2*sizeof(struct Object));
    wBishop = (struct Object *) malloc(2*sizeof(struct Object));
    bBishop = (struct Object *) malloc(2*sizeof(struct Object));
    wQueen = (struct Object *) malloc(1*sizeof(struct Object));
    bQueen = (struct Object *) malloc(1*sizeof(struct Object));
    wKing = (struct Object *) malloc(1*sizeof(struct Object));
    bKing = (struct Object *) malloc(1*sizeof(struct Object));
    if(wPawn == NULL||bPawn == NULL||wRook == NULL||bRook == NULL||wKnight == NULL||bKnight == NULL
       ||wBishop == NULL||bBishop == NULL||wQueen == NULL||bQueen == NULL||wKing == NULL||bKing == NULL){
        printf("메모리 할당 오류!\n");
    }
    wPawn->objNum = 1;
    bPawn->objNum = 1;
    wRook->objNum = 2;
    bRook->objNum = 2;
    wKnight->objNum = 3;
    bKnight->objNum = 3;
    wBishop->objNum = 4;
    bBishop->objNum = 4;
    wQueen->objNum = 5;
    bQueen->objNum = 5;
    wKing->objNum = 6;
    bKing->objNum = 6;
    size = 8;
    strcpy(wPawn->team, "white");
    assignment(wPawn, wPawn->team, wPawn->objNum, size);
    strcpy(bPawn->team, "black");
    assignment(bPawn, bPawn->team, bPawn->objNum, size);
    size = 2;
    strcpy(wRook->team, "white");
    assignment(wRook, wRook->team, wRook->objNum, size);
    strcpy(bRook->team, "white");
    assignment(bRook, bRook->team, bRook->objNum, size);
    strcpy(wKnight->team, "white");
    assignment(wKnight, wKnight->team, wKnight->objNum, size);
    strcpy(bKnight->team, "white");
    assignment(bKnight, bKnight->team, bKnight->objNum, size);
    strcpy(wBishop->team, "white");
    assignment(wBishop, wBishop->team, wBishop->objNum, size);
    strcpy(bBishop->team, "white");
    assignment(bBishop, bBishop->team, bBishop->objNum, size);
    size = 1;
    strcpy(wQueen->team, "white");
    assignment(wQueen, wQueen->team, wQueen->objNum, size);
    strcpy(bQueen->team, "white");
    assignment(bQueen, bQueen->team, bQueen->objNum, size);
    strcpy(wKing->team, "white");
    assignment(wKing, wKing->team, wKing->objNum, size);
    strcpy(bKing->team, "white");
    assignment(bKing, bKing->team, bKing->objNum, size);


    for(i = 0; i<8; i++){
        printf("%s %d %d %s %d %d %d %s\n", wPawn[i].team, wPawn[i].isDead, wPawn[i].isPromoted,  wPawn[i].objectType,
               wPawn[i].xPos, wPawn[i].yPos, wPawn[i].isMovement, wPawn[i].PromotedObject);
    }
    //
    //



    free(wPawn);
    free(bPawn);
    free(wRook);
    free(bRook);
    free(wKnight);
    free(bKnight);
    free(wBishop);
    free(bBishop);
    free(wQueen);
    free(bQueen);
    free(wKing);
    free(bKing);
    return 0;
}
