//
//  main.cpp
//  hanoi_code
//
//  Created by line.ash on 2021/11/19.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <bangtal>
#include "hanoi.hpp"
using namespace bangtal;
using namespace std;


class hanoi_Bar;
class hanoi_Tower;


ScenePtr hanoi_scene1, hanoi_scene2;
ObjectPtr hanoi_startButton, hanoi_endButton;
ObjectPtr hanoi_tower_img[3];
ObjectPtr hanoi_selectButton[3], hanoi_toButton[3], hanoi_clearButton;

ObjectPtr hanoi_howto;
ObjectPtr hanoi_story[3];
ObjectPtr hanoi_end;

extern ScenePtr mainScene;
extern void check_all_clear();
extern SoundPtr BGM2;
extern ObjectPtr main_button5;

//타워 객체 생성
hanoi_Tower hanoi_tower[3];
hanoi_Tower hanoi_towerR;
int hanoi_tempTower;

//*막대 객체 생성
hanoi_Bar BAR[4];


SoundPtr hanoi_BGM;
// 게임 2번 색칠하기 배경음악
void game5_bgm()
{
    hanoi_BGM = Sound::create("main_sounds/05.mp3");
    hanoi_BGM->play();
}


ScenePtr hanoi_game_init();
void hanoi_init()
{
    hanoi_game_init()->enter();
}

bool hanoi_check_Clear()
{
    for (int i = 0; i < 4; i++)
    {
        if (hanoi_tower[2].slot[i] == NULL)
            return false;
    }
    return true;
}
void hanoi_resetToButton()
{
    //버튼 초기화
    hanoi_selectButton[hanoi_tempTower]->setImage("hanoi_images/hanoi_selectButton.png"); //ing->select 버튼 이미지 변경
    for (int button = 0; button < 3; button++) //버튼 변경
    {
        if (button != hanoi_tempTower)
        {
            hanoi_selectButton[button]->show();
            hanoi_toButton[button]->hide();
        }
    }
}
//씬2 생성함수
void hanoi_create_scene2()
{
    //버튼 생성
    for (int i = 0; i < 3; i++)
    {
        hanoi_selectButton[i] = Object::create("hanoi_images/hanoi_selectButton.png", hanoi_scene2, 290 + 300 * i, 130);
    }
    for (int i = 0; i < 3; i++)
    {
        hanoi_toButton[i] = Object::create("hanoi_images/hanoi_toButton.png", hanoi_scene2, 290 + 300 * i, 130);
        hanoi_toButton[i]->hide();
    }

    //select 버튼 콜백
    //선택한 타워와 top막대를 확인합니다.
    for (int i = 0; i < 3; i++)
    {
        hanoi_selectButton[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hanoi_tempTower = i; // 선택한 타워 기억
            hanoi_tower[i].check_tower_index(); //타워 새로고침
            if (hanoi_tower[i].tower_top == -1) //막대가 없는 타워 선택시
            {
                showMessage("막대가 없는 타워입니다.");
            }
            if (hanoi_tower[i].tower_top >= 0)
            {
                hanoi_selectButton[i]->setImage("hanoi_images/hanoi_ingButton.png"); //버튼 이미지 변경
                for (int button = 0; button < 3; button++) //버튼 변경
                {
                    if (button != i)
                    {
                        hanoi_selectButton[button]->hide();
                        hanoi_toButton[button]->show();
                    }
                }
            }
            return true;
        });
    }

    //to 버튼 콜백
    //1.to 타워의 top 막대를 확인합니다.
    //2.index 비교를 통해 bool 판단을 합니다.
    //3.select 타워의 top 막대를 to 타워의 맨 위로 옮깁니다.
    for (int i = 0; i < 3; i++)
    {
        hanoi_toButton[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
            //1.to 타워의 top막대를 확인합니다.
            hanoi_tower[i].check_tower_index(); //타워 새로고침
            //2.index비교를 통해 bool 판단을 합니다.
            if (hanoi_tower[i].slot[0] == nullptr) //타워가 빈 경우
            {
                //그래픽
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top]->object->locate(hanoi_scene2, 240 + 300 * i, 220);
                //showMessage("막대를 옮겼습니다.");

                //백
                hanoi_tower[i].slot[0] = hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top];
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top] = nullptr;
                hanoi_tower[hanoi_tempTower].check_tower_index();
                hanoi_tower[i].check_tower_index();

                hanoi_resetToButton(); //버튼 초기화

            }
            else if (hanoi_tower[i].slot[hanoi_tower[i].tower_top]->index < hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top]->index) //옮기려는 막대가 더 작은 경우
            {
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top]->object->locate(hanoi_scene2, 240 + 300 * i, 270 + 50 * hanoi_tower[i].tower_top);
                //showMessage("막대를 옮겼습니다.");

                hanoi_tower[i].slot[hanoi_tower[i].tower_top + 1] = hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top];
                hanoi_tower[hanoi_tempTower].slot[hanoi_tower[hanoi_tempTower].tower_top] = nullptr;
                hanoi_tower[hanoi_tempTower].check_tower_index();
                hanoi_tower[i].check_tower_index();

                hanoi_resetToButton(); //버튼 초기화
            }
            else {
                //그 외 경우
                showMessage("타워를 옮길 수 없습니다.");

                hanoi_resetToButton();
            }
            if (hanoi_check_Clear() == true) //클리어 체크
            {
                hanoi_clearButton = Object::create("hanoi_images/hanoi_clearButton.png", hanoi_scene2, 540, 550);
                hanoi_clearButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                    //능력치값 수정

                    hanoi_end = Object::create("hanoi_images/hanoi_end.png", hanoi_scene2, 0, 0);
                    hanoi_end->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

                        // 메인 홈 화면 이동

                        hanoi_BGM->stop();
                        main_button5->hide();
                        BGM2->play();
                        check_all_clear();
                        mainScene->enter();

                        return true;
                    });//여기까지


                    return true;
                });
            }
            return true;
        });
    }
}

ScenePtr hanoi_game_init()
{

    // 
    //씬 생성
    hanoi_scene1 = Scene::create("scene1", "hanoi_images/hanoi_scene1.png");
    hanoi_scene2 = Scene::create("scene2", "hanoi_images/hanoi_scene2.png");

    game5_bgm();

    //오브젝트 생성, 콜백 등록
    hanoi_startButton = Object::create("hanoi_images/hanoi_startButton.png", hanoi_scene1, 880, 200);
    hanoi_startButton->setScale(0.25);
    hanoi_startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        //씬2 입장
        hanoi_create_scene2();
        hanoi_scene2->enter();

        // 새로 추가
        hanoi_howto = Object::create("hanoi_images/hanoi_howto.png", hanoi_scene2, 0, 0);
        hanoi_howto->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hanoi_howto->hide();
            return true;
        });

        for (int i = 2; i >= 0; i--)
        {
            char buf[50];
            sprintf(buf, "hanoi_images/hanoi_story%d.png", i);
            hanoi_story[i] = Object::create(buf, hanoi_scene2, 0, 0);
            hanoi_story[i]->setOnMouseCallback([&, i](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hanoi_story[i]->hide();
                return true;
            });
        }


        return true;
    });

    //시작화면-endButton
    hanoi_endButton = Object::create("hanoi_images/hanoi_endButton.png", hanoi_scene1, 880, 100);
    hanoi_endButton->setScale(0.25);
    hanoi_endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        mainScene->enter();

        return true;
    });

    //타워 오브젝트 생성
    for (int i = 0; i < 3; i++)
    {
        Object::create("hanoi_images/hanoi_tower.png", hanoi_scene2, 240 + 300 * i, 190.8);
    }

    //막대 생성 및 슬롯 등록

    BAR[0].setInfo(0, hanoi_scene2);
    BAR[1].setInfo(1, hanoi_scene2);
    BAR[2].setInfo(2, hanoi_scene2);
    BAR[3].setInfo(3, hanoi_scene2);

    hanoi_tower[0].slot[0] = &BAR[0];
    hanoi_tower[0].slot[1] = &BAR[1];
    hanoi_tower[0].slot[2] = &BAR[2];
    hanoi_tower[0].slot[3] = &BAR[3];


    return hanoi_scene1;
}

/*
int main() {

    //게임옵션설정
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

    //게임시작
    startGame(hanoi_game_init());

    return 0;
}*/
