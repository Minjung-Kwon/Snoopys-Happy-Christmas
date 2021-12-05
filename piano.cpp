#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
#include <iostream>
#include <stdio.h>
using namespace bangtal;

extern ScenePtr mainScene;
extern void check_all_clear();
extern SoundPtr BGM2;
extern ObjectPtr main_button3;

ScenePtr Piano_start;
ScenePtr Piano_gamerule;
ObjectPtr piano_text1;
ObjectPtr piano_text2;
ObjectPtr piano_text3;
ObjectPtr piano_text4;
ObjectPtr piano_text5;
ObjectPtr piano_text6;
ObjectPtr piano_text7;
ObjectPtr piano_text8;

ObjectPtr p_next_button1;
ObjectPtr p_next_button2;
ObjectPtr p_next_button3;
ObjectPtr p_next_button4;
ObjectPtr piano_start_button;

ScenePtr Piano_Play1;
ScenePtr Piano_Play2;
ScenePtr Piano_Play3;

ObjectPtr Dot1;
ObjectPtr Dot2;
ObjectPtr Dot3;

int piano_text_index;
int key_press[25] = { 0, };
int key_index = 0;

int Rudolf_Notes[14] = { 4, 5, 4, 2, 7, 5, 4, 4, 5, 4, 5, 4, 7, 6 };
int Lookoutthewindow_Notes[16] = { 4, 4, 4, 4, 2, 4, 4, 4, 4, 2, 4, 4, 2, 4, 7, 6 };
int Jinglebell_Notes[25] = { 2, 2, 2, 2, 2, 2, 2, 4, 0, 1, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 2, 1, 4 };
SoundPtr Note[8];
char path[20];
int stage = 1;

void Piano_first() {


    piano_text2->hide();
    piano_text3->hide();
    piano_text4->hide();
    piano_text5->hide();
    piano_text6->hide();
    piano_text7->hide();
    piano_text8->hide();

    p_next_button2->hide();
    p_next_button3->hide();
    p_next_button4->hide();

    p_next_button1->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text1->hide();
            piano_text2->show();
            piano_text_index++;
        }
        else if (piano_text_index == 1) {
            piano_text2->hide();
            p_next_button1->hide();
            piano_text3->show();
            p_next_button2->show();
            Piano_gamerule->enter();

            piano_text_index = 0;

        }
        return true;
    });

    piano_start_button->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        Piano_Play1->enter();
        return true;
    });

    p_next_button2->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text3->hide();
            piano_text4->show();
            piano_text_index++;
        }

        else if (piano_text_index == 1) {

            piano_text4->hide();
            p_next_button2->hide();
            piano_text5->show();
            p_next_button3->show();
            Piano_Play2->enter();
            piano_text_index = 0;
        }
        return true;
    });

    p_next_button3->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text5->hide();
            piano_text6->show();
            piano_text_index++;
        }

        else if (piano_text_index == 1) {
            piano_text6->hide();
            p_next_button3->hide();
            piano_text7->show();
            p_next_button4->show();
            Piano_Play3->enter();
            piano_text_index = 0;
        }
        return true;
    });

    p_next_button4->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        if (piano_text_index == 0) {
            piano_text7->hide();
            piano_text8->show();
            piano_text_index++;
        }

        else if (piano_text_index == 1) {

            /*
             *  스누피 게임 전체 메인 화면 이동
             */
            main_button3->hide();
            BGM2->play();
            check_all_clear();
            mainScene->enter();

        }
        return true;
    });

    piano_start_button->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
        Piano_Play1->enter();
        return true;
    });








    Piano_Play1->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
        int key = 0;
        if (pressed == true) {
            switch (code) {
            case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot1->locate(Piano_Play1, 80, 20); break;
            case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot1->locate(Piano_Play1, 238, 20); break;
            case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot1->locate(Piano_Play1, 396, 20); break;
            case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot1->locate(Piano_Play1, 554, 20); break;
            case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot1->locate(Piano_Play1, 712, 20); break;
            case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot1->locate(Piano_Play1, 870, 20); break;
            case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot1->locate(Piano_Play1, 1028, 20); break;
            case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot1->locate(Piano_Play1, 1186, 20); break;
            }
            key_press[key_index] = key;


            if (key_press[key_index] == Rudolf_Notes[key_index]) key_index++;
            else key_index = 0;

            if (key_index == 14) {
                Piano_start->enter();
                stage++;
                key_index = 0;

            }

        };

        return true;
    });

    Piano_Play2->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
        int key = 0;
        if (pressed == true) {
            switch (code) {
            case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot2->locate(Piano_Play2, 80, 20); break;
            case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot2->locate(Piano_Play2, 238, 20); break;
            case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot2->locate(Piano_Play2, 396, 20); break;
            case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot2->locate(Piano_Play2, 554, 20); break;
            case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot2->locate(Piano_Play2, 712, 20); break;
            case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot2->locate(Piano_Play2, 870, 20); break;
            case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot2->locate(Piano_Play2, 1028, 20); break;
            case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot2->locate(Piano_Play2, 1186, 20); break;
            }
            key_press[key_index] = key;

            if (key_press[key_index] == Lookoutthewindow_Notes[key_index]) key_index++;
            else key_index = 0;

            if (key_index == 16) {
                Piano_start->enter();
                stage++;
                key_index = 0;

            }

        };
        return true;
    });

    Piano_Play3->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
        int key = 0;
        if (pressed == true) {
            switch (code) {
            case KeyCode::KEY_1: key = 0; Note[0]->play(); Dot3->locate(Piano_Play3, 80, 20); break;
            case KeyCode::KEY_2: key = 1; Note[1]->play(); Dot3->locate(Piano_Play3, 238, 20); break;
            case KeyCode::KEY_3: key = 2; Note[2]->play(); Dot3->locate(Piano_Play3, 396, 20); break;
            case KeyCode::KEY_4: key = 3; Note[3]->play(); Dot3->locate(Piano_Play3, 554, 20); break;
            case KeyCode::KEY_5: key = 4; Note[4]->play(); Dot3->locate(Piano_Play3, 712, 20); break;
            case KeyCode::KEY_6: key = 5; Note[5]->play(); Dot3->locate(Piano_Play3, 870, 20); break;
            case KeyCode::KEY_7: key = 6; Note[6]->play(); Dot3->locate(Piano_Play3, 1028, 20); break;
            case KeyCode::KEY_8: key = 7; Note[7]->play(); Dot3->locate(Piano_Play3, 1186, 20); break;
            }
            key_press[key_index] = key;



            if (key_press[key_index] == Jinglebell_Notes[key_index]) key_index++;
            else key_index = 0;

            if (key_index == 25) {
                Piano_start->enter();
                stage++;
                key_index = 0;


            }



        };
        return true;
    });


}

void piano_init() {
    Piano_start = Scene::create("피아노", "piano_images/Piano_start.png");
    Piano_gamerule = Scene::create("피아노", "piano_images/Piano_gamerule.png");

    piano_text1 = Object::create("piano_images/piano_text1.png", Piano_start, 0, 0);
    piano_text2 = Object::create("piano_images/piano_text2.png", Piano_start, 0, 0);
    piano_text3 = Object::create("piano_images/piano_text3.png", Piano_start, 0, 0);
    piano_text4 = Object::create("piano_images/piano_text4.png", Piano_start, 0, 0);
    piano_text5 = Object::create("piano_images/piano_text5.png", Piano_start, 0, 0);
    piano_text6 = Object::create("piano_images/piano_text6.png", Piano_start, 0, 0);
    piano_text7 = Object::create("piano_images/piano_text7.png", Piano_start, 0, 0);
    piano_text8 = Object::create("piano_images/piano_text8.png", Piano_start, 0, 0);

    p_next_button1 = Object::create("piano_images/next_button.png", Piano_start, 920, 40);
    p_next_button2 = Object::create("piano_images/next_button.png", Piano_start, 920, 40);
    p_next_button3 = Object::create("piano_images/next_button.png", Piano_start, 920, 40);
    p_next_button4 = Object::create("piano_images/next_button.png", Piano_start, 920, 40);
    piano_start_button = Object::create("piano_images/스타트게임.png", Piano_gamerule, 520, 50);

    piano_text_index = 0;
    Piano_Play1 = Scene::create("피아노", "piano_images/루돌프사슴코악보.png");
    Piano_Play2 = Scene::create("피아노", "piano_images/창밖을보라악보.png");
    Piano_Play3 = Scene::create("피아노", "piano_images/징글벨악보.png");

    Dot1 = Object::create("piano_images/점.png", Piano_Play1, -100, 20);
    Dot2 = Object::create("piano_images/점.png", Piano_Play2, -100, 20);
    Dot3 = Object::create("piano_images/점.png", Piano_Play3, -100, 20);

    for (int i = 0; i < 8; i++)
    {
        sprintf(path, "piano_sounds/%d.mp3", i + 1);
        Note[i] = Sound::create(path);
    }

    Piano_start->enter();
    Piano_first();


}



/*
int main() {

    piano_init();

    startGame(Piano_start);

    return 0;
}
*/