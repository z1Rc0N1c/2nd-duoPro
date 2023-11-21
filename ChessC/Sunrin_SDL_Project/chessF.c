#include "pch.h"

//typedef struct Object {
//    char team[6];
//    int isDead;
//    int isPromoted;
//    char objectType[10];
//    int xPos;
//    int yPos;
//    int isMovement;
//    char PromotedObject[10];
//} Object;

int i;
Slot* slots[8][8];

void Assign(int team, int type, int x, int y) {
    Object* obj = (Object*)malloc(sizeof(Object));
    obj->xPos = x;
    obj->yPos = y;
    obj->team = team;
    obj->objectType = type;

    slots[x][y]->object = obj;
}

void assignMent(GameScene* gameScene) {//기물 선언용 함수
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Slot* newNode = (Slot*)malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->object = NULL;
            newNode->positionX = gameScene->board.x + (gameScene->board.w / 8) * (i + 1);
            newNode->positionY = gameScene->board.y + (gameScene->board.h / 8) * (j + 1);
            slots[i][j] = newNode;
        }
    }
    //흑
    for (int i = 0; i < 8; i++)
        Assign(0, 0, 1, i);
    Assign(0, 1, 0, 0);
    Assign(0, 1, 0, 7);
    Assign(0, 2, 0, 1);
    Assign(0, 2, 0, 6);
    Assign(0, 3, 0, 2);
    Assign(0, 3, 0, 5);
    Assign(0, 4, 0, 3);
    Assign(0, 5, 0, 4);

    //백
    for (int i = 0; i < 8; i++)
        Assign(1, 0, 6, i);
    Assign(1, 1, 7, 0);
    Assign(1, 1, 7, 7);
    Assign(1, 2, 7, 1);
    Assign(1, 2, 7, 6);
    Assign(1, 3, 7, 2);
    Assign(1, 3, 7, 5);
    Assign(1, 4, 7, 3);
    Assign(1, 5, 7, 4);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            gameScene->nodeArray[i][j] = slots[i][j];
        }
    }
    //for (i = 0; i < size; i++) {
    //    Object thisObject = objects[i];
    //    strncpy(thisObject.team, team, sizeof(thisObject.team));
    //    thisObject.team[sizeof(thisObject.team) - 1] = '\0';
    //    thisObject.isDead = 0;

    //    if (strcmp(thisObject.team, "white") == 0) {
    //        switch (objType) {
    //        case 1: strcpy(thisObject.objectType, "Pawn"); thisObject.xPos = 2; break;
    //        case 2: strcpy(thisObject.objectType, "Rook"); thisObject.xPos = 1; break;
    //        case 3: strcpy(thisObject.objectType, "Knight"); thisObject.xPos = 1; break;
    //        case 4: strcpy(thisObject.objectType, "Bishop"); thisObject.xPos = 1; break;
    //        case 5: strcpy(thisObject.objectType, "Queen"); thisObject.xPos = 1; break;
    //        case 6: strcpy(thisObject.objectType, "King"); thisObject.xPos = 1; break;
    //        default: break;
    //        }
    //    }
    //    else {
    //        switch (objType) {
    //        case 1: strcpy(thisObject.objectType, "Pawn"); thisObject.xPos = 7; break;
    //        case 2: strcpy(thisObject.objectType, "Rook"); thisObject.xPos = 8; break;
    //        case 3: strcpy(thisObject.objectType, "Knight"); thisObject.xPos = 8; break;
    //        case 4: strcpy(thisObject.objectType, "Bishop"); thisObject.xPos = 8; break;
    //        case 5: strcpy(thisObject.objectType, "Queen"); thisObject.xPos = 8; break;
    //        case 6: strcpy(thisObject.objectType, "King"); thisObject.xPos = 8; break;
    //        default: break;
    //        }
    //    }

    //    if (strcmp(thisObject.team, "white") == 0) {
    //        switch (objType) {
    //        case 1: thisObject.yPos = i + 1; break;
    //        case 2: thisObject.yPos = (i == 0) ? 1 : 8; break;
    //        case 3: thisObject.yPos = (i == 0) ? 2 : 7; break;
    //        case 4: thisObject.yPos = (i == 0) ? 3 : 6; break;
    //        case 5: thisObject.yPos = 5; break;
    //        case 6: thisObject.yPos = 4; break;
    //        default: break;
    //        }
    //    }
    //    else {
    //        switch (objType) {
    //        case 1: thisObject.yPos = i + 1; break;
    //        case 2: thisObject.yPos = (i == 0) ? 1 : 8; break;
    //        case 3: thisObject.yPos = (i == 0) ? 2 : 7; break;
    //        case 4: thisObject.yPos = (i == 0) ? 3 : 6; break;
    //        case 5: thisObject.yPos = 4; break;
    //        case 6: thisObject.yPos = 5; break;
    //        default: break;
    //        }
    //    }
    //    (slots[thisObject.xPos][thisObject.yPos]).object = &thisObject;
    //}



}
void check_obj(Object *a, int objType, int size, int x, int y){//클릭했을 시에 무었을 선택했는지 확인하는 함수
    int j;
    switch (objType) {
        case 1:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    printf("(%d, %d) 좌표의 %s 선택했습니다.", x, y, a[j].objectType);
                }else{
                    printf("Cannot find Object, Reselect");break;
                }
            }
            break;
        case 2:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[j].objectType);
                }
            }
            break;
        case 3:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[j].objectType);
                }
            }
            break;
        case 4:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[j].objectType);
                }
            }
            break;
        case 5:
            if (a->xPos == x && a->yPos == y) {
                printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[i].objectType);
            }else{
                printf("Cannot find Object, Reselect");
            }
            break;
        case 6:
            if (a->xPos == x && a->yPos == y) {
                printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[i].objectType);
            } else {
                printf("Cannot find Object, Reselect");
            }
            break;
    }

}
void move_obj(Object *a, int objType, int size, int x, int y){
    int j;
    if(a->team == "white"){
        switch (objType) {
            case 1:
                for(j=0; j<size; j++){
                    if(a->xPos+1 == x&&(a->yPos+1 == y||a->yPos-1 == y)){

                    }else{
                        a->xPos+=1;
                    }break;
                }

            case 2:break;
            case 3:break;
            case 4:break;
            case 5:break;
            case 6:break;
            default:break;
        }
    }else{
        switch (objType) {
            switch (objType) {
                case 1:break;
                case 2:break;
                case 3:break;
                case 4:break;
                case 5:break;
                case 6:break;
            }
        }
    }
}

//int main() {
//    Object *whitePieces, *blackPieces;
//    whitePieces = (Object*)malloc(16 * sizeof(Object));
//    blackPieces = (Object*)malloc(16 * sizeof(Object));
//
//    if (whitePieces == NULL || blackPieces == NULL) {
//        printf("메모리 할당 오류!\n");
//        return 1;
//    }
//
//    assignMent(whitePieces, "white", 1, 8);
//    assignMent(blackPieces, "black", 1, 8);
//    assignMent(whitePieces + 8, "white", 2, 2);
//    assignMent(blackPieces + 8, "black", 2, 2);
//    assignMent(whitePieces + 10, "white", 3, 2);
//    assignMent(blackPieces + 10, "black", 3, 2);
//    assignMent(whitePieces + 12, "white", 4, 2);
//    assignMent(blackPieces + 12, "black", 4, 2);
//    assignMent(whitePieces + 14, "white", 5, 1);
//    assignMent(blackPieces + 14, "black", 5, 1);
//    assignMent(whitePieces + 15, "white", 6, 1);
//    assignMent(blackPieces + 15, "black", 6, 1);
//
//    // 출력 예시
//    for (i = 0; i < 16; i++) {
//        printf("%s %d %d %s %d %d %d %s\n", whitePieces[i].team, whitePieces[i].isDead, whitePieces[i].isPromoted,
//               whitePieces[i].objectType, whitePieces[i].xPos, whitePieces[i].yPos, whitePieces[i].isMovement,
//               whitePieces[i].PromotedObject);
//    }
//    check_obj(whitePieces,1, 8, 1, 1);
//    free(whitePieces);
//    free(blackPieces);
//    return 0;
//}
