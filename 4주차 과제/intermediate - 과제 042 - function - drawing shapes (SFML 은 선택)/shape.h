const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

enum class ShapeType{
    RECT,
    CIRCLE
};

struct Point{
    int x;
    int y;
};

struct Shape{
    int id;
    ShapeType type;
    Point pos1;
    Point pos2;
    Point center;
    int radius;
};

double CalArea(Shape& a);
bool compare_sort(Shape& a, Shape& b);
double CalCenterLen(Shape& a);
bool compare_max(Shape& a, Shape& b);
void create_rectangle(Point& pos1, Point& pos2);
void create_circle(Point& center, int radius);
void move_shape(int id, int x, int y);
void move_xy_shape(int id, int x, int y);
void sort_shapes();
int find_furthest_shape();
void remove_shape_by_id(int id);
bool is_overlap(Shape& shape, Shape& pre_shape);
void align_shapes();
void print_shape(Shape& it);
void print_shapes();