/*
 * Copyright (c) 2015-2016, Andy Deng <theandy.deng@gmail.com>
 *
 * Licensed under the FreeBSD as detailed in the accompanying
 * LICENSE file.
 */

#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include "rewrite.h"
#include "cursor.h"

static void txt_preface(void)
{
	Mix_PauseMusic();
	prt_title("            - 序言 -");
	sleep(4);

	play_music(bgm[ERLUNCAO]);
	prt_sub("【瑚太朗】");
	prt_info("有时候，我会感到自己一无所有。", 2);
	prt_info("本以为装满了幸福的口袋，其实空空如也。", 3);
	prt_info("因为根本就没有努力去收集过，那也是理所当然的。", 3);
	prt_info("可是，我连这都不明白。", 2);
	prt_info("漫不经心地虚度空无的人生。", 2);
	prt_info("有一天，我突然察觉到自己已经浪费了很多的时间。", 3);
	prt_info("我跟谁都能聊得开，不管那是怎样的人。", 3);
	prt_info("可是却没有知心朋友。就连一个也没有。", 3);
	prt_info("这意味着什么，其实根本不用去考虑。", 3);
	prt_info("我的人生就是这么单薄。", 2);
	prt_info("曾经只有青梅竹马的神户小鸟,\n"
		 "是不会对我说客套话的朋友。", 3);
	prt_info("没错。", 2);
	prt_info("...是朋友。", 2);
	prt_info("（我要重新来过）", 2);
	prt_info("（下次一定可以成功）", 2);
	prt_info("我衷心祈祷着。", 2);
	prt_info("只是，大概很难实现吧。", 2);
	prt_info("大家都在为之忙碌奔波。", 2);
	prt_info("幸福不会从天而降。", 2);
	prt_info("必须靠自己的努力走向它。", 2);
	prt_info("幸福是什么呢？", 2);
	prt_info("像青春一样的东西吗？", 2);
	prt_info("那青春又是什么？", 2);
	prt_info("\"是什么光彩夺目的东西吧\"，小鸟说。", 3);
	prt_info("\"...鬼知道，谁有功夫去想这些！\"，吉野喷道。", 3);
	prt_info("很久以前，不知是谁说过\"人生就像在走钢丝\"的话。", 3);
	prt_info("三人的话我都很赞同。", 2);
	prt_info("幸福是耀眼的、未知的、令人敬畏的东西。", 3);
	prt_info("所以幸福是难求的。因为它没有标准答案。", 3);
	prt_info("但我还是决定踏上寻找幸福的旅途。", 3);
	prt_info("可是，时间是残酷的。", 2);
	prt_info("一转眼，夏天就到了。", 2);
	prt_info("而秋天的到来也只是一瞬的事。", 2);
	prt_info("我这才注意到，自己已经高二了。", 3);
	prt_info("我很焦急。", 2);
	prt_info("因为我仍旧两手空空。", 2);
	prt_info("可是，就连接下来该做什么我都不知道。", 3);
	prt_info("每天只是这样，虚度光阴而已...", 4);
}

static void txt_moon_start(void)
{
	Mix_PauseMusic();
	prt_title("           - Moon - 月光");
	sleep(2);
	prt_title("           - 月光漫步 -");
	prt_sub("【瑚太朗】");
	prt_info("...这是个无法入睡的夜晚。", 2);
	prt_info("也是无需入睡的夜晚。", 2);
	prt_info("（为什么丝毫不觉得奇怪呢...）", 3);
	prt_info("房间的空气，都如同化石般，异常干燥。", 3);
	prt_info("这里，待不下去了。", 2);
	prt_info("那就去外面吧。", 2);
	prt_info("目的地 ?", 2);
	prt_info("似乎早就决定过了。", 2);
	prt_info("山丘...", 2);
	prt_info("虽然这种想法毫无根据，但心里还是明白。", 3);
	prt_info("即使没有任何理由，也会做出\"一定要那样做\"的判断。", 3);
	prt_info("就好像，能预知将要发生的事情那样。", 2);
	prt_info("未来会经历的，我事先就知道了吗？", 3);
	prt_info("未来？", 2);
	prt_info("在这里，也许不是一种合适的描述。", 3);
	prt_info("“过去”，“未来”，在这儿, 就像无忧无虑的学生\n"
		 "对“战争”和“谍报活动”的认知一样。", 3);
	prt_info("它们都是遥远世界里的存在。", 2);
	prt_info("等等...", 2);
	prt_info("说起来，今天是几号呢？", 2);
	prt_info("是几月几号，又或是几时几分？", 2);
	prt_info("时间的概念在这里似乎是很模糊的。", 3);
	prt_info("也许最合理的描述，就是“今晚”吧。", 3);
	prt_info("（坐标...）", 2);
	prt_info("没错，是坐标。", 2);
	prt_info("坐标偏移了。", 2);
	prt_info("...不明白吗？", 2);
	prt_info("我也不明白。", 2);
	prt_info("啊，话说回来。", 2);
	prt_info("这是个不错的夜晚啊...", 6);
}

static void open_screen(void)
{
	Mix_PauseMusic();
	prt_title("OP · Start:\n\n");
	play_music(bgm[PHILOSOPHYZ]);
	sleep(38);
	printf("【神户小鸟】\n");
	txt_view("呐，瑚太朗君，要多看看外面的世界哦—\n\n\n", 6);
	printf("【凤千早】\n");
	txt_view("所—以—说！我就是讨厌你这样啊！\n\n\n", 6);
	printf("【千里朱音】\n");
	txt_view("你心中的疑惑，我会完美地帮你解决。\n\n\n", 6);
	printf("【中津静流】\n");
	txt_view("结束了就会很寂寞的...所以在那之前，要一直快乐下去。\n\n\n", 6);
	printf("【此花露西娅】\n");
	txt_view("我是个...不洁的人...\n\n\n\n", 6);

	prt_title("OP · Start:");
	prt_info("和意气相投的伙伴一起度过的欢乐时光", 3);
	prt_info("在平静的岁月中", 3);
	prt_info("沉浸其中的他们还不知道", 3);
	prt_info("那是连想象，都想象不到的", 3);
	prt_info("通向真实的道路...", 6);

	prt_sub("[水谷瑠奈 - Philosophyz]");
	char_control = 1;
	char_delay = 20;
	prt_info("数亿星辰闪烁的星空，映照而出的你我，如同镜花水月", 5);
	prt_info("若能如愿以偿，比昨日向前一步", 4);
	prt_info("真正的我便能伫立这大地之上", 4);
	prt_info("你我存在于此，散于天际", 4);
	prt_info("你自始至终，在锈迹斑驳的围栏边，静静守到最后...", 9);
	prt_info("若熊熊烈火燃烧于心", 3);
	prt_info("我便能牵起回眸转身的你", 3);
	prt_info("向黑暗星辰起誓，绝对不再离开", 4);
	prt_info("将这首旋律，全部改写", 3);
	prt_info("若一腔热血能激荡在我的双臂", 3);
	prt_info("我便能牵起回眸转身的你", 3);
	prt_info("向遥远星辰起誓，绝对不再离开", 4);
	prt_info("将一切，全部改写", 19);
	char_control = 0;
}

static void txt001(void)
{
	Mix_PauseMusic();
	play_music(bgm[DISISAPAIN]);
	prt_title("         - 10月23日 周五 -");
	prt_sub("【吉野】");
	prt_info("我再也忍受不了了！", 2);
	prt_info("天王寺，和我决斗吧！", 2);
	prt_mono("我们班唯一可以称之为不良少年的家伙，吉野晴彦这样说道", 2);
	prt_sub("【瑚太朗】");
	prt_info("抱歉呐，我对卡牌游戏一点都不了解啊\n"
		 "（注：Neta《游戏王》中的 Duel 一词，天王寺的调侃）", 3);
	prt_sub("【吉野】");
	prt_info("我说的是真人快打！", 2);
	prt_mono("吉野用认真的眼神看着我", 2);
	prt_mono("别看他看起来独狼一只，平时还是很理智冷静的。", 2);
	prt_mono("所以，了解吉野用漫画和游戏中的台词来说话的人\n"
		 "出人意料的少。", 2);
	prt_mono("我则一直尽量回避着他，但最后事情还是变成了这样。", 2);
	prt_mono("我每次课间休息的时候都会很自然地找他搭话。", 2);
	prt_mono("他去洗手间的时候，我都会从后面窥视着他。", 2);
	prt_mono("对于他装酷耍帅的话，我每次都以爆笑示意友好。", 2);
	prt_mono("明明顶膝盖这样的友情表现从来没有停止过。\n"
		 "（注：偷偷绕到他人背后顶弯他人膝盖的游戏）", 2);
	prt_mono("但为什么吉野还是讨厌我呢？", 2);
	prt_mono("老实说，我真的完全不明白。", 2);
	prt_sub("【瑚太朗】");
	prt_info("真是遗憾呐，吉野", 2);
	prt_info("我可不想和亲密的伙伴发生争执。", 2);
	prt_sub("【吉野】");
	prt_info("我可没想过和你成为亲密的伙伴！", 2);
	prt_info("今天就让你用伤痛来亲身体会这点吧！", 2);
	prt_sub("【瑚太朗】");
	prt_info("看来，小子你是动真格的了。", 2);
	prt_info("明白了。我应战就是了！", 2);
	prt_sub("【吉野】");
	prt_info("放学后，校舍后面。在那里来个 The·End 吧！", 2);
	prt_sub("【瑚太朗】");
	prt_info("啊啊...但我丑话说在前面。", 2);
	prt_mono("我毫不动摇，只是冷冷地回答道。", 2);
	prt_sub("【吉野】");
	prt_info("什么？", 2);
	prt_sub("【瑚太朗】");
	prt_info("我可不是那种简简单单就被你搞定的男人。", 2);
	prt_sub("【吉野】");
	prt_info("正合我意，真想看看你哭丧着脸的样子啊。", 2);
	prt_info("时间就定在放学后。别忘了啊，混蛋！", 2);
	prt_sub("【瑚太朗】");
	prt_info("啊，明白了。", 2);
	prt_mono("这就是我和被称为“狂犬”的吉野\n"
		 "充满激情的约定。", 3);
	prt_mono("当然，这约定一回头就被我抛到了脑后", 2);
	prt_mono("放学后我就直接回家了", 2);
	prt_mono("我可是个很能敷衍了事的男人。", 2);

	play_music(bgm[MIANMAOZI]);
	prt_sub("【瑚太朗】");
	prt_info("哈哈哈哈。", 2);
	prt_mono("完全没想起约定的事", 2);
	prt_mono("一个人夜晚在家享受电视节目的乐趣。", 2);
	prt_sub("【瑚太朗】");
	prt_info("哈哈哈哈。", 2);
	prt_mono("完全没想起约定的事", 2);
	prt_mono("周六的假期在城镇里痛快地玩了一天。", 2);
	prt_mono("当我发现自己放了吉野鸽子的时候", 2);
	prt_mono("那已是夜晚的事了。", 2);
	prt_mono("当然，后悔也来不及了。", 2);
	prt_mono("下次再向吉野道歉应该就没事了吧", 2);
	prt_mono("我这么想着，倒头就睡下了。", 2);
	prt_mono("这样完全不把别人当回事的态度", 2);
	prt_mono("或许就是被吉野讨厌的原因吧。", 2);

	Mix_PauseMusic();
	sleep(1);
	prt_mono("也许是那敷衍了事活法的报应吧", 2);
	prt_mono("周日的晚上，我被某人召集了。", 2);
	prt_sub("【理香子】");
	prt_info("我的女儿小鸟到现在还没回家。", 2);
	prt_info("所以。", 2);
	prt_info("请你把她带回来吧。", 2);
	prt_mono("上下文之间完全没有联系。", 2);
	prt_mono("但...", 2);
	prt_sub("【瑚太朗】");
	prt_info("明白了。", 2);
	prt_mono("她是绝对不能拒绝的、高贵的存在。", 2);
	prt_mono("是我儿时玩伴--神户小鸟的母亲，理香子女士。", 2);
	prt_mono("因为一直都是邻居，家里与她的感情也不错", 2);
	prt_mono("所以她说的话比远房亲戚还要难推搪。", 2);
	prt_mono("话虽如此", 2);
	prt_mono("其实把迷路的女儿带回家的事，也不是头一回了。", 2);
	prt_mono("该找的地方大体上我也是知道的。", 2);
	prt_mono("整理好装备，就马上出发了。", 2);
	prt_title("未完待续 ...");
}

static inline void quit(void)
{
	Mix_PauseMusic();
	play_music(bgm[LV]);
	prt_title("8 秒后退出...");
	sleep(8);
	clr_scr();

	Mix_Quit();
	SDL_Quit();
}

void main_line(void)
{
	txt_preface();
	txt_moon_start();
	open_screen();
	txt001();

	quit();
}
