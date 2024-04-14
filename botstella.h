#ifndef BOTSTELLA
#define BOTSTELLA

#include <iostream>
#include <stdlib.h>
#include "config.h"

Point check_win_stella(int board_game[][WIDTH], int player_id);
Point defend_stella(int board_game[][WIDTH], int player_id);
Point attack_stella(int board_game[][WIDTH], int player_id);
Point check_n_tile_stella(int board_game[][WIDTH], int player_id, int n);


Point player_Stella(int board_game[][WIDTH], int player_id){
    Point p = check_win_stella(board_game, player_id);
    if(p.x != -1 && p.y != -1)
            return p;
     else {
        p = defend_stella(board_game, player_id);
        if(p.x != -1 && p.y != -1){

            return p;
        } else {
            return attack_stella(board_game, player_id);
        }
    }
}

Point check_win_stella(int board_game[][WIDTH], int player_id)
{
    Point p = check_n_tile_stella(board_game, player_id, 4);
    if(p.x != -1 && p.y != -1)
        return p;
     return Point(-1,-1);
}
Point defend_stella(int board_game[][WIDTH], int player_id)
{
    Point p = check_n_tile_stella(board_game, -player_id, 3);
    if(p.x != -1 && p.y != -1)
        return p;
     return Point(-1,-1);
}

Point attack_stella(int board_game[][WIDTH], int player_id)
{
    Point p = check_n_tile_stella(board_game, player_id, 3);
    if(p.x != -1 && p.y != -1)
        return p;

    p = check_n_tile_stella(board_game, -player_id, 3);
    if(p.x != -1 && p.y != -1)
        return p;

    p = check_n_tile_stella(board_game, player_id, 2);
    if(p.x != -1 && p.y != -1)
        return p;

    p = check_n_tile_stella(board_game, -player_id, 2);
    if(p.x != -1 && p.y != -1)
        return p;

    p = check_n_tile_stella(board_game, player_id, 1);
    if(p.x != -1 && p.y != -1)
        return p;

    p = check_n_tile_stella(board_game, -player_id, 1);
    if(p.x != -1 && p.y != -1)
        return p;


    return player_rand(board_game,player_id);
}
Point check_n_tile_stella(int board_game[][WIDTH], int player_id, int n)
{
    int score = 0;
    for(int i=0; i<HEIGHT; i++)
        for(int j=0; j<WIDTH; j++)
        {
            if(board_game[i][j] == 0)
            {
                // check 12h
                for(int k = 1; k<=n && i-k>=0 ; k++)
                {
                    if(board_game[i-k][j] != player_id)
                        break;
                    else score ++;
                }
                if(score == n) return Point(i,j);
                else score = 0;

                // check 1h
                for(int k = 1; k<=n && i-k >= 0 && j+k < WIDTH ; k++)
                {
                    if(board_game[i-k][j+k] != player_id)
                        break;
                    else score ++;
                }
                if(score == n) return Point(i,j);
                else score = 0;

                // check 3h
                for(int k = 1; k<=n && j+k < WIDTH; k++)
                {
                    if(board_game[i][j+k] != player_id)
                        break;
                    else score ++;
                }
                if(score == n) return Point(i,j);
                else score = 0;

                // check 5h
                for(int k = 1; k<=n && i+k < HEIGHT && j+k < WIDTH ; k++)
                {
                    if(board_game[i+k][j+k] != player_id)
                        break;
                    else score ++;
                }
                if(score == n) return Point(i,j);
                else score = 0;

                // check 6h
                for(int k = 1; k<=n && i+k < HEIGHT; k++)
                {
                    if(board_game[i+k][j] != player_id)
                        break;
                    else score ++;
                }
                if(score == n)
                {
                    return Point(i,j);
                }
                else score = 0;

                // check 7h
                for(int k = 1; k<=n && i+k < HEIGHT && j-k >= 0; k++)
                {
                    if(board_game[i+k][j-k] != player_id)
                        break;
                    else score ++;
                }
                if(score == n) return Point(i,j);
                else score = 0;

                // check 9h
                for(int k = 1; k<=n && j-k >= 0; k++)
                {
                    if(board_game[i][j-k] != player_id)
                        break;
                    else score ++;
                }
                if(score == n) return Point(i,j);
                else score = 0;

                // check 11h
                for(int k = 1; k<=n && i-k>=0 && j-k >=0; k++)
                {
                    if(board_game[i-k][j-k] != player_id)
                        break;
                    else score ++;
                }
                if(score == n) return Point(i,j);
                else score = 0;
            }
        }
    if(score == 0) return Point(-1,-1);
}


#endif // BOTSTELLA
