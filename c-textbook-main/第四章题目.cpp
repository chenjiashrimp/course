#include<iostream>
#include<cmath>
using namespace std;
int eat() {
	int A_say, B_say, C_say = 0;
	for (int A = 0;A < 3;A++)
		for (int B = 0;B < 3;B++)
			for (int C = 0;C < 3;C++) {
				A_say = (B > A) + (C == A);
				B_say = (A > B) + (A > C);
				C_say = (C > B) + (B > A);
				if ((B - A == A_say - B_say) && (B - C == C_say - B_say) && (C - A == A_say - C_say))
					for (int k = 2;k >= 0;k--) {
						if (A == k)
							cout << 'A' << " ";
						if (B == k)
							cout << 'B' << " ";
						if (C == k)
							cout << 'C' << " ";
					}

			}
	return 0;
}
int car() {
	int best_car = 0;
	for (best_car = 1;best_car <= 4;best_car++) {
		int sum = (best_car == 2) + (best_car == 4) + (best_car != 3) + (best_car != 4);
		if (sum == 1)
			cout << best_car << endl;
	}
	return 0;
}
int diving() {
	for(int A=1;A<=5;A++)
		for(int B=1;B<=5;B++)
			if(B!=A)
				for(int C=1;C<=5;C++)
					if(C!=A&&C!=B)
						for(int D=1;D<=5;D++)
							if(D!=C&&D!=B&&D!=A)
								for(int E=1;E<=5;E++)
									if (E != D && E != C && E != B && E != A) {
										int A_say = (B == 2) + (A == 3);
										int B_say = (B == 2) + (E == 4);
										int C_say = (C == 1) + (D == 2);
										int D_say = (C == 5) + (D == 3);
										int E_say = (E == 4) + (A == 1);
										if (A_say == 1 && B_say == 1 && C_say == 1 && D_say == 1 && E_say == 1) 
											for (int i = 1;i <= 5;i++) {
												if (A == i)
													cout << 'A' << " ";
												if (B == i)
													cout << 'B' << " ";
												if (C == i)
													cout << 'C' << " ";
												if (D == i)
													cout << 'D' << " ";
												if (E == i)
													cout << 'E' << " ";
											}
									}
	return 0;
}
int lake() {
	for(int hongze=1;hongze<=4;hongze++)
		for(int dongting=1;dongting<=4;dongting++)
			if(dongting!=hongze)
				for(int boyang=1;boyang<=4;boyang++)
					if(boyang!=dongting&&boyang!=hongze)
						for(int tai=1;tai<=4;tai++)
							if (tai != boyang && tai != dongting && tai != hongze) {
								int A_say = (dongting == 1) + (hongze == 4) + (boyang == 3);
								int B_say = (hongze == 1) + (dongting == 4) + (boyang == 2) + (tai == 3);
								int C_say = (hongze == 4) + (dongting == 3);
								int D_say = (boyang == 1) + (tai == 4) + (hongze == 2) + (dongting == 3);
								if(A_say==1&&B_say==1&&C_say==1&&D_say==1)
									for (int i = 1;i <= 4;i++) {
										if (dongting == i)
											cout << "洞庭湖" << " ";
										if (hongze == i)
											cout << "洪泽湖" << " ";
										if (boyang == i)
											cout << "鄱阳湖" << " ";
										if (tai == i)
											cout << "太湖" << " ";
									}
							}
	return 0;
}
int teacher() {
	for(int chinese=1;chinese<=3;chinese++)
		for(int math=1;math<=3;math++)
			for(int politics=1;politics<=3;politics++)
					for(int geography=1;geography<=3;geography++)
						for(int music=1;music<=3;music++)
							for (int art = 1;art <= 3;art++)
								if (chinese + math + geography + politics + music + art == 12) 
									if (politics != math && geography != chinese && geography != 2 && geography != 1  &&math!=1&& geography != math && music != 2 && chinese != 2 && music != chinese) {
											for (int i = 1;i <= 3;i++) {
												if (chinese == i)
													cout <<"语文"<< " ";
												if (math == i)
													cout << "算术" << " ";
												if (geography == i)
													cout << "地理" << " ";
												if (politics == i)
													cout << "政治" << " ";
												if (music == i)
													cout << "音乐" << " ";
												if (art == i)
													cout << "美术" << " ";
												cout << endl;
											}
									}
	return 0;
}
int sports() {
	for(int meter_100=0;meter_100<5;meter_100++)
		for(int meter_400=0;meter_400<5;meter_400++)
			if(meter_400!=meter_100)
				for(int jump_high=0;jump_high<5;jump_high++)
					if(jump_high!=meter_400&&jump_high!=meter_100)
						for(int jump_long=0;jump_long<5;jump_long++)
							if(jump_long!=jump_high&&jump_long!=meter_400&&jump_long!=meter_100)
								for(int triple_jump=0;triple_jump<5;triple_jump++)
									if (triple_jump != jump_long && triple_jump != jump_high && triple_jump != meter_400 && triple_jump != meter_100) {
										int say1 = (triple_jump == 1) + (jump_high == 3);
										int say2 = (meter_100 == 0) + (jump_high == 4);
										int say3 = (jump_long == 2) + (meter_400 == 3);
										int say4 = (jump_high == 1) + (triple_jump == 4);
										if (say1 == 1 && say2 == 1 && say3 == 1 && say4 == 1) {
											for (int i = 0;i < 5;i++) {
												if (meter_100 == i)
													cout << char('A' + i) << " " << "一百米";
												if (meter_400 == i)
													cout << char('A' + i) << " " << "四百米";
												if (jump_high == i)
													cout << char('A' + i) << " " << "跳高";
												if (jump_long == i)
													cout << char('A' + i) << " " << "跳远";
												if (triple_jump == i)
													cout << char('A' + i) << " " << "三级跳";
												cout << endl;
											}
										}
									}
	return 0;
}
int factory() {
	for(int A=1;A<=5;A++)
		for(int B=1;B<=5;B++)
			if(B!=A)
				for(int C=1;C<=5;C++)
					if(C!=B&&C!=A)
						for(int D=1;D<=5;D++)
							if(D!=C&&D!=B&&D!=A)
								for(int E=1;E<=5;E++)
									if(E!=D&&E!=C&&E!=B&&E!=A)
										if (E != 2 && E != 3) {
											int A_guess = (E == 1);
											int B_guess = (B == 2);
											int C_guess = (A == 5);
											int D_guess = (C != 1);
											int E_guess = (D == 1);
											if(A_guess+B_guess+C_guess+D_guess+E_guess==2)
												if(A-A_guess==0||B-B_guess==0||C-C_guess==0||D-D_guess==0||E-E_guess==0)
													if (A - A_guess == 1 || B - B_guess == 1 || C - C_guess == 1 || D - D_guess == 1 || E - E_guess == 1)
														for (int i = 1;i <= 5;i++) {
															if (A == i)
																cout << 'A' << " ";
															if (B == i)
																cout << 'B' << " ";
															if (C == i)
																cout << 'C' << " ";
															if (D == i)
																cout << 'D' << " ";
															if (E == i)
																cout << 'E' << " ";
														}
										}
	return 0;
}
int main() {
	car();
	eat();
	cout << endl;
	diving();
	cout << endl;
	lake();
	cout << endl;
	teacher();
	cout << endl;
	sports();
	cout << endl;
	factory();
}
