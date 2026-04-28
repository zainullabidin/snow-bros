#pragma once

struct level_maker{


    int level_id;
    bool boos_level;
    bool bonus;
   const  char *level_name_arr;
    int T_enemies;


};

///now as per recquired levels we make an array
level_maker arr_main_levels[]={

    1,false,true,"level1",3,
    2,false,true,"level2",4,
    3,false,true,"level3",5,
    4,false,true,"level4",3,
    5,true,false,"level5_BOSS",0,
    6,false,true,"level6",5,
    7,false,true,"level7",5,
    8,false,true,"level8",5,
    9,false,true,"level9",6,
    10,true,false,"level10_BOSS",0

};


const int TOTAL_LEVELS = sizeof(arr_main_levels) / sizeof(arr_main_levels[0]);
//^^ got thios formuala fromn AI
