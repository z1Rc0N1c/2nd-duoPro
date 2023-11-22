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
    obj->isFirstMoved = false;
    obj->moveAllowedSlots = (List*)malloc(sizeof(List*));
    list_init(obj->moveAllowedSlots);

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
        Assign(0, 0, i, 1);
    Assign(0, 1, 0, 0);
    Assign(0, 1, 7, 0);
    Assign(0, 2, 1, 0);
    Assign(0, 2, 6, 0);
    Assign(0, 3, 2, 0);
    Assign(0, 3, 5, 0);
    Assign(0, 4, 3, 0);
    Assign(0, 5,4, 0);

    //백
    for (int i = 0; i < 8; i++)
        Assign(1, 0, i, 6);
    Assign(1, 1, 0, 7);
    Assign(1, 1, 7, 7);
    Assign(1, 2, 1, 7);
    Assign(1, 2, 6, 7);
    Assign(1, 3, 2, 7);
    Assign(1, 3, 5, 7);
    Assign(1, 4, 3, 7);
    Assign(1, 5, 4, 7);

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

short CheckMovingPossible(GameScene* gameScene, Object* obj, int x, int y) {
    int xMove = obj->xPos + x;
    int yMove = obj->yPos + y;
    if (xMove >= 0 && xMove < 8 && yMove >= 0 && yMove < 8) {
        if (gameScene->nodeArray[xMove][yMove]->object &&
            gameScene->nodeArray[xMove][yMove]->object->team == obj->team) return 0;

            //폰은 추가 작업을 거침
            if (obj->objectType == 0 && x != 0 && y != 0) {
                if (!gameScene->nodeArray[xMove][yMove]->object ||
                    gameScene->nodeArray[xMove][yMove]->object->team == obj->team) return 0;
            }
            list_push(obj->moveAllowedSlots, gameScene->nodeArray[xMove][yMove]);

            //다른 팀 말이 있을 경우 해당 말 까지만 이동
            if (gameScene->nodeArray[xMove][yMove]->object &&
                gameScene->nodeArray[xMove][yMove]->object->team != obj->team) return 0;
    }
    return 1;
}

void move_obj(GameScene* gameScene) {
    int j;
    int directionConst = 0;
    if (!gameScene->selectedArray || !gameScene->selectedArray->object) return;
    Object* object = gameScene->selectedArray->object;
    list_releaseList(object->moveAllowedSlots);
    switch (object->objectType) {
        case 0:

            if (object->team == 0) directionConst = 1;
            else directionConst = -1;
            CheckMovingPossible(gameScene, object, 0, 1 * directionConst);
            CheckMovingPossible(gameScene, object, 1, 1 * directionConst);
            CheckMovingPossible(gameScene, object, -1, 1 * directionConst);

            if (!object->isFirstMoved) {
                CheckMovingPossible(gameScene, object, 0, 2 * directionConst);
                object->isFirstMoved = true;
            }
            break;
        case 1:
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, i, 0);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, -i, 0);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, 0, i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, 0, -i);
                if (!t) break;
            }
            break;
        case 2:
            CheckMovingPossible(gameScene, object, 2, 1);
            CheckMovingPossible(gameScene, object, 2, -1);
            CheckMovingPossible(gameScene, object, 1, 2);
            CheckMovingPossible(gameScene, object, 1, -2);
            CheckMovingPossible(gameScene, object, -2, 1);
            CheckMovingPossible(gameScene, object, -2, -1);
            CheckMovingPossible(gameScene, object, -1, 2);
            CheckMovingPossible(gameScene, object, -1, -2);
            break;
        case 3:
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, i, i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, i, -i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, -i, -i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, -i, i);
                if (!t) break;
            }
            break;
        case 4:
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, i, 0);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, -i, 0);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, 0, i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, 0, -i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, i, i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, i, -i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, -i, -i);
                if (!t) break;
            }
            for (int i = 1; i < 8; i++) {
                short t = CheckMovingPossible(gameScene, object, -i, i);
                if (!t) break;
            }
            break;
        case 5:
            CheckMovingPossible(gameScene, object, 1, 0);
            CheckMovingPossible(gameScene, object, -1, 0);
            CheckMovingPossible(gameScene, object, 0, 1);
            CheckMovingPossible(gameScene, object, 0, -1);

            CheckMovingPossible(gameScene, object, 1, 1);
            CheckMovingPossible(gameScene, object, 1, -1);
            CheckMovingPossible(gameScene, object, -1, -1);
            CheckMovingPossible(gameScene, object, -1, 1);
            break;
        default:
            break;
        }



        //switch (objType) {
        //case 1:
        //    for (j = 0; j < size; j++) {
        //        if (Pawn_diag(a, b, size) == 2) {
        //            b->xPosi -= 1;
        //            b->yPosi += 1;
        //        }
        //        else if (Pawn_diag(a, b, size) == 1) {
        //            b->xPosi -= 1;
        //            b->yPosi += 1;
        //        }
        //        else if (Pawn_diag(a, b, size) == 0) {
        //            if (b->xPosi == 7) {
        //                b->xPosi -= 2;
        //            }
        //            else {
        //                b->xPosi -= 1;
        //            }

        //        }
        //        else {
        //            if (x == b->xPosi - 1 && y == b->yPosi) {
        //                b->xPosi -= 1;
        //            }

        //        }
        //        Promotion(a, b, 1);
        //    }break;
        //case 2:
        //    for (j = 0; j < size; j++) {
        //        if ((x == b->xPosi - j && y == b->yPosi) || (x == b->xPosi + j && b->yPosi)) {
        //            b->xPosi = x;
        //        }
        //        else if ((x == b->xPosi && y == b->yPosi + j) || x == b->xPosi && b->yPosi - j) {
        //            b->yPosi = y;
        //        }
        //    }
        //    break;
        //case 3:
        //    for (j = 0; j < size; j++) {
        //        if ((x == b->xPosi + 2 && (y == b->yPosi + 1) || y == b->yPosi - 1)) {
        //            b->xPosi = x;
        //            b->yPosi = y;
        //        }
        //        else if ((x == b->xPosi + 1) || (x == b->yPosi - 1) && y == b->yPosi + 2) {
        //            b->xPosi = x;
        //            b->yPosi = y;
        //        }
        //        else if (x == b->xPosi - 2 && (y == b->yPosi + 1) || (y == b->yPosi - 1)) {
        //            b->xPosi = x;
        //            b->yPosi = y;
        //        }
        //        else if ((x == b->xPosi + 1) || (x == b->xPosi - 1) && y == b->yPosi - 2) {
        //            b->xPosi = x;
        //            b->yPosi = y;
        //        }
        //    }

        //    break;
        //case 4:
        //    for (j = 0; j < size; j++) {
        //        if ((x == b->xPosi + j && y == b->yPosi + j) || (x == b->xPosi - j && y == b->yPosi - j) ||
        //            (x == b->xPosi - j && y == b->yPosi + j) || (x == b->xPosi + j && y == b->yPosi - j)) {
        //            b->xPosi = x;
        //            b->yPosi = y;
        //        }
        //    }
        //    break;
        //case 5:
        //    for (j = 0; j < size; j++) {
        //        if ((x == b->xPosi + j && y == b->yPosi) || (x == b->xPosi - j && b->yPosi)) {
        //            b->xPosi = x;
        //        }
        //        else if ((x == b->xPosi && y == b->yPosi + j) || x == b->xPosi && b->yPosi - j) {
        //            b->yPosi = y;
        //        }
        //        else if ((x == b->xPosi + j && y == b->yPosi + j) || (x == b->xPosi - j && y == b->yPosi - j) ||
        //            (x == b->xPosi - j && y == b->yPosi + j) || (x == b->xPosi + j && y == b->yPosi - j)) {
        //            b->xPosi = x;
        //            b->yPosi = y;
        //        }
        //    }
        //    break;
        //case 6:
        //    for (j = 0; j < size; j++) {
        //        if ((x == b->xPosi + 1 && y == b->yPosi) || (x == b->xPosi - 1 && b->yPosi)) {
        //            b->xPosi = x;
        //        }
        //        else if ((x == b->xPosi && y == b->yPosi + 1) || x == b->xPosi && b->yPosi - 1) {
        //            b->yPosi = y;
        //        }
        //        else if ((x == b->xPosi + 1 && y == b->yPosi + 1) || (x == b->xPosi - 1 && y == b->yPosi - 1) ||
        //            (x == b->xPosi - 1 && y == b->yPosi + 1) || (x == b->xPosi + 1 && y == b->yPosi - 1)) {
        //            b->xPosi = x;
        //            b->yPosi = y;
        //        }
        //    }
        //    break;
        //default:
        //    break;
        //}

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
