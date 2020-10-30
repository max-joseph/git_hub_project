#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
using namespace std;
int main(int argc, char **argv)
{
    if (!al_init()) {
        std::cerr << "failed to init allegro!";
        return 1;
    }
    ALLEGRO_DISPLAY* Display = al_create_display(1000, 1000);
    if (!Display) {
        std::cerr << "faild to creat display!";
        return 1;
    }
    al_clear_to_color(al_map_rgb(200, 200, 200));
    ALLEGRO_COLOR green = al_map_rgb(44, 117, 255);
    ALLEGRO_COLOR gray = al_map_rgb(0,100,0);
    
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
    
    
 
    
    
    
    
//    snake
    al_init_primitives_addon();
    al_install_keyboard();
    int x[3], y[3];
    int a = 3, b = a - 1, e = 0, c = rand() % 1000 , d = rand() % 1000;
    for (int i = 0; i < 3; i++) {
        x[i] = 450;
        y[i] = 450;
    }
    bool done = false;
    bool draw = false;
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_EVENT ev;
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    while (!done) {
        al_flip_display();
        al_draw_filled_circle(c, d, 20, gray);
        if (e % 60 == 0) {
            c = rand() % 1000;
            d = rand() % 1000;
        }
        al_draw_rectangle(0, 0, 1000, 1000, green, 15);
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_DOWN:
                    for (int i = 0; i < b; i++) {
                        x[b - i] = x[b - 1 - i];
                        y[b - i] = y[b - 1 - i];
                    }
                    y[0] = y[0] + 60;
                    break;
                case ALLEGRO_KEY_UP:
                    for (int i = 0; i < b; i++) {
                        x[b - i] = x[b - 1 - i];
                        y[b - i] = y[b - 1 - i];
                    }
                    y[0] = y[0] - 60;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    for (int i = 0; i < b; i++) {
                        x[b - i] = x[b - 1 - i];
                        y[b - i] = y[b - 1 - i];
                    }
                    x[0] = x[0] + 60;
                    break;
                case ALLEGRO_KEY_LEFT:
                    for (int i = 0; i < b; i++) {
                        x[b - i] = x[b - 1 - i];
                        y[b - i] = y[b - 1 - i];
                    }
                    x[0] = x[0] - 60;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                case ALLEGRO_KEY_SPACE:
                    draw = done;
            }
        }
        
        al_flip_display();
        al_clear_to_color(al_map_rgb(200, 200, 200));
        al_flip_display();
        if (draw == done) {
            for (int i = 0; i < 3; i++) {
                al_draw_filled_rectangle(x[i], y[i], x[i] + 50, y[i] +50, green);
            }
        }
        e++;
    }
    al_destroy_display(Display);

    
    
    
    


    

    
    
    
    return 0;
}
