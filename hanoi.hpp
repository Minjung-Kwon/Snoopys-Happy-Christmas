#pragma once

//
//  hanoi.hpp
//  hanoi_code
//
//  Created by line.ash on 2021/11/26.
//

#define _CRT_SECURE_NO_WARNINGS

#ifndef hanoi_hpp
#define hanoi_hpp

#include <iostream>
#include <bangtal>
using namespace bangtal;

//막대 클래스
class hanoi_Bar {
public:
    int index;
    ObjectPtr object;
    hanoi_Bar(int i, ScenePtr scene);
    hanoi_Bar() {};
    void setInfo(int i, ScenePtr scene);
};

//타워 클래스
class hanoi_Tower {
public:
    hanoi_Bar* slot[4];//={nullptr}; //타워는 막대 소유 유무를 알기 위해 막대포인터를 가진다.
    int tower_top = -1; //타워에 막대가 몇층까지 있는지.
    int tower_index = -1; //타워의 맨 위 막대 크기.

    hanoi_Tower() {
        tower_top = -1;
        tower_index = -1;
    };
    int check_top();
    int check_tower_index();
};

#endif /* hanoi_hpp */

