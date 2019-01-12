#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>
#include <string.h>

#define BINGO (25)
#define MAX_NUMBER (50)

static int HUMAN    = 0;
static int COMPUTER = 1;

typedef struct player{

    char name[30];
    int playerStatus;
    int bingo[BINGO];
    int bingo_check[BINGO];
    int line;

} Player;

int call_number(Player* player, int arr[]);
int is_already_called(int number, const int arr[]);
void set_number_serial(int arr[], int number);
void draw_circle(Player* player, int number);
void set_bingo_line(Player* player);
int check_vertical_bingo(const Player* player, int idx);
int check_horizontal_bingo(const Player* player, int idx);
int check_diagonal_bingo_left_top_to_right_bottom(const Player* player, int idx);
int check_diagonal_bingo_right_top_to_left_bottom(const Player* player, int idx);
int is_number_correct(Player player, int count, int number);
int is_in_boundary(int number, int start, int end);
void init(Player* player);
void show_bingo(const Player* player);

int number_serial[MAX_NUMBER] = {0};
int game_status = 1;

int main() {

    Player user      = {"user",         HUMAN,    {0}, {0}, 0};
    Player computer1 = {"computer1",    COMPUTER, {0}, {0}, 0};
    Player computer2 = {"computer2",    COMPUTER, {0}, {0}, 0};
    Player computer3 = {"computer3",    COMPUTER, {0}, {0}, 0};


    Player playerList[3] = {computer1, computer2, user};

    int player_num = sizeof(playerList) / sizeof(Player);

    for(int i = 0 ; i < player_num ; i++){
        init(&playerList[i]);
        sleep(1);
    }
    printf("빙고판 기입이 완료되었습니다. 게임을 곧 시작합니다.\n");
    printf("--------------------------------------\n");

    while(game_status)
    {
        int number;
        char input[30];
        game_status++;
        number = call_number(&playerList[(game_status - 2) % player_num], number_serial);

        for(int a = 0 ; a < player_num ; a++)
        {
            printf("빙고 체크 중입니다...\n");
            draw_circle(&playerList[a], number);
        }

        for(int b = 0 ; b < player_num ; b++)
        {
            printf("빙고 줄 체크 중입니다...\n");
            set_bingo_line(&playerList[b]);
        }

        do
        {
            printf("빙고판을 보고 싶다면 'screen'을 입력해주세요.\n");
            printf("현재까지 불린 숫자들을 보고 싶다면 'serial'을 입력해주세요.\n");
            printf("게임을 포기하려면 'escape'를 입력해주세요.\n");
            printf("각 플레이어의 빙고 상황을 알고 싶다면 'bingo'를 입력해주세요.\n");
            printf("다른 키를 입력하면 게임은 계속 진행됩니다.\n");
            scanf("%s", input);

            if(!strcasecmp("screen",input))
            {
                printf("빙고판의 상황입니다.\n");
                for(int scr = 0 ; scr < player_num ; scr++)
                {
                    show_bingo(&playerList[scr]);
                }
            }
            else if(!strcasecmp("serial", input))
            {
                printf("현재까지 불린 숫자들의 상황입니다.\n");
                for(int ser = 0 ; ser < MAX_NUMBER && number_serial[ser] != 0 ; ser++)
                {
                    printf("%3d", number_serial[ser]);
                }
                printf("\n");
            }
            else if(!strcasecmp("escape", input))
            {
                printf("게임 종료 명령을 눌렀습니다.\n");
                game_status = 0;
            }
            else if(!strcasecmp("bingo", input))
            {
                for(int bin = 0 ; bin < player_num ; bin++)
                {
                    printf("%s의 현재 빙고 수: %d줄 \n", playerList[bin].name, playerList[bin].line);
                }
            }
            else
                break;

        } while(1);

        printf("게임을 계속 진행합니다.\n");

        for(int c = 0 ; c < player_num ; c++)
        {
            if(playerList[c].line >= 3)
            {
                game_status = 0;
                break;
            }
        }
    }

    printf("게임이 끝났습니다.\n");
    for(int e = 0 ; e < player_num ; e++)
    {
        show_bingo(&playerList[e]);
        printf("%s의 빙고 수: %d줄\n", playerList[e].name, playerList[e].line);
    }

    return 0;
}
void init(Player* player)
{
    int count = 0;
    int number;
    srand(time(NULL));

    if(player->playerStatus)
    {
        printf("%s 입니다. 숫자를 자동으로 입력합니다.\n", player->name);
    }
    else
        printf("%s 입니다. 숫자를 수동으로 입력합니다.\n", player->name);

    while(count < BINGO)
    {
        if(player->playerStatus)
        {
            number = rand() % MAX_NUMBER + 1;
            if(is_number_correct(*player, count, number))
            {
                player->bingo[count] = number;
                count++;
            }
        }
        else
        {
            printf("%d행 %d열에 숫자를 입력하세요!\n", count / 5 + 1, count % 5 + 1);
            scanf("%d", &number);
            if(is_number_correct(*player, count, number))
            {
                player->bingo[count] = number;
                count++;
            }
            else    printf("잘못된 숫자를 입력했습니다. 다시 입력해 주세요.\n");
        }
    }
}
int is_number_correct(Player player, int count, int number)
{

    int index = 0;
    if(count == 0)  return is_in_boundary(number, 0, MAX_NUMBER);
    if(!is_in_boundary(number, 0, MAX_NUMBER))  return 0;
    while(index <= count)
    {
        if(player.bingo[index] == number)   return 0;
        else    index++;
    }
    return 1;
}
int is_in_boundary(int number, int start, int end)
{
    int status;
    status = (number <= start || number > end) ? 0 : 1;
    return status;
}
int call_number(Player* player, int arr[])
{

    int number;
    srand(time(NULL));

    if(player->playerStatus)
    {
        printf("%s가 숫자를 부릅니다.\n", player->name);
        do
        {
            number = player->bingo[rand() % BINGO];
        } while(is_already_called(number, number_serial));

        printf("%s는 숫자 %d를 불렀습니다.\n", player->name, number);
        set_number_serial(arr, number);

    }
    else
    {
        printf("%s가 숫자를 부릅니다.\n", player->name);
        do
        {
            printf("올바른 숫자를 부르세요!\n");
            scanf("%d", &number);

        } while(is_already_called(number, number_serial) || !is_in_boundary(number, 0, MAX_NUMBER));

        printf("%s는 숫자 %d를 불렀습니다.\n", player->name, number);
        set_number_serial(arr, number);
    }

    return number;
}
int is_already_called(int number, const int arr[])
{

    int i;
    for(i = 0 ; arr[i] != 0 ; i++)
    {
        if(arr[i] == number)    return 1;
    }
    return 0;
}
void set_number_serial(int arr[], int number)
{
    int i;
    for(i = 0 ; arr[i] != 0 ; i++){

    }
    if(is_in_boundary(number, 0, MAX_NUMBER))    arr[i] = number;
}
void draw_circle(Player* player, int number)
{
    for(int i = 0 ; i < BINGO ; i++)
    {
        if (player->bingo[i] == number)
        {
            player->bingo_check[i] = 1;
            break;
        }
    }
}
void set_bingo_line(Player* player)
{
    player->line = 0;
    for(int ver = 0 ; ver < 5 ; ver++)
        (check_vertical_bingo(player, ver) == 5) ? (player->line += 1) : (player->line += 0);

    for(int hor = 0 ; hor < 5 ; hor++)
        (check_horizontal_bingo(player, hor * 5) == 5) ? (player->line += 1) : (player->line += 0);

    (check_diagonal_bingo_left_top_to_right_bottom(player, 0) == 5) ? (player->line += 1) : (player->line += 0);
    (check_diagonal_bingo_right_top_to_left_bottom(player, 4) == 5) ? (player->line += 1) : (player->line += 0);
}

/*
 *  0  1  2  3  4
 *  5  6  7  8  9
 * 10 11 12 13 14
 * 15 16 17 18 19
 * 20 21 22 23 24
 */
int check_vertical_bingo(const Player* player, int idx)
{
    if(idx >= BINGO) return 0;
    else {
        if(player->bingo_check[idx] == 0) return 0;
        else return check_vertical_bingo(player, idx + 5) + 1;
    }

}
int check_horizontal_bingo(const Player* player, int idx)
{
    if(idx % 5 == 4)
    {
        if (player->bingo_check[idx] == 1) return 1;
        else return 0;
    }
    else {
        if(player->bingo_check[idx] == 0) return 0;
        else return check_horizontal_bingo(player, idx + 1) + 1;
    }
}


int check_diagonal_bingo_left_top_to_right_bottom(const Player* player, int idx)
{
    if(idx >= BINGO) return 0;
    else {
        if(player->bingo_check[idx] == 0) return 0;
        else return check_diagonal_bingo_left_top_to_right_bottom(player, idx + 6) + 1;
    }
}
int check_diagonal_bingo_right_top_to_left_bottom(const Player* player, int idx)
{
    if(idx > BINGO - 5) return 0;
    else {
        if(player->bingo_check[idx] == 0) return 0;
        else return check_diagonal_bingo_right_top_to_left_bottom(player, idx + 4) + 1;
    }
}


void show_bingo(const Player* player)
{
    if(player->playerStatus)
    {
        printf("%s 의 빙고판입니다..\n", player->name);
        for(int i = 0 ; i < BINGO ; i++)
        {
            (player->bingo_check[i] == 1) ? printf("%3d", player->bingo[i]) : printf("%3s", "XX");
            (i % 5 == 4) ? printf("\n") : printf("");
        }
        printf("\n\n");
    }
    else
    {
        printf("%s 의 빙고판입니다..\n", player->name);
        for(int i = 0 ; i < BINGO ; i++)
        {
            printf("%3d", player->bingo[i]);
            (i % 5 == 4) ? printf("\n") : printf("");
        }
        printf("\n\n");
    }
}
