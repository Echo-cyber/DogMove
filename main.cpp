#include <iostream>
#include "animation.h"

using namespace std;

class Bug {
public:
  Bug(int position) {
    _position = position;
    _movingRight = true;
  }

  void turn() {
    _movingRight = !_movingRight;
  }

  void move() {
    if (_movingRight) {
      _position ++;
    } else {
      _position --;
    }
  }

  int getPosition() {
    return _position;
  }

private:
  int _position;
  bool _movingRight;
};


int main()
{
  Bug bugsy(100);
  Picture right("bugright.png");
  Picture left("bugleft.png");
  Animation anim("animation.gif", 200, 50);
  anim.add(right, bugsy.getPosition(), 0);
  anim.frame();

  cout << "current position: " << bugsy.getPosition() << endl;

  for (int i = 0; i < 50; i ++) {
    bugsy.move();
    anim.add(right, bugsy.getPosition(), 0);
    anim.frame();
  }
  cout << "current position: " << bugsy.getPosition() << ", expected position: 150" << endl;
  bugsy.turn();
  for (int i = 0; i < 50; i ++) {
    bugsy.move();
    anim.add(left, bugsy.getPosition(), 0);
    anim.frame();
  }
  cout << "current position: " << bugsy.getPosition() << ", expected position: 100" << endl;

  anim.close();
}
