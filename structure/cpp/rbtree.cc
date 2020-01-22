#include <iostream>
#include <algorithm>

using namespace std;

struct RBNode {
  enum {red, black} colot;
  int item;
  RBNode * left;
  RBNode * right;
  RBNode * parentl;
};

class RBTree {
  public:
    void Insert(int key);
    bool Contains(int key);
    void Delete(int key);
  private:
    RBNode * root_;
};

