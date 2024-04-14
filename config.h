#ifndef CONFIG
#define CONFIG

struct Point{
    int x, y;
    Point(){
        x = 0;
        y = 0;
    }

    Point(int x_, int y_){
        x = x_;
        y = y_;
    }

    void operator=(Point p){
        x = p.x;
        y = p.y;
    }
};

const int BLUE_COLOR = 1;
const int BLACK_COLOR = 0;
const int RED_COLOR = 4;
const int PURPLE_COLOR = 5;
const int WHITE_COLOR = 7;
const int WIDTH = 50;
const int HEIGHT = 30;
const int PAUSE_TIME = 500; // milisecond
const int BLOCK_RATIO = 1;
int board_game[HEIGHT][WIDTH];
int win_flag = 0; //1: player 1, -1: player 2, 0: Game Draw/Continue
Point win_path[5];
const int WIN_LENGTH = 5;
const int MAX_DEPTH = 3;
int bestmove[2]={14,24};
int winner;

#endif // CONFIG
