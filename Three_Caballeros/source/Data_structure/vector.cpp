struct vec
{
    double x, y;
    vec ()
    {
        x = y = 0.0;
    }
    vec (double _x, double _y)
    {
        x=_x, y=_y;
    }
    vec (point a, point b)
    {
        x = b.x-a.x,y = b.y-a.y;
    }
    vec operator + (const point &rhs)
    {
        vec tmp;
        tmp.x = x+rhs.x;
        tmp.y = y+rhs.y;
        return tmp;
    }
    vec operator - (const point &rhs)
    {
        vec tmp;
        tmp.x = x-rhs.x;
        tmp.y = y-rhs.y;
        return tmp;
    }
    vec operator * (const double &a)
    {
        vec tmp;
        tmp.x = x*a;
        tmp.y = y*a;
        return tmp;
    }
    vec operator / (const double &a)
    {
        vec tmp;
        tmp.x = x/a;
        tmp.y = y/a;
        return tmp;
    }
    double operator * (const vec &rhs)
    {
        return x*rhs.x + y*rhs.y;    //dot pro
    }
    double operator ^ (const vec &rhs)
    {
        return x*rhs.y - y*rhs.x;    //crs pro
    }
};