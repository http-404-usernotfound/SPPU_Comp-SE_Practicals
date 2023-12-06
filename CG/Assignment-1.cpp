#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class polygon{
	int d = 5;
  public:
	void DDA_line(float x1, float y1, float x2, float y2);
	void Bres_circle(int r, int stx, int sty);
};
void polygon::DDA_line(float x1, float y1, float x2, float y2){
	float xn = x1, yn = y1;
	float m = ((y2-y1)/(x2-x1));
	cout<<"M = "<<m<<endl;
	if(abs(m)<=1){
		cout<<"M <= 1\n";
		while(xn<x2){
			putpixel(xn, floor(yn), WHITE);
			delay(d);
			xn += 1;
			yn += m;
			cout<<"X: "<<xn<<", Y: "<<yn<<endl;
		}
	}
	
	if(abs(m) > 1){
		cout<<"M > 1\n";
		while(yn < y2){
			putpixel(floor(xn), yn, WHITE);
			
			delay(d);
			yn += 1;
			xn += (1/m);
			cout<<"X: "<<xn<<", Y: "<<yn<<endl;
		}
	}
}

void polygon::Bres_circle(int r, int cx, int cy){
	int d = 3-2*r;
	int x = 0, y = r;
	for(int i = 0; i < 8; i++)
		do{
			delay(polygon::d);
			putpixel(cx+x, cy+y, WHITE);
			putpixel(cx-x, cy+y, WHITE);
			putpixel(cx-x, cy-y, WHITE);
			putpixel(cx+x, cy-y, WHITE);
			putpixel(cx+y, cy+x, WHITE);
			putpixel(cx+y, cy-x, WHITE);
			putpixel(cx-y, cy-x, WHITE);
			putpixel(cx-y, cy+x, WHITE);
			
			if(d<0) d = d+4*x+6;
			
			else{
				d = d+4*(x-y)+10;
				y -= 1;
			}
			x += 1;
		} while(x < abs(y-10));
}

int main(){
	int gm, gd = DETECT;
	initgraph(&gd, &gm, NULL);
	
	polygon triangle, inner_circle, outer_circle;
	
	outer_circle.Bres_circle(111, 300, 250);
	triangle.DDA_line(200, 300, 400, 300);
	triangle.DDA_line(300, 140, 200, 300);
	triangle.DDA_line(300, 140, 400, 300);
	inner_circle.Bres_circle(55, 300, 245);
	
	delay(5000);
	closegraph();
	return 0;
}
