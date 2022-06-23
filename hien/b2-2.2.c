#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point
{
	double x;
	double y;
} point_t;

typedef struct circle
{
	point_t center;
	double radius;
} circle_t;

int is_in_circle(point_t p, circle_t c)
{
	double kcach=sqrt(pow(p.x, 2)-pow((c.center).x, 2)+(pow(p.y, 2)-pow((c.center).y, 2)));
	if(kcach<c.radius)
	{
		return 1;
	}
}

int main()
{
	point_t p;
	printf("Nhap diem p(x, y) = \n");
	scanf("%lf%*c", &p.x);
	scanf("%lf%*c", &p.y);
	circle_t c;
	printf("Nhap O va r cua duong tron c: \n");
	scanf("%lf%*c", &(c.center).x);
	scanf("%lf%*c", &(c.center).y);
	scanf("%lf%*c", &c.radius);
	if(is_in_circle(p, c)==1)
	{
		printf("diem p nam trong c\n");
	}
	else
	{
		printf("diem p khong nam trong c\n");
	}
}
