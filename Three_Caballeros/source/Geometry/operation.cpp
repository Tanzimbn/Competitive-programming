//distance between two points
double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}
//rotate the point CCW
point rotate(point p, double theta) {
  double rad = theta * PI / 180; //degree to rad
  return point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}
point rotate(point p, point c, double rad) {
  p.x -= c.x, p.y -= c.y;
  return point(p.x * cos(rad) - p.y * sin(rad) + c.x,
    p.x * sin(rad) + p.y * cos(rad) + c.y);
}
bool areParallel(line l1, line l2) {
  return EQ(l1.a, l2.a) && EQ(l1.b, l2.b);
}
bool areSame(line l1, line l2) {
  return areParallel(l1, l2) &&
    EQ(l1.c, l2.c);
}
bool lineIntersect(line l1, line l2,
  point & p) { //not segments
  if (areParallel(l1, l2)) return 0;
  p.x = (l2.b * l1.c - l1.b * l2.c) /
    (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS)
    p.y = -(l1.a * p.x + l1.c);
  else p.y = -(l2.a * p.x + l2.c);
  return 1;
}
vec scale(vec v, double s) {
  return vec(v.x * s, v.y * s);
}
point translate(point p, vec v) {
  return point(p.x + v.x, p.y + v.y);
}
vec perpendicular(vec v) {
  return vec(-(v.y), v.x);
}
double distToLine(point p,
  point a, point b, point & c) {
  //formula c=a + u *ab;
  vec ap(a, p), ab(a, b);
  double u = (ap * ab) / (ab * ab);
  c = translate(a, scale(ab, u));
  return dist(p, c);
}
double distToLineSegment(point p,
  point a, point b, point & c) {
  vec ap(a, p), ab(a, b);
  double u = (ap * ab) / (ab * ab);
  if (u < 0.0) {
    c = a;
    return dist(p, a);
  }
  if (u > 1.0) {
    c = b;
    return dist(p, b);
  }
  return distToLine(p, a, b, c);
}
double angle(point a, point o, point b) { //returns AOB in rad
  vec oa(o, a), ob(o, b);
  return acos((oa * ob) /
    sqrt((oa * oa) * (ob * ob)));
}
//r is on which side of line pq
//returns 0 if co-linear  
// > 0 if CCW, < 0 if CW
int direction(point p, point q, point r) {
  vec pq(p, q), pr(p, r);
  return (pq ^ pr);
}
bool onSegment(point a, point b, point p) {
  return min(a.x, b.x) <= p.x &&
    p.x <= max(a.x, b.x) &&
    min(a.y, b.y) <= p.y &&
    p.y <= max(a.y, b.y);
}
bool segmentIntersect(point a, point b,
  point c, point d) {
  //return true if two segments intersect
  //two lines are AB and CD
  int d1 = direction(c, d, a);
  int d2 = direction(c, d, b);
  int d3 = direction(a, b, c);
  int d4 = direction(a, b, d);
  //if they intersect
  if (d1 * d2 < 0 && d3 * d4 < 0)
    return 1;
  if (d1 == 0 && onSegment(c, d, a)) return 1;
  if (d2 == 0 && onSegment(c, d, b)) return 1;
  if (d3 == 0 && onSegment(a, b, c)) return 1;
  if (d4 == 0 && onSegment(a, b, d)) return 1;
  return 0;
}
double area2Dpolygon(int n,
  point a[]) {
  double area = 0;
  for (int i = 0; i + 1 < n; ++i) {
    area += a[i].x * a[i + 1].y;
    area -= a[i].y * a[i + 1].x;
  }
  area += a[2].x * a[0].y;
  area -= a[2].y * a[0].x;
  return fabs(area) / 2.0;
}
bool inPolygon(point poly[], int n, point p) {
  //returns true if the point p is inside polygon
    //(first point = last point)
  int i, j, k;
  double totAngle = 0;
  for (i = 0; i < n; ++i)
    if (poly[i].x == p.x && poly[i].y == p.y) return true;
  //if it overlaps with some point
  for (i = 1; i < n; ++i)
    if (collinear(p, poly[i - 1], poly[i]) &&
      onSegment(p, poly[i - 1], poly[i])) return true;
  //if it is in some edges of the polygon
  for (i = 1; i < n; ++i) {
    if (ccw(poly[i - 1], p, poly[i]))
      totAngle -= angle(poly[i - 1], p, poly[i]);
    else totAngle += angle(poly[i - 1], p, poly[i]);
  }
  return fabs(totAngle - 2. * PI) < EPS;
}
