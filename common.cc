/*
 * Copyright (c) 2015-2016, Andy Deng <theandy.deng@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>
using std::cout;

#include <SDL.h>
#include <SDL_mixer.h>
#include "cursor.h"
#include "music.h"
#include "print.h"
#include "time.h"

int aurora;

static Print prt;

static void txt_preface()
{
	Mix_PauseMusic();
	prt.title("            - 序言 -");
	rw_delay(4);

	play_bgm(RW_Hinagiku);
	prt.sub("【瑚太朗】");
	prt.info("有时候，我会感到自己一无所有。");
	prt.info("本以为装满了幸福的口袋，其实空空如也。");
	prt.info("因为根本就没有努力去收集过，那也是理所当然的。");
	prt.info("可是，我连这都不明白。");
	prt.info("漫不经心地虚度空无的人生。");
	prt.info("有一天，我突然察觉到自己已经浪费了很多的时间。");
	prt.info("我跟谁都能聊得开，不管那是怎样的人。");
	prt.info("可是却没有知心朋友。就连一个也没有。");
	prt.info("这意味着什么，其实根本不用去考虑。");
	prt.info("我的人生就是这么单薄。");
	prt.info("曾经只有青梅竹马的神户小鸟,\n"
		 "是不会对我说客套话的朋友。");
	prt.info("没错。");
	prt.info("...是朋友。");
	prt.info("（我要重新来过）");
	prt.info("（下次一定可以成功）");
	prt.info("我衷心祈祷着。");
	prt.info("只是，大概很难实现吧。");
	prt.info("大家都在为之忙碌奔波。");
	prt.info("幸福不会从天而降。");
	prt.info("必须靠自己的努力走向它。");
	prt.info("幸福是什么呢？");
	prt.info("像青春一样的东西吗？");
	prt.info("那青春又是什么？");
	prt.info("\"是什么光彩夺目的东西吧\"，小鸟说。");
	prt.info("\"...鬼知道，谁有功夫去想这些！\"，吉野喷道。");
	prt.info("很久以前，不知是谁说过\"人生就像在走钢丝\"的话。");
	prt.info("三人的话我都很赞同。");
	prt.info("幸福是耀眼的、未知的、令人敬畏的东西。");
	prt.info("所以幸福是难求的。因为它没有标准答案。");
	prt.info("但我还是决定踏上寻找幸福的旅途。");
	prt.info("可是，时间是残酷的。");
	prt.info("一转眼，夏天就到了。");
	prt.info("而秋天的到来也只是一瞬的事。");
	prt.info("我这才注意到，自己已经高二了。");
	prt.info("我很焦急。");
	prt.info("因为我仍旧两手空空。");
	prt.info("可是，就连接下来该做什么我都不知道。");
	prt.info("每天只是这样，虚度光阴而已...");
}

static void txt_moon_start()
{
	Mix_PauseMusic();
	prt.title("           - Moon - 月光");
	rw_delay(3);
	prt.title("           - 月光漫步 -");
	prt.sub("【瑚太朗】");
	prt.info("...这是个无法入睡的夜晚。");
	prt.info("也是无需入睡的夜晚。");
	prt.info("（为什么丝毫不觉得奇怪呢...）");
	prt.info("房间的空气，都如同化石般，异常干燥。");
	prt.info("这里，待不下去了。");
	prt.info("那就去外面吧。");
	prt.info("目的地 ?");
	prt.info("似乎早就决定过了。");
	prt.info("山丘...");
	prt.info("虽然这种想法毫无根据，但心里还是明白。");
	prt.info("即使没有任何理由，也会做出\"一定要那样做\"的判断。");
	prt.info("就好像，能预知将要发生的事情那样。");
	prt.info("未来会经历的，我事先就知道了吗？");
	prt.info("未来？");
	prt.info("在这里，也许不是一种合适的描述。");
	prt.info("“过去”，“未来”，在这儿, 就像无忧无虑的学生\n"
		 "对“战争”和“谍报活动”的认知一样。");
	prt.info("它们都是遥远世界里的存在。");
	prt.info("等等...");
	prt.info("说起来，今天是几号呢？");
	prt.info("是几月几号，又或是几时几分？");
	prt.info("时间的概念在这里似乎是很模糊的。");
	prt.info("也许最合理的描述，就是“今晚”吧。");
	prt.info("（坐标...）");
	prt.info("没错，是坐标。");
	prt.info("坐标偏移了。");
	prt.info("...不明白吗？");
	prt.info("我也不明白。");
	prt.info("啊，话说回来。");
	prt.info("这是个不错的夜晚啊...");
}

static void open_screen()
{
	Mix_PauseMusic();
	prt.title("OP · Start:\n\n");
	play_bgm(RW_Philosophyz_GSV);
	rw_delay(38);
	cout << "【神户小鸟】\n";
	prt.view("瑚太朗君，要多看看外面的世界哦—\n\n\n", 6);
	cout << "【凤千早】\n";
	prt.view("所—以—说！我就是讨厌你这样啊！\n\n\n", 6);
	cout << "【千里朱音】\n";
	prt.view("你心中的疑惑，我会完美地帮你解决。\n\n\n", 6);
	cout << "【中津静流】\n";
	prt.view("结束了就会很寂寞的...所以在那之前，要一直快乐下去。\n\n\n", 6);
	cout << "【此花露西娅】\n";
	prt.view("我是个...不洁的人...\n\n\n\n", 6);

	prt.title("OP · Start:");
	prt.info("和意气相投的伙伴一起度过的欢乐时光", 3);
	prt.info("在平静的岁月中", 3);
	prt.info("沉浸其中的他们还不知道", 3);
	prt.info("那是连想象，都想象不到的", 3);
	prt.info("通向真实的道路...", 6);

	prt.sub("[水谷瑠奈 - Philosophyz]");
	prt.info("数亿星辰闪烁的星空，映照而出的你我，如同镜花水月", 5);
	prt.info("若能如愿以偿，比昨日向前一步", 4);
	prt.info("真正的我便能伫立这大地之上", 4);
	prt.info("你我存在于此，散于天际", 4);
	prt.info("你自始至终，在锈迹斑驳的围栏边，静静守到最后...", 9);
	prt.info("若熊熊烈火燃烧于心", 3);
	prt.info("我便能牵起回眸转身的你", 3);
	prt.info("向黑暗星辰起誓，绝对不再离开", 4);
	prt.info("将这首旋律，全部改写", 3);
	prt.info("若一腔热血能激荡在我的双臂", 3);
	prt.info("我便能牵起回眸转身的你", 3);
	prt.info("向遥远星辰起誓，绝对不再离开", 4);
	prt.info("将一切，全部改写", 19);
}

static void txt001()
{
	Mix_PauseMusic();
	play_bgm(RW_DIS_is_a_Pain);
	prt.title("         - 10月23日 周五 -");
	prt.sub("【吉野】");
	prt.info("我再也忍受不了了！");
	prt.info("天王寺，和我决斗吧！");
	prt.mono("我们班唯一可以称之为不良少年的家伙，吉野晴彦这样说道");
	prt.sub("【瑚太朗】");
	prt.info("抱歉呐，我对卡牌游戏一点都不了解啊\n"
		 "（注：Neta《游戏王》中的 Duel 一词，天王寺的调侃）");
	prt.sub("【吉野】");
	prt.info("我说的是真人快打！");
	prt.mono("吉野用认真的眼神看着我");
	prt.mono("别看他看起来独狼一只，平时还是很理智冷静的。");
	prt.mono("所以，了解吉野用漫画和游戏中的台词来说话的人\n"
		 "出人意料的少。");
	prt.mono("我则一直尽量回避着他，但最后事情还是变成了这样。");
	prt.mono("我每次课间休息的时候都会很自然地找他搭话。");
	prt.mono("他去洗手间的时候，我都会从后面窥视着他。");
	prt.mono("对于他装酷耍帅的话，我每次都以爆笑示意友好。");
	prt.mono("明明顶膝盖这样的友情表现从来没有停止过。\n"
		 "（注：偷偷绕到他人背后顶弯他人膝盖的游戏）");
	prt.mono("但为什么吉野还是讨厌我呢？");
	prt.mono("老实说，我真的完全不明白。");
	prt.sub("【瑚太朗】");
	prt.info("真是遗憾呐，吉野");
	prt.info("我可不想和亲密的伙伴发生争执。");
	prt.sub("【吉野】");
	prt.info("我可没想过和你成为亲密的伙伴！");
	prt.info("今天就让你用伤痛来亲身体会这点吧！");
	prt.sub("【瑚太朗】");
	prt.info("看来，小子你是动真格的了。");
	prt.info("明白了。我应战就是了！");
	prt.sub("【吉野】");
	prt.info("放学后，校舍后面。在那里来个 The·End 吧！");
	prt.sub("【瑚太朗】");
	prt.info("啊啊...但我丑话说在前面。");
	prt.mono("我毫不动摇，只是冷冷地回答道。");
	prt.sub("【吉野】");
	prt.info("什么？");
	prt.sub("【瑚太朗】");
	prt.info("我可不是那种简简单单就被你搞定的男人。");
	prt.sub("【吉野】");
	prt.info("正合我意，真想看看你哭丧着脸的样子啊。");
	prt.info("时间就定在放学后。别忘了啊，混蛋！");
	prt.sub("【瑚太朗】");
	prt.info("啊，明白了。");
	prt.mono("这就是我和被称为“狂犬”的吉野\n"
		 "充满激情的约定。");
	prt.mono("当然，这约定一回头就被我抛到了脑后");
	prt.mono("放学后我就直接回家了");
	prt.mono("我可是个很能敷衍了事的男人。");

	play_bgm(RW_Wataboshi);
	prt.sub("【瑚太朗】");
	prt.info("哈哈哈哈。");
	prt.mono("完全没想起约定的事");
	prt.mono("一个人夜晚在家享受电视节目的乐趣。");
	prt.sub("【瑚太朗】");
	prt.info("哈哈哈哈。");
	prt.mono("完全没想起约定的事");
	prt.mono("周六的假期在城镇里痛快地玩了一天。");
	prt.mono("当我发现自己放了吉野鸽子的时候");
	prt.mono("那已是夜晚的事了。");
	prt.mono("当然，后悔也来不及了。");
	prt.mono("下次再向吉野道歉应该就没事了吧");
	prt.mono("我这么想着，倒头就睡下了。");
	prt.mono("这样完全不把别人当回事的态度");
	prt.mono("或许就是被吉野讨厌的原因吧。");

	Mix_PauseMusic();
	rw_delay(1);
	prt.mono("也许是那敷衍了事活法的报应吧");
	prt.mono("周日的晚上，我被某人召集了。");
	prt.sub("【理香子】");
	prt.info("我的女儿小鸟到现在还没回家。");
	prt.info("所以。");
	prt.info("请你把她带回来吧。");
	prt.mono("上下文之间完全没有联系。");
	prt.mono("但...");
	prt.sub("【瑚太朗】");
	prt.info("明白了。");
	prt.mono("她是绝对不能拒绝的、高贵的存在。");
	prt.mono("是我儿时玩伴--神户小鸟的母亲，理香子女士。");
	prt.mono("因为一直都是邻居，家里与她的感情也不错");
	prt.mono("所以她说的话比远房亲戚还要难推搪。");
	prt.mono("话虽如此");
	prt.mono("其实把迷路的女儿带回家的事，也不是头一回了。");
	prt.mono("该找的地方大体上我也是知道的。");
	prt.mono("整理好装备，就马上出发了。");
	prt.title("未完待续 ...");
}

static void quit()
{
	Mix_PauseMusic();
	play_bgm(RW_Tabi);
	prt.title("8 秒后退出...");
	rw_delay(8);
	clscr();

	Mix_Quit();
	SDL_Quit();
}

void main_line()
{
	txt_preface();
	txt_moon_start();
	open_screen();
	txt001();

	quit();
}
