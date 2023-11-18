#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Object {
    char team[6];
    int isDead;
    char objectType[10];
    int xPos;
    int yPos;
    int ownNum;
} Object;
typedef struct Position{
    int xPosi;
    int yPosi;
    char team[6];
    int ownNumber;
}Pos;
int i;
int obj_check_die(Object *checkee, Pos *checker){
    int j;
    if(checker->team == "white"){
        for(j=0; j<16; j++){
            if(checkee[j].team == "black"){
                if(checkee[j].xPos == checker->xPosi&&checkee[j].yPos == checker->yPosi){
                    checkee[j].isDead = 1;
                    return 0;
                }
            }else{
                return -1;
            }

        }
    }else if(checker->team == "black"){
        for(j=0; j<16; j++){
            if(checkee[j].team == "white"){
                if(checkee[j].xPos == checker->xPosi&&checkee[j].yPos == checker->yPosi){
                    checkee[j].isDead = 1;
                    return 0;
                }
            }else{
                return -1;
            }
        }
    }else{
        return -1;
    }
}//기물이 죽는지 확인하는 함수
int Promotion(Object *Origin, Pos *position, int select){
    if(position->team == "white") {
        if (Origin->objectType == "Pawn") {
            if (position->xPosi == 8) {
                switch (select) {
                    case 1:
                        strcpy(Origin->objectType, "Rook");
                        break;
                    case 2:
                        strcpy(Origin->objectType, "Knight");
                        break;
                    case 3:
                        strcpy(Origin->objectType, "Bishop");
                        break;
                    case 4:
                        strcpy(Origin->objectType, "Queen");
                        break;
                }
            }
            else{
                return 0;
            }
        }else{
            return 0;
        }
    }else if(position->team == "black"){
        if (Origin->objectType == "Pawn") {
            if (position->xPosi == 8) {
                switch (select) {
                    case 1:
                        strcpy(Origin->objectType, "Rook");
                        break;
                    case 2:
                        strcpy(Origin->objectType, "Knight");
                        break;
                    case 3:
                        strcpy(Origin->objectType, "Bishop");
                        break;
                    case 4:
                        strcpy(Origin->objectType, "Queen");
                        break;
                }
            }
            else{
                return 0;
            }
        }else{
            return 0;
        }
    }
}//프로모션하는 함수로, select 매개변수로 변경할 수 있다.
void assignMent(Object* objects, const char* team, int objType, int size) {//기물 선언용 함수
    for (i = 0; i < size; i++) {
        strncpy(objects[i].team, team, sizeof(objects[i].team));
        objects[i].team[sizeof(objects[i].team) - 1] = '\0';
        objects[i].isDead = 0;

        if (strcmp(objects[i].team, "white") == 0) {
            switch (objType) {
                case 1: strcpy(objects[i].objectType, "Pawn"); objects[i].xPos = 2; break;
                case 2: strcpy(objects[i].objectType, "Rook"); objects[i].xPos = 1; break;
                case 3: strcpy(objects[i].objectType, "Knight"); objects[i].xPos = 1; break;
                case 4: strcpy(objects[i].objectType, "Bishop"); objects[i].xPos = 1; break;
                case 5: strcpy(objects[i].objectType, "Queen"); objects[i].xPos = 1; break;
                case 6: strcpy(objects[i].objectType, "King"); objects[i].xPos = 1; break;
                default: break;
            }
        } else {
            switch (objType) {
                case 1: strcpy(objects[i].objectType, "Pawn"); objects[i].xPos = 7; break;
                case 2: strcpy(objects[i].objectType, "Rook"); objects[i].xPos = 8; break;
                case 3: strcpy(objects[i].objectType, "Knight"); objects[i].xPos = 8; break;
                case 4: strcpy(objects[i].objectType, "Bishop"); objects[i].xPos = 8; break;
                case 5: strcpy(objects[i].objectType, "Queen"); objects[i].xPos = 8; break;
                case 6: strcpy(objects[i].objectType, "King"); objects[i].xPos = 8; break;
                default: break;
            }
        }

        if (strcmp(objects[i].team, "white") == 0) {
            switch (objType) {
                case 1: objects[i].yPos = i + 1; break;
                case 2: objects[i].yPos = (i == 0) ? 1 : 8; break;
                case 3: objects[i].yPos = (i == 0) ? 2 : 7; break;
                case 4: objects[i].yPos = (i == 0) ? 3 : 6; break;
                case 5: objects[i].yPos = 5; break;
                case 6: objects[i].yPos = 4; break;
                default: break;
            }
        } else {
            switch (objType) {
                case 1: objects[i].yPos = i + 1; break;
                case 2: objects[i].yPos = (i == 0) ? 1 : 8; break;
                case 3: objects[i].yPos = (i == 0) ? 2 : 7; break;
                case 4: objects[i].yPos = (i == 0) ? 3 : 6; break;
                case 5: objects[i].yPos = 4; break;
                case 6: objects[i].yPos = 5; break;
                default: break;
            }
        }
    }

}//선언하는 함수, 위치까지 다 지정해 줌
void ownNum(Object *a){
    if(a->team == "white"){
        for(i=0; i<16; i++){
            a[i].ownNum =i+1;
        }
    }else{
        for(i=0; i<16; i++){
            a[i].ownNum =i+17;
        }
    }

}
struct Position check_obj(Object *a, int objType, int size, int x, int y){//클릭했을 시에 무었을 선택했는지 확인하는 함수
    int j;
    struct Position p;
    switch (objType) {
        case 1:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    p.xPosi = a[j].xPos;
                    p.yPosi = a[j].yPos;
                    strcpy(p.team, a[j].team);
                    p.ownNumber = a[j].ownNum;
                    return p;
                }else{
                    printf("Cannot find Object, Reselect");break;
                }
            }
            break;
        case 2:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    p.xPosi = a[j].xPos;
                    p.yPosi = a[j].yPos;
                    strcpy(p.team, a[j].team);
                    p.ownNumber = a[j].ownNum;
                    return p;
                }else{
                    printf("Cannot find Object, Reselect");break;
                }
            }
            break;
        case 3:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    p.xPosi = a[j].xPos;
                    p.yPosi = a[j].yPos;
                    strcpy(p.team, a[j].team);
                    p.ownNumber = a[j].ownNum;
                    return p;
                }else{
                    printf("Cannot find Object, Reselect");break;
                }
            }
            break;
        case 4:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    p.xPosi = a[j].xPos;
                    p.yPosi = a[j].yPos;
                    strcpy(p.team, a[j].team);
                    p.ownNumber = a[j].ownNum;
                    return p;
                }else{
                    printf("Cannot find Object, Reselect");break;
                }
            }
            break;
        case 5:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    p.xPosi = a[j].xPos;
                    p.yPosi = a[j].yPos;
                    strcpy(p.team, a[j].team);
                    p.ownNumber = a[j].ownNum;
                    return p;
                }else{
                    printf("Cannot find Object, Reselect");break;
                }
            }
            break;
        case 6:
            for (j = 0; j < size; j++) {
                if (a[j].xPos == x && a[j].yPos == y) {
                    p.xPosi = a[j].xPos;
                    p.yPosi = a[j].yPos;
                    strcpy(p.team, a[j].team);
                    p.ownNumber = a[j].ownNum;
                    return p;
                }else{
                    printf("Cannot find Object, Reselect");break;
                }
            }
            break;
    }

}//b안의 정보가 선택한 기물의 정보임
int Pawn_diag(Object *a, Pos *b, int size){
    int j;
    for(j=0; j<size; j++){
        if(b->team == "white"){
            if(a[j].team == "black"){
                if(b->xPosi+1 == a[j].xPos&&b->yPosi+1 == a[j].yPos){
                    b->ownNumber = a[j].ownNum;
                    return 2;
                }else if(b->xPosi+1 == a[j].xPos&&b->yPosi-1 == a[j].yPos){
                    b->ownNumber = a[j].ownNum;
                    return 1;
                }else if(b->xPosi+1 == a[j].xPos&&b->yPosi == a[j].yPos){
                    b->ownNumber = a[j].ownNum;
                    return 0;
                }else{
                    return -2;
                }
            }else{
                return -2;
            }
        }else if(b->team == "black"){
            if(a[j].team == "white"){
                if(b->xPosi-1 == a[j].xPos&&b->yPosi+1 == a[j].yPos){
                    return 2;
                }else if(b->xPosi-1 == a[j].xPos&&b->yPosi-1 == a[j].yPos){
                    return 1;
                }else if(b->xPosi -1 == a[j].xPos&&b->yPosi == a[j].yPos){
                    return 0;
                }
                else{
                    return -2;
                }
            }else{
                return -2;
            }
        }else{
            return -2;
        }
    }

}//폰이 대각선으로 움직일 수 있는지 확인하는 함수
void move_obj(Object *a, Pos *b,int objType, int size, int x, int y) {
    int j;
    if (a->team == "white") {
        switch (objType) {
            case 1:
                for (j = 0; j < size; j++) {
                    if (Pawn_diag(a, b, size) == 2) {
                        if (x == b->xPosi + 1 && y == b->yPosi + 1) {
                            b->xPosi += 1;
                            b->yPosi += 1;
                        }

                    } else if (Pawn_diag(a, b, size) == 1) {
                        if (x == b->xPosi + 1 && y == b->yPosi - 1) {
                            b->xPosi += 1;
                            b->yPosi -= 1;
                        }
                    } else if (Pawn_diag(a, b, size) == 0) {
                        if (b->xPosi == 2) {
                            if (x == b->xPosi + 2 && y == b->yPosi) {
                                b->xPosi += 2;
                            } else if (x == b->xPosi + 1 && y == b->yPosi) {
                                b->xPosi += 1;
                            }
                        } else {
                            if (x == b->xPosi + 1 && y == b->yPosi) {
                                b->xPosi += 1;
                            }
                        }
                    }
                    Promotion(a, b, 1);
                }
                break;

            case 2:
                for (j = 0; j < size; j++) {
                    if ((x == b->xPosi + j && y == b->yPosi) || (x == b->xPosi - j && b->yPosi)) {
                        b->xPosi = x;
                    } else if ((x == b->xPosi && y == b->yPosi + j) || x == b->xPosi && b->yPosi - j) {
                        b->yPosi = y;
                    }
                }
                break;
            case 3:
                for (j = 0; j < size; j++) {
                    if ((x == b->xPosi + 2 && (y == b->yPosi + 1) || y == b->yPosi - 1)) {
                        b->xPosi = x;
                        b->yPosi = y;
                    } else if ((x == b->xPosi + 1) || (x == b->yPosi - 1) && y == b->yPosi + 2) {
                        b->xPosi = x;
                        b->yPosi = y;
                    } else if (x == b->xPosi - 2 && (y == b->yPosi + 1) || (y == b->yPosi - 1)) {
                        b->xPosi = x;
                        b->yPosi = y;
                    } else if ((x == b->xPosi + 1) || (x == b->xPosi - 1) && y == b->yPosi - 2) {
                        b->xPosi = x;
                        b->yPosi = y;
                    }
                }

                break;
            case 4:
                for (j = 0; j < size; j++) {
                    if ((x == b->xPosi + j && y == b->yPosi + j) || (x == b->xPosi - j && y == b->yPosi - j) ||
                        (x == b->xPosi - j && y == b->yPosi + j) || (x == b->xPosi + j && y == b->yPosi - j)) {
                        b->xPosi = x;
                        b->yPosi = y;
                    }
                }
                break;
            case 5:
                for (j = 0; j < size; j++) {
                    if ((x == b->xPosi + j && y == b->yPosi) || (x == b->xPosi - j && b->yPosi)) {
                        b->xPosi = x;
                    } else if ((x == b->xPosi && y == b->yPosi + j) || x == b->xPosi && b->yPosi - j) {
                        b->yPosi = y;
                    } else if ((x == b->xPosi + j && y == b->yPosi + j) || (x == b->xPosi - j && y == b->yPosi - j) ||
                               (x == b->xPosi - j && y == b->yPosi + j) || (x == b->xPosi + j && y == b->yPosi - j)) {
                        b->xPosi = x;
                        b->yPosi = y;
                    }
                }
                break;
            case 6:
                for (j = 0; j < size; j++) {
                    if ((x == b->xPosi + 1 && y == b->yPosi) || (x == b->xPosi - 1 && b->yPosi)) {
                        b->xPosi = x;
                    } else if ((x == b->xPosi && y == b->yPosi + 1) || x == b->xPosi && b->yPosi - 1) {
                        b->yPosi = y;
                    } else if ((x == b->xPosi + 1 && y == b->yPosi + 1) || (x == b->xPosi - 1 && y == b->yPosi - 1) ||
                               (x == b->xPosi - 1 && y == b->yPosi + 1) || (x == b->xPosi + 1 && y == b->yPosi - 1)) {
                        b->xPosi = x;
                        b->yPosi = y;
                    }
                }
                break;
            default:
                break;
        }
    } else {
        switch (objType) {
            case 1:
                for (j = 0; j < size; j++) {
                    if (Pawn_diag(a, b, size) == 2) {
                        b->xPosi -= 1;
                        b->yPosi += 1;
                    } else if (Pawn_diag(a, b, size) == 1) {
                        b->xPosi -= 1;
                        b->yPosi += 1;
                    } else if (Pawn_diag(a, b, size) == 0) {
                        if (b->xPosi == 7) {
                            b->xPosi -= 2;
                        } else {
                            b->xPosi -= 1;
                        }

                    } else {
                        if (x == b->xPosi - 1 && y == b->yPosi) {
                            b->xPosi -= 1;
                        }

                    }
                    Promotion(a, b, 1);
                }break;
                case 2:
                    for (j = 0; j < size; j++) {
                        if ((x == b->xPosi - j && y == b->yPosi) || (x == b->xPosi + j && b->yPosi)) {
                            b->xPosi = x;
                        } else if ((x == b->xPosi && y == b->yPosi + j) || x == b->xPosi && b->yPosi - j) {
                            b->yPosi = y;
                        }
                    }
                    break;
                case 3:
                    for (j = 0; j < size; j++) {
                        if ((x == b->xPosi + 2 && (y == b->yPosi + 1) || y == b->yPosi - 1)) {
                            b->xPosi = x;
                            b->yPosi = y;
                        } else if ((x == b->xPosi + 1) || (x == b->yPosi - 1) && y == b->yPosi + 2) {
                            b->xPosi = x;
                            b->yPosi = y;
                        } else if (x == b->xPosi - 2 && (y == b->yPosi + 1) || (y == b->yPosi - 1)) {
                            b->xPosi = x;
                            b->yPosi = y;
                        } else if ((x == b->xPosi + 1) || (x == b->xPosi - 1) && y == b->yPosi - 2) {
                            b->xPosi = x;
                            b->yPosi = y;
                        }
                    }

                    break;
                case 4:
                    for (j = 0; j < size; j++) {
                        if ((x == b->xPosi + j && y == b->yPosi + j) || (x == b->xPosi - j && y == b->yPosi - j) ||
                            (x == b->xPosi - j && y == b->yPosi + j) || (x == b->xPosi + j && y == b->yPosi - j)) {
                            b->xPosi = x;
                            b->yPosi = y;
                        }
                    }
                    break;
                case 5:
                    for (j = 0; j < size; j++) {
                        if ((x == b->xPosi + j && y == b->yPosi) || (x == b->xPosi - j && b->yPosi)) {
                            b->xPosi = x;
                        } else if ((x == b->xPosi && y == b->yPosi + j) || x == b->xPosi && b->yPosi - j) {
                            b->yPosi = y;
                        } else if ((x == b->xPosi + j && y == b->yPosi + j) || (x == b->xPosi - j && y == b->yPosi - j) ||
                                   (x == b->xPosi - j && y == b->yPosi + j) || (x == b->xPosi + j && y == b->yPosi - j)) {
                            b->xPosi = x;
                            b->yPosi = y;
                        }
                    }
                    break;
                case 6:
                    for (j = 0; j < size; j++) {
                        if ((x == b->xPosi + 1 && y == b->yPosi) || (x == b->xPosi - 1 && b->yPosi)) {
                            b->xPosi = x;
                        } else if ((x == b->xPosi && y == b->yPosi + 1) || x == b->xPosi && b->yPosi - 1) {
                            b->yPosi = y;
                        } else if ((x == b->xPosi + 1 && y == b->yPosi + 1) || (x == b->xPosi - 1 && y == b->yPosi - 1) ||
                                   (x == b->xPosi - 1 && y == b->yPosi + 1) || (x == b->xPosi + 1 && y == b->yPosi - 1)) {
                            b->xPosi = x;
                            b->yPosi = y;
                        }
                    }
                    break;
                default:
                    break;
        }
    }
}
int is_Check(Object *Checker, Pos *Checkee){
    int j;
    if(Checkee->team == "white"){
        for(j=17; j<33;j++){
            if(Checker[j].objectType == "Pawn"){
                int Check;
                Check = 0;
                if ((Checker[j].xPos + 1 == Checkee->xPosi) &&
                    ((Checker[j].yPos + 1 == Checkee->yPosi) || (Checker[j].yPos - 1 == Checkee->yPosi)))
                    Check++;
                if(Check != 0){
                    return 1;
                }
            }else if(Checker[j].objectType == "Rook"){
                int check = 0;
                if((Checker[j].xPos == Checkee->xPosi)||(Checker[j].yPos == Checkee->yPosi)){
                    check++;
                }
                if(check != 0){
                    return 1;
                }
            }else if(Checker[j].objectType == "Knight"){
                int Check;
                Check = 0;
                if(((Checker[j].xPos+2 == Checkee->xPosi)&&((Checker[j].yPos+1 == Checkee->yPosi)||(Checker[j].yPos-1)) == Checkee->yPosi)){
                    Check++;
                }else if(((Checker[j].xPos+1 == Checkee->xPosi)||(Checker[j].xPos-1 == Checkee->xPosi))&&(Checker[j].yPos+2 == Checkee->yPosi)){
                    Check++;
                }else if((Checker[j].xPos-2 == Checkee->xPosi)&&((Checker[j].yPos +1 == Checkee->yPosi)||(Checker[j].yPos == Checkee->yPosi))){
                    Check++;
                }else if(((Checker[j].xPos+1 == Checkee->xPosi)||(Checker[j].xPos-1 == Checkee->xPosi))&&(Checker[j].yPos-2 == Checkee->yPosi)){
                    Check++;
                }
                if(Check != 0){
                    return 1;
                }
            }else if(Checker[j].objectType == "Bishop"){
                int check_Check = 0;
                for(int h = 1;h<9; h++){
                    if(((Checker[j].xPos+h == Checkee->xPosi)&&(Checker[j].yPos+h == Checkee->yPosi))||((Checker[j].xPos-h == Checkee->xPosi)&&(Checker[j].yPos-h == Checkee->yPosi))){
                        check_Check++;
                    }
                }
                if(check_Check != 0){
                    return 1;
                }

            }else if(Checker[j].objectType == "Queen"){
                int check = 0;
                for(int h = 1; h < 9; h++){
                    if(((Checker[j].xPos+h == Checkee->xPosi)&&(Checker[j].yPos+h == Checkee->yPosi))||((Checker[j].xPos-h == Checkee->xPosi)&&(Checker[j].yPos-h == Checkee->yPosi))){
                        check++;
                    }
                }
                if((Checker[j].xPos == Checkee->xPosi)||(Checker[j].yPos == Checkee->yPosi)){
                    check++;
                }
                if(check != 0){
                    return 1;
                }
            }else if(Checker[j].objectType == "King"){
                return 0;
            }else{
                return -2;//뭔가 잘못되었다는 신호
            }
        }

    }else if(Checkee->team == "black") {
        for (j = 1; j < 17; j++) {
            if (Checker[j].objectType == "Pawn") {
                int Check;
                Check = 0;
                if ((Checker[j].xPos - 1 == Checkee->xPosi) &&
                    ((Checker[j].yPos - 1 == Checkee->yPosi) || (Checker[j].yPos + 1 == Checkee->yPosi)))
                    Check++;
                if (Check != 0) {
                    return 1;
                }
            } else if (Checker[j].objectType == "Rook") {
                int check = 0;
                if ((Checker[j].xPos == Checkee->xPosi) || (Checker[j].yPos == Checkee->yPosi)) {
                    check++;
                }
                if (check != 0) {
                    return 1;
                }
            } else if (Checker[j].objectType == "Knight") {
                int Check;
                Check = 0;
                if (((Checker[j].xPos + 2 == Checkee->xPosi) &&
                     ((Checker[j].yPos + 1 == Checkee->yPosi) || (Checker[j].yPos - 1)) == Checkee->yPosi)) {
                    Check++;
                } else if (((Checker[j].xPos + 1 == Checkee->xPosi) || (Checker[j].xPos - 1 == Checkee->xPosi)) &&
                           (Checker[j].yPos + 2 == Checkee->yPosi)) {
                    Check++;
                } else if ((Checker[j].xPos - 2 == Checkee->xPosi) &&
                           ((Checker[j].yPos + 1 == Checkee->yPosi) || (Checker[j].yPos == Checkee->yPosi))) {
                    Check++;
                } else if (((Checker[j].xPos + 1 == Checkee->xPosi) || (Checker[j].xPos - 1 == Checkee->xPosi)) &&
                           (Checker[j].yPos - 2 == Checkee->yPosi)) {
                    Check++;
                }
                if (Check != 0) {
                    return 1;
                }
            } else if (Checker[j].objectType == "Bishop") {
                int check_Check = 0;
                for (int h = 1; h < 9; h++) {
                    if (((Checker[j].xPos + h == Checkee->xPosi) && (Checker[j].yPos + h == Checkee->yPosi)) ||
                        ((Checker[j].xPos - h == Checkee->xPosi) && (Checker[j].yPos - h == Checkee->yPosi))) {
                        check_Check++;
                    }
                }
                if (check_Check != 0) {
                    return 1;
                }

            } else if (Checker[j].objectType == "Queen") {
                int check = 0;
                for (int h = 1; h < 9; h++) {
                    if (((Checker[j].xPos + h == Checkee->xPosi) && (Checker[j].yPos + h == Checkee->yPosi)) ||
                        ((Checker[j].xPos - h == Checkee->xPosi) && (Checker[j].yPos - h == Checkee->yPosi))) {
                        check++;
                    }
                }
                if ((Checker[j].xPos == Checkee->xPosi) || (Checker[j].yPos == Checkee->yPosi)) {
                    check++;
                }
                if (check != 0) {
                    return 1;
                }
            } else if (Checker[j].objectType == "King") {
                return 0;
            } else {
                return -2;//뭔가 잘못되었다는 신호
            }
        }
    }
}
int main() {
    Object *whitePieces, *blackPieces;
    whitePieces = (Object*)malloc(16 * sizeof(Object));
    blackPieces = (Object*)malloc(16 * sizeof(Object));

    if (whitePieces == NULL || blackPieces == NULL) {
        printf("메모리 할당 오류!\n");
        return 1;
    }

    assignMent(whitePieces, "white", 1, 8);
    assignMent(blackPieces, "black", 1, 8);
    assignMent(whitePieces + 8, "white", 2, 2);
    assignMent(blackPieces + 8, "black", 2, 2);
    assignMent(whitePieces + 10, "white", 3, 2);
    assignMent(blackPieces + 10, "black", 3, 2);
    assignMent(whitePieces + 12, "white", 4, 2);
    assignMent(blackPieces + 12, "black", 4, 2);
    assignMent(whitePieces + 14, "white", 5, 1);
    assignMent(blackPieces + 14, "black", 5, 1);
    assignMent(whitePieces + 15, "white", 6, 1);
    assignMent(blackPieces + 15, "black", 6, 1);
    ownNum(whitePieces);
    ownNum(blackPieces);
    // 출력 예시
    for (i = 0; i < 16; i++) {
        printf("%s %d %s %d %d %d\n", whitePieces[i].team, whitePieces[i].isDead,
               whitePieces[i].objectType, whitePieces[i].xPos, whitePieces[i].yPos,
               whitePieces[i].ownNum);
    }
    check_obj(whitePieces,1, 8, 1, 1);
    free(whitePieces);
    free(blackPieces);
    return 0;
}