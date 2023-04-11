#include <stdio.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int main() 
{
    int player_x = 1;
    int player_y = 1;
    double player_angle = 0;

    int screen_width = 120;
    int screen_height = 40;

    for (int y = 0; y < screen_height; y++) {
        double angle = player_angle - atan((y - screen_height / 2) / screen_height * 2);
        double distance_to_wall = 0;
        int hit_wall = 0;
        int wall_x = 0;
        int wall_y = 0;

        double x_step = cos(angle);
        double y_step = sin(angle);

        double x = player_x;
        double y = player_y;

        while (!hit_wall && distance_to_wall < 10) {
            int map_x = (int)x;
            int map_y = (int)y;

            if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT) {
                hit_wall = 1;
                distance_to_wall = 10;
            } else if (map[map_x][map_y]) {
                hit_wall = 1;
                wall_x = map_x;
                wall_y = map_y;
                distance_to_wall = sqrt(pow(x - player_x, 2) + pow(y - player_y, 2));
            }

            x += x_step;
            y += y_step;
        }

        int ceiling_height = screen_height / 2 - screen_height / distance_to_wall;
        int floor_height =  screen_height - ceiling_height;
    for (int x = 0; x < screen_width; x++) {
        if (y == screen_height / 2 && x == screen_width / 2) {
            putchar('P');
        } else if (y < ceiling_height) {
            putchar(' ');
        } else if (y >= ceiling_height && y < ceiling_height + 1) {
            putchar('#');
        } else if (y >= ceiling_height + 1 && y < floor_height) {
            if (x == wall_x && y == wall_y) {
                putchar('X');
            } else {
                putchar('.');
            }
        } else {
            putchar(' ');
        }
    }

    putchar('\n');
}

return 0;
}