struct point_i
{
    int x, y;
    point_i ()
    {
        x = y = 0.0;
    }
    point_i (int _x, int _y)
    {
        x = _x, y = _y;
    }
    int normSq()
    {
        return sqr(x) + sqr(y);
    }
};
struct point
{
    double x, y;
    point ()
    {
        x = y = 0.0;
    }
    point (double _x,double _y)
    {
        x=_x, y=_y;
    }
    double normSq()  //same as dot product A.A
    {
        return x*x + y*y;
    }
    bool operator < (point &a) const
    {
        if(fabs(x-a.x) > EPS)
            return x < a.x;
        return y < a.y;
    }
    bool operator == (point a) const
    {
        return EQ(x, a.x) && EQ(y, a.y);
    }
};
