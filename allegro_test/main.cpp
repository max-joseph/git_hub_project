#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
using namespace std;

int arai(int x[100], int a){
    for (int i = 0; i < 100; i++) {
        x[i] = a;
    }
    return 0;
}
struct Coordinates{
    int x, y;
    
};
struct Movement{
    int x, y;
    Movement(int x, int y){
        this-> x = x;
        this-> y = y;
    }
};
int main(int argc, char **argv)
{
    if (!al_init()) {
        std::cerr << "failed to init allegro!";
        return 1;
    }
    int screenSize;
    cout << " enter screenSize" << endl;
    cin >> screenSize;
    ALLEGRO_DISPLAY* Display = al_create_display(screenSize, screenSize);
    if (!Display) {
        std::cerr << "faild to creat display!";
        return 1;
    }
    al_clear_to_color(al_map_rgb(200, 200, 200));
    ALLEGRO_COLOR blue = al_map_rgb(44, 117, 255);
    ALLEGRO_COLOR red = al_map_rgb(0,50,0);
    
    
  
    al_init_primitives_addon();
    al_install_keyboard();

    Coordinates cordinates[100];
    for(int i=0; i<sizeof(cordinates);i++){
        cordinates[i].x=0;
        cordinates[i].y=0;
    }
    int x[100], y[100];
    int body = 3, timer = 0, xPoint = rand() % 990, yPoint = rand() % 990;
    int snakeSize;
    cout << "enter snakeSize" << endl;
    cin >> snakeSize;
    arai(x, 450);
    arai(y, 450);
    bool done = false;
    bool draw = false;
    Movement lastMove = Movement(0,0);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_EVENT ev;
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    while (!done) {
        al_flip_display();
        al_draw_filled_circle(xPoint, yPoint, 20, red);
        if (timer % 30 == 0) {
            xPoint = rand() % (screenSize - 20);
            yPoint = rand() % (screenSize - 20);
        }
        al_draw_rectangle(0, 0, screenSize, screenSize, blue, 10);
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_DOWN:
                    for (int i = 0; i < body - 1; i++) {
                        x[body - 1 - i] = x[body - 2 - i];
                        y[body - 1 - i] = y[body - 2 - i];
                    }
                    y[0] = y[0] + 35;
                    lastMove = Movement(0,snakeSize + 5);
                    break;
                case ALLEGRO_KEY_UP:
                    for (int i = 0; i < body - 1; i++) {
                        x[body - 1 - i] = x[body - 2 - i];
                        y[body - 1 - i] = y[body - 2 - i];
                    }
                    y[0] = y[0] - 35;
                    lastMove = Movement(0,-snakeSize + 5);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    for (int i = 0; i < body - 1; i++) {
                        x[body - 1 - i] = x[body - 2 - i];
                        y[body - 1 - i] = y[body - 2 - i];
                    }
                    x[0] = x[0] + 35;
                    lastMove = Movement(snakeSize + 5,0);
                    break;
                case ALLEGRO_KEY_LEFT:
                    for (int i = 0; i < body - 1; i++) {
                        x[body - 1 - i] = x[body - 2 - i];
                        y[body - 1 - i] = y[body - 2 - i];
                    }
                    x[0] = x[0] - 35;
                    lastMove = Movement(-snakeSize + 5,0);
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                case ALLEGRO_KEY_SPACE:
                    draw = done;
            }
        }
        for (int i = 0; i < body - 1; i++) {
            x[body - 1 - i] = x[body - 2 - i];
            y[body - 1 - i] = y[body - 2 - i];
        }
        x[0] = x[0] + lastMove.x;
        y[0] = y[0] + lastMove.y;
        timer++;
        al_flip_display();
        al_clear_to_color(al_map_rgb(200, 200, 200));
        al_flip_display();
        if (draw == done) {
            for (int i = 0; i < 3; i++) {
                al_draw_filled_rectangle(x[i], y[i], x[i] + snakeSize, y[i] + snakeSize, blue);
            }
        }
    }
    


    


    al_flip_display();
    al_rest(3.00);
    al_destroy_display(Display);
    return 0;
}




























//    rosh bezani sabz she
//    for (int i = 0; i <= 10; i++) {
//        for (int j = 0; j <= 10; j++) {
//            al_draw_rectangle(j*100, j*100, i*100, i*100, green, 5);
//        }
//    }
//    al_init_primitives_addon();
//    al_install_mouse();
//    int x, y, a, b;
//    bool done = false;
//    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
//    al_register_event_source(event_queue, al_get_display_event_source(Display));
//    al_register_event_source(event_queue, al_get_mouse_event_source());
//    al_flip_display();
//    while (!done) {
//        ALLEGRO_EVENT ev;
//        al_wait_for_event(event_queue, &ev);
//        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
//                    done = true;
//        }
//        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
//            if(ev.mouse.button & 1){
//                x = ev.mouse.x;
//                y = ev.mouse.y;
//                a = x/100;
//                b = y/100;
//                al_flip_display();
//                al_draw_filled_rectangle(a*100, b*100, (a+1)*100, (b+1)*100, gray);
//                al_flip_display();
//            }
//           else  if (ev.mouse.button & 2) {
//                done = true;
//            }
//        }
//
//    }
 
    
    
    
//    shansi
//    for (int i = 0; i <= 10; i++) {
//        for (int j = 0; j <= 10; j++) {
//            al_draw_rectangle(j*100, j*100, i*100, i*100, green, 5);
//        }
//    }
//    al_init_primitives_addon();
//    al_install_mouse();
//    int x, y , a, b, c, d;
//    c = rand()%1001;
//    d = rand()%1001;
//    c = c/100;
//    d = d/100;
//    bool done = false;
//    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
//    al_register_event_source(event_queue, al_get_display_event_source(Display));
//    al_register_event_source(event_queue, al_get_mouse_event_source());
//    al_flip_display();
//    while (!done) {
//        ALLEGRO_EVENT ev;
//        al_wait_for_event(event_queue, &ev);
//        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//            done = true;
//        }
//        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
//            if (ev.mouse.button & 1) {
//                x = ev.mouse.x;
//                y = ev.mouse.y;
//                a = x/100;
//                b = y/100;
//                al_flip_display();
//                al_draw_filled_rectangle(a*100, b*100, (a+1)*100, (b+1)*100, al_map_rgb(250, 0, 0));
//                al_flip_display();
//                if (a == c){
//                    if (b == d) {
//                        al_flip_display();
//                        al_draw_filled_rectangle(a*100, b*100, (a+1)*100, (b+1)*100, gray);
//                        al_flip_display();
//                    }
//                }
//            }
//        }
//        else  if (ev.mouse.button & 2) {
//            done = true;
//        }
//        }
    
