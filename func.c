/*
 * Copyright (c) 2015-2016, Andy Deng <theandy.deng@gmail.com>
 *
 * Licensed under the FreeBSD as detailed in the accompanying
 * LICENSE file.
 */

#include <stdio.h>
#include <SDL.h>
#include "rewrite.h"
#include "cursor.h"

// #define RWDEBUG

const char *bgm[] = {
	BGMDIR"BGM001.ogg", BGMDIR"BGM010.ogg", BGMDIR"BGM013.ogg",
	BGMDIR"BGM016.ogg", BGMDIR"BGM017.ogg", BGMDIR"BGM034.ogg",
	BGMDIR"BGM046.ogg"
};

int music_on;
int char_control;
int char_delay;
int aurora;

void txt_view(const char* str, const unsigned int delay)
{
	if (!SDL_QuitRequested()) {
		for (size_t i = 0; str[i]; ++i) {
			printf("%c", str[i]);
#if !defined(_WIN32) && !defined(_WIN64)
			fflush(stdout);
#endif

			if (char_control)
				SDL_Delay(char_delay);
			else
				SDL_Delay(24);
		}
#ifndef RWDEBUG
		sleep(delay);
#else
#endif
	}
}

static int music_switch(void)
{
	unsigned int i = 0;

	printf("\n是否开启音乐？\n1.开启  2.关闭\n选择(输入数字) : ");

	do {
		while (getchar() != '\n') ;
		scanf("%u", &i);
		if (i == 1)
			return 1;
		else if (i == 2)
			return 0;
		else
			printf("请输入正确数字(1 或 2) : ");
	} while (1);
}

void start_menu(void)
{
	unsigned int i = 0;

	clr_scr();
	printf("这是一个Rewrite文字版冒险游戏\n\n1.开始Rewrite\n"
		"2.继续Rewrite (暂不可用)\n3.退出\n选择(输入数字)：");

	do {
		scanf("%u", &i);
		if (i == 1)
			goto Start;
		else if (i == 2)
			// goto Read;
			printf("此选项暂不可用, 请选择其他选项 : ");
		else if (i == 3)
			goto End;
		else
			printf("请输入正确数字 (1 或 3) : ");
		while (getchar() != '\n') ;
	} while (1);

 Start:
	music_on = music_switch();
	mix_init();
	play_music(bgm[LV]);
	clr_scr();
	txt_view("\n将一切，全部改写 ...\n", 5);
	clr_scr();

	main_line();
	return;

#if 0
// FIXME: unimplemented, implement it later
 Read:
	clr_scr();
	music_on = music_switch();
	mix_init();
	play_music(bgm[LV]);
	txt_view("\n延续 ...", 2);
	clr_scr();

	return;
#endif

// FIXME: incomplete, make it complete later
 End:
	clr_scr();
	txt_view("\n结束 ...", 2);
	clr_scr();

	return;
}
