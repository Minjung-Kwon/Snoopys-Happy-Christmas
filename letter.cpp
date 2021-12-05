#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
#include <iostream>
#include <stdio.h>
using namespace bangtal;

extern ScenePtr mainScene;
extern ObjectPtr main_button1;

extern void check_all_clear();
extern SoundPtr BGM2;


ScenePtr Letter_text1, Snoopy_Letter, Letter_text2, Letter_text3;

ObjectPtr letter_text1, letter_text2, letter_text3, next_button1, next_button2, Letter_page, gamerule, letter_text4, ok_button4, letter_text5, ok_button5, letter_text6, letter_text7, letter_text8, next_button6, letter_text9, letter_text10, letter_text11, next_button9, postbox, letter_start, typing_snoopy;

int game_on = 0;
int text_index = 0;
int postbox_on = 0;
ObjectPtr word[88];
int word_x = 325;
int word_y = 580;
int word_index = 0;


SoundPtr letter_BGM;
// 게임 1번 편지쓰기 배경음악
void game1_bgm()
{
	letter_BGM = Sound::create("main_sounds/01.mp3");
	letter_BGM->play();
}




void letter_game_start() {



	letter_text1 = Object::create("letter_images/letter_text1.png", Letter_text1, 0, 0);
	letter_text2 = Object::create("letter_images/letter_text2.png", Letter_text1, 0, 0);
	letter_text2->hide();
	letter_text3 = Object::create("letter_images/letter_text3.png", Letter_text2, 0, 0);


	next_button1 = Object::create("letter_images/next_button.png", Letter_text1, 920, 40);
	next_button1->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (text_index == 0) {

			letter_text1->hide();
			letter_text2->show();
			text_index++;
		}
		else if (text_index == 1) {
			Letter_text2->enter();
			text_index--;
		}
		return true;

	});

	next_button2 = Object::create("letter_images/next_button.png", Letter_text2, 920, 40);
	next_button2->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		Snoopy_Letter->enter();
		return true;

	});

	Letter_page = Object::create("letter_images/letter.png", Snoopy_Letter, 223, 241);
	Letter_page->hide();

	gamerule = Object::create("letter_images/letter_game_rule.png", Snoopy_Letter, 0, 0);

	letter_text4 = Object::create("letter_images/letter_text4.png", Snoopy_Letter, 0, 0);
	letter_text4->hide();
	ok_button4 = Object::create("letter_images/next_button.png", Snoopy_Letter, 920, 40);
	ok_button4->hide();

	ok_button4->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		letter_text4->hide();
		ok_button4->hide();
		return true;

	});

	letter_text5 = Object::create("letter_images/letter_text5.png", Snoopy_Letter, 0, 0);
	letter_text5->hide();

	ok_button5 = Object::create("letter_images/next_button.png", Snoopy_Letter, 920, 40);
	ok_button5->hide();

	ok_button5->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		letter_text5->hide();
		ok_button5->hide();

		postbox_on++;
		return true;

	});

	letter_text6 = Object::create("letter_images/letter_text6.png", Snoopy_Letter, 0, 0);
	letter_text6->hide();

	letter_text7 = Object::create("letter_images/letter_text7.png", Snoopy_Letter, 0, 0);
	letter_text7->hide();

	letter_text8 = Object::create("letter_images/letter_text8.png", Snoopy_Letter, 0, 0);
	letter_text8->hide();

	next_button6 = Object::create("letter_images/next_button.png", Snoopy_Letter, 920, 40);
	next_button6->hide();

	next_button6->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (text_index == 0) {

			letter_text6->hide();
			letter_text7->show();
			text_index++;
		}

		else if (text_index == 1) {

			letter_text7->hide();
			letter_text8->show();
			text_index++;
		}

		else if (text_index == 2) {
			Letter_text3->enter();
			text_index = 0;
		}
		return true;

	});

	letter_text9 = Object::create("letter_images/letter_text9.png", Letter_text3, 0, 0);

	letter_text10 = Object::create("letter_images/letter_text10.png", Letter_text3, 0, 0);
	letter_text10->hide();

	letter_text11 = Object::create("letter_images/letter_text11.png", Letter_text3, 0, 0);
	letter_text11->hide();

	next_button9 = Object::create("letter_images/next_button.png", Letter_text3, 920, 40);

	next_button9->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (text_index == 0) {

			letter_text9->hide();
			letter_text10->show();
			text_index++;
		}

		else if (text_index == 1) {

			letter_text10->hide();
			letter_text11->show();
			text_index++;
		}

		else if (text_index == 2) {

			// 메인 장면 이동

			main_button1->hide();

			letter_BGM->stop();
			BGM2->play();
			check_all_clear();



			mainScene->enter();

		}
		return true;

	});


	typing_snoopy = Object::create("letter_images/letter_snoopy.png", Snoopy_Letter, 450, -50);
	typing_snoopy->hide();



	postbox = Object::create("letter_images/postbox.png", Snoopy_Letter, 1070, 150);
	postbox->hide();
	postbox->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		if (postbox_on == 0) {
			letter_text4->show();
			ok_button4->show();
		}
		else if (postbox_on == 1) {}
		else if (postbox_on == 2) {
			Letter_page->hide();
			letter_text6->show();
			next_button6->show();
			for (int i = 0; i < 86; i++)
			{
				word[i]->hide();

			}

		}
		return true;


	});

	letter_start = Object::create("letter_images/letter_start.png", Snoopy_Letter, 500, 50);
	letter_start->setOnMouseCallback([&](auto object, auto x, auto y, auto action)->bool {
		gamerule->hide();
		Letter_page->show();
		postbox->show();
		game_on++;
		letter_start->hide();

		typing_snoopy->show();

		return true;

	});




	char path[60];
	for (int i = 0; i < 9; i++)
	{
		sprintf(path, "letter_images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * i, word_y);
		word[i]->hide();
	}

	for (int i = 9; i < 25; i++)
	{
		sprintf(path, "letter_images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 12), word_y - 50);
		word[i]->hide();
	}

	for (int i = 25; i < 41; i++)
	{
		sprintf(path, "letter_images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 28), word_y - 90);
		word[i]->hide();
	}

	for (int i = 41; i < 57; i++)
	{
		sprintf(path, "letter_images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 44), word_y - 130);
		word[i]->hide();
	}

	for (int i = 57; i < 73; i++)
	{
		sprintf(path, "letter_images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 60), word_y - 175);
		word[i]->hide();
	}

	for (int i = 73; i < 87; i++)
	{
		sprintf(path, "letter_images/snoopy_letter_%d.png", i);
		word[i] = Object::create(path, Snoopy_Letter, word_x + 25 * (i - 76), word_y - 220);
		word[i]->hide();
	}

	Snoopy_Letter->setOnKeyboardCallback([&](ScenePtr scene2, KeyCode code, bool pressed)->bool {
		if (pressed == true && word_index <= 86 && game_on == 1) {

			switch (code) {
			case KeyCode::KEY_SPACE: if (word_index < 87) { word[word_index]->show(); word_index++; }  break;
			}
			if (word_index == 87) {

				typing_snoopy->hide();
				letter_text5->show();
				ok_button5->show();
				postbox_on++;
			}
		}
		return true;
	});


}



void letter_init()
{


	Letter_text1 = Scene::create("편지", "letter_images/Letter_page1.png");
	Snoopy_Letter = Scene::create("편지", "letter_images/letter_page.png");
	Letter_text2 = Scene::create("편지", "letter_images/Letter_page2.png");
	Letter_text3 = Scene::create("편지", "letter_images/letter_page3.png");


	game1_bgm();

	Letter_text1->enter();
	letter_game_start();

}



/*
int main() {
	Letter_init();
}
*/