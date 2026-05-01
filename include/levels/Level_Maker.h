#pragma once
#include<string>
using namespace std;

struct level_maker{


    int level_id;
    bool boos_level;
    bool bonus;
    const  char *level_name_arr;
    int T_enemies;
    float enemy_speed;

    float enemy_x[6];
    float enemy_y[6];

    string BOTTOM_TEXTURE;

    // float bar_x[10];
    // float bar_y[10];
    // float bar_w[10];
    // float bar_h[10];


};

extern level_maker arr_main_levels[];
///now as per recquired levels we make an array
 extern  const int TOTAL_LEVELS;
//^^ got thios formuala fromn AI
