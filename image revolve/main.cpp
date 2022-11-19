#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define dist(x1,y1,x2,y2) sqrt(pow(x1-x2,2)+pow(y1-y2,2))
int main(int arg, char** args)
{
	if (arg != 10)
	{
		cout << "正确格式:rimg2mcfunction [图片地址] [函数地址] [像素间距] [背景颜色位置] [原点横坐标] [原点纵坐标] [r] [g] [b]";
		return 0;
	}
	IMAGE img;
	loadimage(&img, args[1]);
	DWORD* d = GetImageBuffer(&img);
	DWORD(*buffer)[5000] = new DWORD[5000][5000];
	for (int i = 0, sum = 0; i < img.getheight(); i++)
		for (int j = 0; j < img.getwidth(); j++, sum++)
			buffer[i][j] = d[sum];
	int bx = atoi(args[5]), by = atoi(args[6]),bkc = atoi(args[4]);
	putimage(0, 0, &img);
	freopen(args[2], "w", stdout);
	for (int x = 0; x < img.getwidth(); x++)
		for (int y = 0; y < img.getheight(); y++)
		{
			if (buffer[y][x] == d[bkc])
				continue;
			double r = dist(x, y, bx, by),rx=bx-r, ry=by;
			double crd = dist(rx, ry, x, y);
			double sc = crd / 2 / r;
			double angle = asin(sc)*180/acos(-1) * 2;
			if (y > by)
				angle = 360 - angle;
			double asc = angle / 360;
			//cout << "particleex tickparameter minecraft:end_rod ~ ~ ~ 1 1 1 1 0 0 0 -5.0 50.0 \"x = sin(t+" << setprecision(3) << asc << ")*" << setprecision(3) << r << "; z = cos(t+" << setprecision(3) << asc << ")*" << setprecision(3) << r << "\" 0.1 1 1" << endl;
			//printf("particleex tickparameter minecraft:end_rod ~ ~ ~ 1 1 1 1 0 0 0 -5.0 50.0 \"x = sin(t+%.3llf)*%.3llf; z = cos(t+%.3llf)*%.3llf\" 0.1 1 1\n", asc*2*acos(-1), r*atof(args[3]), asc * 2 * acos(-1), r * atof(args[3]));
			//printf("particleex rgbatickparameter minecraft:end_rod ~ ~ ~ 1 1 1 -5.0 50.0 \"x = sin(t+%.3llf)*%.3llf; z = cos(t+%.3llf)*%.3llf;cr=%d;cg=%d;cb=%d\" 0.1 1 1\n", asc * 2 * acos(-1), r * atof(args[3]), asc * 2 * acos(-1), r * atof(args[3]),atoi(args[7]),atoi(args[8]), atoi(args[9]));
			printf("particleex rgbatickparameter minecraft:end_rod ~ ~ ~ 1 1 1 -5.0 50.0 \"x = sin(t+%.3llf)*%.3llf; y = cos(t+%.3llf)*%.3llf;cr=%d;cg=%d;cb=%d\" 0.1 1 1\n", asc * 2 * acos(-1), r * atof(args[3]), asc * 2 * acos(-1), r * atof(args[3]), atoi(args[7]), atoi(args[8]), atoi(args[9]));
		}
	return 0;
}
//particleex tickparameter minecraft:end_rod ~ ~ ~ 1 1 1 1 0 0 0 -5.0 50.0 "x=sin(t);z=cos(t)" 0.1 1 1
///particleex rgbatickparameter minecraft:end_rod ~ ~ ~ 1 1 1 -5 50 "x = sin(t+0.197)*7.139; z = cos(t+0.197)*7.139;cr=0;cg=0;cb=0" 0.1 1 1