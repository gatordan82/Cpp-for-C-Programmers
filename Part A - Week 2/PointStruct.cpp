typedef struct Point
{
	double x, y;
} Point;

void add_points(Point* p1, Point* p2, Point* sum)
{
	sum->x = p1->x + p2->x;
	sum->y = p1->y + p2->y;
}