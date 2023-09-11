#include "shape.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

std::vector<Shape> shape_list;
int next_id = 0;

double CalArea(Shape& a){
    double area = 0;
    if(a.type == ShapeType::RECT){
        area = (a.pos2.x - a.pos1.x) * (a.pos2.y - a.pos1.y);
    }
    else if(a.type == ShapeType::CIRCLE){
        area = M_PI * a.radius * a.radius;
    }
    return area;
}

bool compare_sort(Shape& a, Shape& b){
    return CalArea(a) < CalArea(b);
}

double CalCenterLen(Shape& a){
    return sqrt(pow(a.center.x, 2) + pow(a.center.y, 2));
}

bool compare_max(Shape& a, Shape& b){
    return CalCenterLen(a) > CalCenterLen(b);
}

void create_rectangle(Point& pos1, Point& pos2){
    Shape rectangle;
    rectangle.id = next_id++;
    rectangle.type = ShapeType::RECT;
    rectangle.pos1 = pos1;
    rectangle.pos2 = pos2;
    rectangle.center.x = (pos1.x + pos2.x)/2;
    rectangle.center.y = (pos1.y + pos2.y)/2;
    rectangle.radius = 0;
    shape_list.push_back(rectangle);
}

void create_circle(Point& center, int radius){
    Shape circle;
    circle.id = next_id++;
    circle.type = ShapeType::CIRCLE;
    circle.pos1.x = center.x - radius;
    circle.pos1.y = center.y - radius;
    circle.pos2.x = center.x + radius;
    circle.pos2.y = center.y + radius;
    circle.center = center;
    circle.radius = radius;
    shape_list.push_back(circle);
}

void move_shape(int id, int x, int y){
    for(auto& shape: shape_list){
        if(shape.id == id){
            shape.center.x += x;
            shape.center.y += y;
            shape.pos1.x += x;
            shape.pos1.y += y;
            shape.pos2.x += x;
            shape.pos2.y += y;
        }
    }
}

void move_xy_shape(int id, int x, int y){//중심을 (x,y) 로 이동
    for(auto& shape: shape_list){
        if(shape.id == id){
            int width, height;
            width = shape.pos2.x - shape.pos1.x;
            height = shape.pos2.y - shape.pos1.y;
            shape.center.x = x;
            shape.center.y = y;
            shape.pos1.x = shape.center.x - width/2;
            shape.pos1.y = shape.center.y - height/2;
            shape.pos2.x = shape.center.x + width/2;
            shape.pos2.y = shape.center.y + height/2;
        }
    }
}

void sort_shapes(){
    std::sort(shape_list.begin(), shape_list.end(), compare_sort);
}

int find_furthest_shape(){
    auto max = std::max_element(shape_list.begin(), shape_list.end(), compare_max);
    print_shape(*max);
}

void remove_shape_by_id(int id){
    shape_list.erase(std::remove_if(shape_list.begin(), shape_list.end(), [id](Shape a){
        return a.id == id;
    }), shape_list.end());
}

bool is_overlap(Shape& shape, Shape& pre_shape){
    bool result;
    if((pre_shape.pos2.x > shape.pos1.x) && (pre_shape.pos2.y > shape.pos1.y)){
        result = true;
    }
    else{
        result = false;
    }
    return result;
}

void align_shapes(){
    sort_shapes();
    for(auto& shape: shape_list){
        static Shape pre_shape= shape;  //값 복사?
        if(shape.id == pre_shape.id){
            move_xy_shape(shape.id, 0, 0);
            int min = std::min(shape.pos1.x, shape.pos1.y);
            move_shape(shape.id, abs(min), abs(min));
        }
        else{
            move_xy_shape(shape.id, pre_shape.center.x, pre_shape.center.y);
            while(is_overlap(shape, pre_shape)){
                move_shape(shape.id, 1, 1);
            }
            if((shape.pos1.x < 0) || (shape.pos1.y < 0)){
                int min = std::min(shape.pos1.x, shape.pos1.y);
                move_shape(shape.id, abs(min), abs(min));
            }
        }
        pre_shape = shape;
    }
}

void print_shape(Shape& shape){
    std::cout << std::fixed << std::setprecision(2) ;
    if(shape.type == ShapeType::CIRCLE){
        double area;
        area = CalArea(shape);                 //CIRCLE 대신에 it.type을 이용할 방법은 없나?
        std::cout << "ID: " <<shape.id << ", Type: CIRCLE, Center: (" <<shape.center.x << ", " <<shape.center.y
                  << "), Radius: " <<shape.radius << ", Area: " << area << std::endl;
    }
    else{
        int width, height;
        double area;
        width =shape.pos2.x -shape.pos1.x;
        height =shape.pos2.y -shape.pos1.y;
        area = CalArea(shape);
        std::cout << "ID: " << shape.id << ", Type: RECT, Position: (" <<shape.center.x << ", " <<shape.center.y
                  << "), Width: " << width << ", Height: " << height << ", Area: " << area << std::endl;
    }
}

void print_shapes(){
    for(auto& shape: shape_list){
        print_shape(shape);
    }
}