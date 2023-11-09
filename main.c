#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int i;
void assignMent(Object* objects, const char* team, int objType, int size) {//기물 선언용 함수
    for (i = 0; i < size; i++) {
        strncpy(objects[i].team, team, sizeof(objects[i].team));
        objects[i].team[sizeof(objects[i].team) - 1] = '\0';
        objects[i].isDead = 0;
        objects[i].isPromoted = 0;

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
                case 5: objects[i].yPos = 4; break;
                case 6: objects[i].yPos = 5; break;
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

        objects[i].isMovement = 0;
        objects[i].PromotedObject[0] = '\0';
    }
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

    // 출력 예시
    for (i = 0; i < 16; i++) {
        printf("%s %d %d %s %d %d %d %s\n", whitePieces[i].team, whitePieces[i].isDead, whitePieces[i].isPromoted,
               whitePieces[i].objectType, whitePieces[i].xPos, whitePieces[i].yPos, whitePieces[i].isMovement,
               whitePieces[i].PromotedObject);
    }
    check_obj(whitePieces,1, 8, 1, 1);
    free(whitePieces);
    free(blackPieces);
    return 0;
}
