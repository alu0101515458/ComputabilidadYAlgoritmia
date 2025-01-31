#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

typedef std::pair<double, double> point;
typedef std::pair<point, point> line;
typedef std::vector<point> point_vector;

enum side { LEFT = -1, CENTER, RIGHT };

class point_set : public point_vector {
 private:
  point_vector hull_;
  // MODIFICACIÓN
  // parámetro para calcular la profundidad de la recursividad con un contador.
  int depth_ = 0;

 public:
  point_set(const std::vector<point> &points);
  ~point_set(void);

  void quickHull(void);

  void write_hull(std::ostream &os) const;
  // void write(std::ostream &os) const;
  void write_dot(std::ostream& os) const;

  const point_vector& get_hull(void);
  const point_vector& get_points(void);
  // MODIFICACIÓN
  int get_depth(void);

 private:
  void quickHull(const line &l, int side);

  double distance(const line &l, const point &p) const;
  int find_side(const line &l, const point &p) const;
  void x_bounds(point &min_x, point &max_x) const;
  double point_2_line(const line &l, const point &p) const;
  bool farthest_point(const line &l, int side, point &farthest) const;
};