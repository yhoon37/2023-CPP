#include "shape.h"
#include <iostream>

int main() {
    bool isQuit = false;
    while(!isQuit){
        std::string command;
        std::cin >> command;
        if(command == "RECT"){
            int x1, x2, y1, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            Point pos1 = {x1, y1};
            Point pos2 = {x2, y2};
            create_rectangle(pos1, pos2);
        }
        else if(command == "CIRCLE"){
            int x1, y1, radius;
            std::cin >> x1 >> y1 >> radius;
            Point pos = {x1, y1};
            create_circle(pos, radius);
        }
        else if(command == "QUIT"){
            isQuit = true;
        }
        else if(command == "MOVE"){
            int id, x, y;
            std::cin >> id >> x >> y;
            move_shape(id, x, y);
        }
        else if(command == "SORT"){
            sort_shapes();
        }
        else if(command == "MAX"){
            find_furthest_shape();
        }
        else if(command == "REMOVE"){
            int id;
            std::cin >> id;
            remove_shape_by_id(id);
        }
        else if(command == "ALIGN"){
            align_shapes();
        }
        else if(command == "PRINT"){
            print_shapes();
        }
        else{
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}
