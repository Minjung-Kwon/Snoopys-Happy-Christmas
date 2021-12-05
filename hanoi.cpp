//
//  hanoi.cpp
//  hanoi_code
//
//  Created by line.ash on 2021/11/26.
//

#define _CRT_SECURE_NO_WARNINGS

#include "hanoi.hpp"
#include <iostream>
#include <bangtal>
using namespace bangtal;

//막대 클래스
hanoi_Bar::hanoi_Bar(int i, ScenePtr scene) :index(i) {
    char buf[30];
    sprintf(buf, "hanoi_images/hanoi_%d.png", i);
    object = Object::create(buf, scene, 240, 220 + 50 * i); //막대는 모두 첫번째 타워에서 생성된다.
};

void hanoi_Bar::setInfo(int i, ScenePtr scene) {
    index = i;
    char buf[30];
    sprintf(buf, "hanoi_images/hanoi_%d.png", i);
    object = Object::create(buf, scene, 240, 220 + 50 * i); //막대는 모두 첫번째 타워에서 생성된다.
};

//타워 클래스
/*
hanoi_Tower::hanoi_Tower()
    {

    }*/

int hanoi_Tower::check_top() //타워에 막대가 몇층까지 있는지 체크합니다.
{
    tower_top = -1; //초기화
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] != nullptr)
            tower_top = i;
    }
    return tower_top;
}

int hanoi_Tower::check_tower_index() //맨 위 막대의 크기를 확인합니다.
{
    tower_index = -1; //초기화
    if (check_top() == -1)
    {
        //showMessage("타워가 비었습니다.");
    }
    else if (check_top() >= 0) {
        tower_index = slot[check_top()]->index;
    }
    return tower_index;
}
