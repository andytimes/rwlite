/*
 * Copyright (c) 2015-2016, Andy Deng <theandy.deng@gmail.com>
 *
 * Licensed under the FreeBSD as detailed in the accompanying
 * LICENSE file.
 */

#ifndef __REWRITE_H
#define __REWRITE_H

#include <SDL.h>
#include <SDL_mixer.h>

#ifndef RWDEBUG
#define sleep(n) SDL_Delay(1000 * (n))
#else
#define sleep(n) {};
#endif

#define BGMDIR "BGM/"

enum music_name {
	YACHUI = 0,
	ERLUNCAO,
	MIANMAOZI,
	LV,
	SANKA,
	DISISAPAIN,
	PHILOSOPHYZ
};

extern const char *bgm[];
extern int music_on;
extern int char_control;
extern int char_delay;
extern int aurora;

static inline void mix_init(void)
{
	if (music_on) {
		Mix_Init(MIX_INIT_OGG);
		Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
	}
}

static inline void play_music(const char *now_play)
{
	if (music_on)
		Mix_PlayMusic(Mix_LoadMUS(now_play), -1);
}

void start_menu(void);
void main_line(void);

#endif /* __REWRITE_H */
