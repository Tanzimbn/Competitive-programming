struct line {
  double a, b, c;
  line() {
    a = b = c = 0.0;
  }
  line(point p1, point p2) {
    if (EQ(p1.x, p2.x)) { //vertical line
      a = 1.0, b = 0.0, c = -p1.x;
      return;
    }
    a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    b = 1.0;
    c = -(double)(a * p1.x) - p1.y;
  }
};
