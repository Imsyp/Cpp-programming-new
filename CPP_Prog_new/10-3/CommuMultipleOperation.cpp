#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    Point operator*(int times)
    {
        Point pos(xpos*times, ypos*times);
        return pos;
    }
    friend Point operator*(int times, Point &ref);
};

Point operator*(int times, Point &ref)
{
    Point pos(ref.xpos * times, ref.ypos * times);
    return pos;
}

int main(void)
{
    Point pos(1, 2);
    Point cpy;

    cpy=3*pos;
    cpy.ShowPosition();

    cpy=3*pos*2;
    cpy.ShowPosition();
    
    return 0;
}