#include <iostream>
#include "bug.h"
#include<FL/Fl_PNG_Image.H>

static Bug bug;
static Fl_PNG_Image d("dog.png");
static Fl_PNG_Image d1("dog1.png");
static Fl_PNG_Image d2("dog2.png");
static Fl_PNG_Image d3("dog3.png");
static Fl_PNG_Image* bugs[DIRECTIONS] = {&d,&d1,&d2,&d3};
static char path[]= "mmmmtmmmmtmmmmtmmmm";
static const int P = sizeof(path);

Fl_Box *b=(Fl_Box *)0;

static void cb_move(Fl_Button*, void*) {
  bug.move_one_unit();
b->position(bug.get_column(),bug.get_row());
b->parent()->redraw();
}

static void cb_turn(Fl_Button*, void*) {
  bug.turn_right();
static int i = EAST;
i = (i + 1) % DIRECTIONS;
b->image(bugs[i]);
b->redraw();
}

static void cb_Path(Fl_Return_Button* o, void*) {
  std::cout << "Path button pushed" << std::endl;

static int i = 0;
switch (path[i])
{
        case 'm': cb_move(o,0); break;
        case 't': cb_turn(o,0); break;
};
i = (i+1) % P;
}

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { // window to contain buttons and box with bug image
    Fl_Double_Window* o = new Fl_Double_Window(350, 270, "Bug ");
    w = o; if (w) {/* empty */}
    { // box to hold image of bug
      b = new Fl_Box(30, 30, 50, 50);
      b->image(&d);
    } // Fl_Box* b
    { /*
       move bug in current direction
       changle position of box which holds bug
       redraw window which is parent of box
       */
      Fl_Button* o = new Fl_Button(110, 135, 70, 20, "move");
      o->callback((Fl_Callback*)cb_move);
    } // Fl_Button* o
    { // Change current direction of bug
      Fl_Button* o = new Fl_Button(126, 140, 70, 20, "turn");
      o->callback((Fl_Callback*)cb_turn);
    } // Fl_Button* o
    { /*
       The path button will cause the image to move
        according to a predetermined path.
       */
      Fl_Return_Button* o = new Fl_Return_Button(228, 140, 72, 20, "Path");
      o->callback((Fl_Callback*)cb_Path);
    } // Fl_Return_Button* o
    o->end();
  } // Fl_Double_Window* o
  w->show(argc, argv);
  return Fl::run();
}
