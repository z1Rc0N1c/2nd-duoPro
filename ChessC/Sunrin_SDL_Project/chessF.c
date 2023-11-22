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

void Assign(int team, int type, int x, int y, GameScene* gameScene) {
    Object* obj = (Object*)malloc(sizeof(Object));
    obj->xPos = x;
    obj->yPos = y;
    obj->team = team;
    obj->objectType = type;
    obj->isFirstMoved = false;
    obj->moveAllowedSlots = (List*)malloc(sizeof(List*));
    list_init(obj->moveAllowedSlots);

    slots[x][y]->object = obj;

    if (type == 5) {
        if (team == 0) gameScene->bKing = obj;
        else gameScene->wKing = obj;
    }
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
        Assign(0, 0, i, 1, gameScene);
    Assign(0, 1, 0, 0, gameScene);
    Assign(0, 1, 7, 0, gameScene);
    Assign(0, 2, 1, 0, gameScene);
    Assign(0, 2, 6, 0, gameScene);
    Assign(0, 3, 2, 0, gameScene);
    Assign(0, 3, 5, 0, gameScene);
    Assign(0, 4, 3, 0, gameScene);
    Assign(0, 5,4, 0, gameScene);

    //백
    for (int i = 0; i < 8; i++)
        Assign(1, 0, i, 6, gameScene);
    Assign(1, 1, 0, 7, gameScene);
    Assign(1, 1, 7, 7, gameScene);
    Assign(1, 2, 1, 7, gameScene);
    Assign(1, 2, 6, 7, gameScene);
    Assign(1, 3, 2, 7, gameScene);
    Assign(1, 3, 5, 7, gameScene);
    Assign(1, 4, 3, 7, gameScene);
    Assign(1, 5, 4, 7, gameScene);

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
//void check_obj(Object *a, int objType, int size, int x, int y){//클릭했을 시에 무었을 선택했는지 확인하는 함수
//    int j;
//    switch (objType) {
//        case 1:
//            for (j = 0; j < size; j++) {
//                if (a[j].xPos == x && a[j].yPos == y) {
//                    printf("(%d, %d) 좌표의 %s 선택했습니다.", x, y, a[j].objectType);
//                }else{
//                    printf("Cannot find Object, Reselect");break;
//                }
//            }
//            break;
//        case 2:
//            for (j = 0; j < size; j++) {
//                if (a[j].xPos == x && a[j].yPos == y) {
//                    printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[j].objectType);
//                }
//            }
//            break;
//        case 3:
//            for (j = 0; j < size; j++) {
//                if (a[j].xPos == x && a[j].yPos == y) {
//                    printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[j].objectType);
//                }
//            }
//            break;
//        case 4:
//            for (j = 0; j < size; j++) {
//                if (a[j].xPos == x && a[j].yPos == y) {
//                    printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[j].objectType);
//                }
//            }
//            break;
//        case 5:
//            if (a->xPos == x && a->yPos == y) {
//                printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[i].objectType);
//            }else{
//                printf("Cannot find Object, Reselect");
//            }
//            break;
//        case 6:
//            if (a->xPos == x && a->yPos == y) {
//                printf("(%d, %d) 좌표의 %s을 선택했습니다.", x, y, a[i].objectType);
//            } else {
//                printf("Cannot find Object, Reselect");
//            }
//            break;
//    }
//
//}

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

void move_obj(GameScene* gameScene, Object* object) {
    int j;
    int directionConst = 0;
    if (!gameScene->selectedArray || !gameScene->selectedArray->object) return;
    //Object* object = gameScene->selectedArray->object;
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
}
/*

int is_Check(GameScene gameScene) {
    int j;
    List* checker = (List*)malloc(sizeof(List*));
    Object* checkee;
    list_init(checker);


    if (gameScene.order == 0) 
        checkee = gameScene.bKing;
    else checkee = gameScene.wKing;

    for (int i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            Slot* slot = gameScene.nodeArray[i][j];
            if (slot->object) list_push(checker, slot->object);
        }
    }
    
    Node* currentObject = checker->head;
    if (gameScene.order == 1) {
        while (currentObject) {
            Object* obj = currentObject->val;
            if (obj->objectType == 0) {
                int Check;
                Check = 0;
                if ((obj->xPos + 1 == obj->xPos) &&
                    ((obj->yPos + 1 == obj->yPos) || (obj->yPos - 1 == obj->yPos)))
                    Check++;
                if (Check != 0) {
                    return 1;
                }
            }
            else if (obj->objectType == 1) {
                int check = 0;
                if ((obj->xPos == obj->xPos) || (obj->yPos == obj->yPos)) {
                    check++;
                }
                if (check != 0) {
                    return 1;
                }
            }
            else if (obj->objectType == 2) {
                int Check;
                Check = 0;
                if (((obj->xPos + 2 == obj->xPos) && ((obj->yPos + 1 == obj->yPos) || (obj->yPos - 1)) == obj->yPos)) {
                    Check++;
                }
                else if (((obj->xPos + 1 == obj->xPos) || (obj->xPos - 1 == obj->xPos)) && (obj->yPos + 2 == obj->yPos)) {
                    Check++;
                }
                else if ((obj->xPos - 2 == obj->xPos) && ((obj->yPos + 1 == obj->yPos) || (obj->yPos == obj->yPos))) {
                    Check++;
                }
                else if (((obj->xPos + 1 == obj->xPos) || (obj->xPos - 1 == obj->xPos)) && (obj->yPos - 2 == obj->yPos)) {
                    Check++;
                }
                if (Check != 0) {
                    return 1;
                }
            }
            else if (obj->objectType == 3) {
                int check_Check = 0;
                for (int h = 1; h < 9; h++) {
                    if (((obj->xPos + h == obj->xPos) && (obj->yPos + h == obj->yPos)) || ((obj->xPos - h == obj->xPos) && (obj->yPos - h == obj->yPos))) {
                        check_Check++;
                    }
                }
                if (check_Check != 0) {
                    return 1;
                }

            }
            else if (obj->objectType == 4) {
                int check = 0;
                for (int h = 1; h < 9; h++) {
                    if (((obj->xPos + h == obj->xPos) && (obj->yPos + h == obj->yPos)) || ((obj->xPos - h == obj->xPos) && (obj->yPos - h == obj->yPos))) {
                        check++;
                    }
                }
                if ((obj->xPos == obj->xPos) || (obj->yPos == obj->yPos)) {
                    check++;
                }
                if (check != 0) {
                    return 1;
                }
            }
            else if (obj->objectType == 5) {
                return 0;
            }
            else {
                return -2;//뭔가 잘못되었다는 신호
            }
        }
    }
    
    else{
        while (currentObject) {
            Object* obj = currentObject->val;
            if (obj->objectType == 0) {
                
            }
            else if (obj->objectType == 1) {
                int check = 0;
                if ((obj->xPos == checkee->xPos) || (obj->yPos == checkee->yPos)) {
                    check++;
                }
                if (check != 0) {
                    return 1;
                }
            }
            else if (obj->objectType == 2) {
                int Check;
                Check = 0;
                if (((obj->xPos + 2 == checkee->xPos) &&
                    ((obj->yPos + 1 == checkee->yPos) || (obj->yPos - 1)) == checkee->yPos)) {
                    Check++;
                }
                else if (((obj->xPos + 1 == checkee->xPos) || (obj->xPos - 1 == checkee->xPos)) &&
                    (obj->yPos + 2 == checkee->yPos)) {
                    Check++;
                }
                else if ((obj->xPos - 2 == checkee->xPos) &&
                    ((obj->yPos + 1 == checkee->yPos) || (obj->yPos == checkee->yPos))) {
                    Check++;
                }
                else if (((obj->xPos + 1 == checkee->xPos) || (obj->xPos - 1 == checkee->xPos)) &&
                    (obj->yPos - 2 == checkee->yPos)) {
                    Check++;
                }
                if (Check != 0) {
                    return 1;
                }
            }
            else if (obj->objectType == 3) {
                int check_Check = 0;
                for (int h = 1; h < 9; h++) {
                    if (((obj->xPos + h == checkee->xPos) && (obj->yPos + h == checkee->yPos)) ||
                        ((obj->xPos - h == checkee->xPos) && (obj->yPos - h == checkee->yPos))) {
                        check_Check++;
                    }
                }
                if (check_Check != 0) {
                    return 1;
                }

            }
            else if (obj->objectType == 4) {
                int check = 0;
                if (obj->xPos == checkee->xPos) {
                    if (obj->xPos > checkee->xPos) {
                        for (int q = obj->xPos - 1; q > checkee->xPos; q--) {
                            for (int w = 0; w < 32; w++) {
                                if ((list_search()[q].xPos == Checker[w].xPos) && (q != w)) {
                                    check++;
                                }
                            }
                        }
                    }
                    else if (Checker[j].xPos < Checkee->xPosi) {
                        for (int q = Checker[j].xPos + 1; q < Checkee->xPosi; q++) {
                            for (int w = 0; w < 32; w++) {
                                if ((Checker[q].xPos != Checker[w].xPos) && (q != w)) {
                                    check++;
                                }
                            }
                        }
                    }
                }
                for (int h = 1; h < 9; h++) {
                    if ((Checker[j].xPos + h > 8) || (Checker[j].yPos > 8)) {
                        break;
                    }
                    if ((Checker[j].xPos + h == Checkee->xPosi) && (Checker[j].yPos + h == Checkee->yPosi)) {
                        for (int q = 0; q < 32; q++) {
                            if ((q != j) && (Checker[q].xPos + h != Checker[j].xPos + h) && (Checker[q].yPos + h != Checker[j].yPos + h)) {
                                check++;
                            }
                        }
                    }
                    else if ((Checker[j].xPos - h == Checkee->xPosi) && (Checker[j].yPos - h == Checkee->yPosi)) {
                        for (int q = 0; q < 32; q++) {
                            if ((q != j) && (Checker[q].xPos - h != Checker[j].xPos - h) && (Checker[q].yPos - h != Checker[j].yPos - h)) {
                                check++;
                            }
                        }
                    }
                    else if ((Checker[j].xPos + h == Checkee->xPosi) && Checker[j].yPos - h == Checkee->yPosi) {
                        for (int q = 0; q < 32; q++) {
                            if ((q != j) && (Checker[q].xPos + h != Checker[j].xPos + h) && (Checker[q].yPos - h != Checker[j].yPos - h)) {
                                check++;
                            }
                        }
                    }
                    else if ((Checker[j].xPos - h == Checkee->xPosi) && (Checker[j].yPos + h) == Checkee->yPosi) {
                        for (int q = 0; q < 32; q++) {
                            if ((q != j) && (Checker[q].xPos - h != Checker[j].xPos - h) && (Checker[q].yPos + h != Checker[j].yPos + h)) {
                                check++;
                            }
                        }
                    }
                }
                if (check != 0) {
                    return 1;
                }
            }
            else if (obj->objectType == 5) {
                return 0;
            }
            else {
                return -2;//뭔가 잘못되었다는 신호
            }
 
        }
    }
}
int autoCheck(Object* er, Pos* ee, int Pos) {
    if (Pos == 1) {
        if (is_Check(er, ee) == 1) {
            ee->xPos += 1;
            if (is_Check(er, ee) == 1) {
                ee->yPos += 1;
                if (is_Check(er, ee) == 1) {
                    ee->xPos -= 1;
                    if (is_Check(er, ee) == 1) {
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 2) {
        if (is_Check(er, ee) == 1) {
            ee->xPos -= 1;
            if (is_Check(er, ee) == 1) {
                ee->yPos += 1;
                if (is_Check(er, ee) == 1) {
                    ee->xPos += 1;
                    if (is_Check(er, ee) == 1) {
                        ee->yPos -= 1;
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 3) {
        if (is_Check(er, ee) == 1) {
            ee->xPos -= 1;
            if (is_Check(er, ee) == 1) {
                ee->yPos -= 1;
                if (is_Check(er, ee) == 1) {
                    ee->xPos += 1;
                    if (is_Check(er, ee) == 1) {
                        ee->yPos += 1;
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 4) {
        if (is_Check(er, ee) == 1) {
            ee->xPos += 1;
            if (is_Check(er, ee) == 1) {
                ee->yPos -= 1;
                if (is_Check(er, ee) == 1) {
                    ee->xPos -= 1;
                    if (is_Check(er, ee) == 1) {
                        ee->yPos += 1;
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 5) {
        if (is_Check(er, ee) == 1) {
            ee->yPos += 1;
            if (is_Check(er, ee) == 1) {
                ee->xPos += 1;
                if (is_Check(er, ee) == 1) {
                    ee->yPos -= 1;
                    if (is_Check(er, ee) == 1) {
                        ee->yPos -= 1;
                        if (is_Check(er, ee) == 1) {
                            ee->xPos -= 1;
                            if (is_Check(er, ee) == 1) {
                                ee->yPos += 1;
                                return 1;
                            }
                            else {
                                return 0;
                            }
                        }
                        else {
                            return 0;
                        }
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 6) {
        if (is_Check(er, ee) == 1) {
            ee->xPos += 1;
            if (is_Check(er, ee) == 1) {
                ee->yPos += 1;
                if (is_Check(er, ee) == 1) {
                    ee->xPos -= 1;
                    if (is_Check(er, ee) == 1) {
                        ee->xPos -= 1;
                        if (is_Check(er, ee) == 1) {
                            ee->yPos -= 1;
                            if (is_Check(er, ee) == 1) {
                                ee->xPos += 1;
                                return 1;
                            }
                            else {
                                return 0;
                            }
                        }
                        else {
                            return 0;
                        }
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 7) {
        if (is_Check(er, ee) == 1) {
            ee->yPos += 1;
            if (is_Check(er, ee) == 1) {
                ee->xPos += 1;
                if (is_Check(er, ee) == 1) {
                    ee->yPos -= 1;
                    if (is_Check(er, ee) == 1) {
                        ee->yPos -= 1;
                        if (is_Check(er, ee) == 1) {
                            ee->xPos -= 1;
                            if (is_Check(er, ee) == 1) {
                                ee->yPos += 1;
                                return 1;
                            }
                            else {
                                return 0;
                            }
                        }
                        else {
                            return 0;
                        }
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 8) {
        if (is_Check(er, ee) == 1) {
            ee->xPos += 1;
            if (is_Check(er, ee) == 1) {
                ee->yPos -= 1;
                if (is_Check(er, ee) == 1) {
                    ee->xPos -= 1;
                    if (is_Check(er, ee) == 1) {
                        ee->xPos -= 1;
                        if (is_Check(er, ee) == 1) {
                            ee->yPos += 1;
                            if (is_Check(er, ee) == 1) {
                                ee->xPos += 1;
                                return 1;
                            }
                            else {
                                return 0;
                            }
                        }
                        else {
                            return 0;
                        }
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (Pos == 9) {
        if (is_Check(er, ee) == 1) {
            ee->yPos += 1;
            if (is_Check(er, ee) == 1) {
                ee->xPos += 1;
                if (is_Check(er, ee) == 1) {
                    ee->yPos -= 1;
                    if (is_Check(er, ee) == 1) {
                        ee->yPos -= 1;
                        if (is_Check(er, ee) == 1) {
                            ee->xPos -= 1;
                            if (is_Check(er, ee) == 1) {
                                ee->xPos -= 1;
                                if (is_Check(er, ee) == 1) {
                                    ee->yPos += 1;
                                    if (is_Check(er, ee) == 1) {
                                        ee->yPos += 1;
                                        if (is_Check(er, ee) == 1) {
                                            ee->xPos += 1;
                                            ee->yPos -= 1;
                                            return 1;
                                        }
                                        else {
                                            return 0;
                                        }
                                    }
                                    else {
                                        return 0;
                                    }
                                }
                                else {
                                    return 0;
                                }
                            }
                            else {
                                return 0;
                            }
                        }
                        else {
                            return 0;
                        }
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
}
int is_CheckMate(Object* checker, const char* team) {
    Pos* King;
    if (strcmp(team, "white") == 0) {
        for (int k = 1; k < 17; k++) {
            if (checker[k].ownNum == 16) {
                King->xPos = checker[k].xPos;
                King->yPos = checker[k].yPos;
                strcpy(King->team, checker[k].team);
            }
        }
    }
    else if (strcmp(team, "black") == 0) {
        for (int k = 17; k < 33; k++) {
            if (checker[k].ownNum == 32) {
                King->xPos = checker[k].xPos;
                King->yPos = checker[k].yPos;
                strcpy(King->team, checker[k].team);
            }
        }
    }

    if (King->yPos == 1) {
        if (King->xPos == 1) {
            if (autoCheck(checker, King, 1) == 1) {
                return 1;
            }
        }
        else if (King->xPos == 8) {
            if (autoCheck(checker, King, 2) == 1) {
                return 1;
            }
        }
        else {
            if (autoCheck(checker, King, 6)) {
                return 1;
            }
        }
    }
    else if (King->xPos == 8) {
        if (King->yPos == 1) {
            if (autoCheck(checker, King, 2) == 1) {
                return 1;
            }
        }
        else if (King->yPos == 8) {
            if (autoCheck(checker, King, 3) == 1) {
                return 1;
            }
        }
        else {
            if (autoCheck(checker, King, 7) == 1) {
                return 1;
            }
        }
    }
    else if (King->yPos == 8) {
        if (King->xPos == 1) {
            if (autoCheck(checker, King, 4) == 1) {
                return 1;
            }
        }
        else if (King->xPos == 8) {
            if (autoCheck(checker, King, 3) == 1) {
                return 1;
            }
        }
        else {
            if (autoCheck(checker, King, 8) == 1) {
                return 1;
            }
        }
    }
    else if (King->xPos == 1) {
        if (King->yPos == 1) {
            if (autoCheck(checker, King, 1) == 1) {
                return 1;
            }
        }
        else if (King->yPos == 8) {
            if (autoCheck(checker, King, 4) == 1) {
                return 1;
            }
        }
        else {
            if (autoCheck(checker, King, 5) == 1) {
                return 1;
            }
        }
    }
    else {
        if (autoCheck(checker, King, 9) != 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

        }//얘 호출하면 체크메이트 판정까지 알아서 해 줌 */