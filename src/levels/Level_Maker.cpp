#include"../../include/levels/Level_Maker.h"

level_maker arr_main_levels[]={

1,false,false,"level1",3,100.0f,{900,500,700,0,0,0},{300,300,600,0,0,0},"assets/Images/Botom_Blue.png",
    2,false,false,"level2",4,130.0f,{200,800,500,600,0,0},{200,400,300,500,0,0},"assets/Images/Botom_Pink.png",
    3,false,false,"level1",5,150.0f,{130,400,700,1000,600,0},{300,400,300,400,500,0},"assets/Images/Botom_Orange.png",
    4,false,true,"level2",3,170.0f,{300,700,500,0,0,0},{200,200,400,0,0,0},"assets/Images/Botom_Blue.png",
    5,true,false,"level5_BOSS",0,0.0f,{0,0,0,0,0,0},{0,0,0,0,0,0},"assets/Images/Botom_Orange.png",
    6,false,false,"level6",5,190.0f,{130,400,700,1000,500,0},{300,200,300,200,400,0},"assets/Images/Botom_Pink.png",
    7,false,false,"level7",5,210.0f,{200,500,800,300,700,0},{200,300,200,400,400,0},"assets/Images/Botom_Orange.png",
    8,false,false,"level8",5,230.0f,{130,350,650,900,600,0},{400,200,400,200,300,0},"assets/Images/Botom_Blue.png",
    9,false,true,"level9",6,250.0f,{130,350,600,850,400,700},{300,400,200,300,500,200},"assets/Images/",
    10,true,false,"level10_BOSS",0,0.0f,{0,0,0,0,0,0},{0,0,0,0,0,0},"assets/Images/Botom_Blue.png"

};

 const int TOTAL_LEVELS = sizeof(arr_main_levels) / sizeof(arr_main_levels[0]);