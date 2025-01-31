#include "point_set.h"

/**
 * @brief Constructor de la clase
 * 
 * @param points 
 */
point_set::point_set(const std::vector<point> &points) : point_vector(points) {
  quickHull();
}

/**
 * @brief Destructor de la clase
 * 
 */
point_set::~point_set(void) {}

/**
 * @brief Método que calcula el convex hull
 * 
 */
void point_set::quickHull(void) {
  hull_.clear();

  point min_x_point;
  point max_x_point;

  x_bounds(min_x_point, max_x_point);

  quickHull(line(min_x_point, max_x_point), side::LEFT);
  quickHull(line(min_x_point, max_x_point), side::RIGHT);

  // Remove duplicates
  std::sort(hull_.begin(), hull_.end());
  hull_.erase(std::unique(hull_.begin(), hull_.end()), hull_.end());
}

/**
 * @brief Método para mostrar los puntos del convex hull
 * 
 * @param os 
 */
void point_set::write_hull(std::ostream &os) const {
  os << std::endl;
  os << "Hull: " << std::endl;
  for (const point &p : hull_) {
    os << "(" << std::setw(3) << p.first << ", " << std::setw(3) << p.second << ") " << std::endl;
  }
}

/**
 * @brief Método que escribe los puntos en un fichero
 * 
 * @param os 
*/
// void point_set::write(std::ostream &os) const {
//   os << "Points: ";
//   for (const point &p : *this) {
//    os << "(" << std::setw(3) << p.first << ", " << std::setw(3) << p.second << ") " << std::endl;
//   }
//   os << std::endl;
// }

/**
 * @brief Método que escribe el árbol de expansión mínima en un fichero DOT
 * 
 * @param os 
 */
void point_set::write_dot(std::ostream &os) const {
  char c = 'a';
  std::vector<char> vector_aux;
    os << "graph {\n";
    for (const point& p : hull_) {
        os << "  " << c << " [pos=\"" << p.first << "," << p.second << "!\"]\n";
        vector_aux.push_back(c);
        ++c;
    }
    for (unsigned int i = 1; i < vector_aux.size(); ++i) {
      os << "  " << vector_aux[0] << " -- " << vector_aux[i] << std::endl;
    }
    os << "}\n";
}

/**
 * @brief Método que devuelve el convex hull
 * 
 * @return const point_vector& 
 */
const point_vector& point_set::get_hull(void) {
  return hull_;
}

/**
 * @brief Método que devuelve los puntos
 * 
 * @return const point_vector& 
 */
const point_vector& point_set::get_points(void) {
  return *this;
}

/**
 * @brief Método que devuelve la profundidad de la recursividad
 * 
 * @return const int 
 */
int point_set::get_depth(void) {
  return depth_;
}

/**
 * @brief Método que calcula el convex hull con parametros.
 * 
 * @param l 
 * @param side 
 */
void point_set::quickHull(const line &l, int side) {
  point farthest;

  if (farthest_point(l, side, farthest)) {
    depth_++;
    quickHull(line(l.first, farthest),
              -find_side(line(l.first, farthest), l.second));
    quickHull(line(farthest, l.second),
              -find_side(line(farthest, l.second), l.first));
  } else {
    hull_.push_back(l.first);
    hull_.push_back(l.second);
  }
}

/**
 * @brief Método que calcula el absoluto de la distancia entre un punto y una recta.
 * 
 * @param l 
 * @param p 
 * @return double 
 */
double point_set::distance(const line &l, const point &p) const {
  return labs(point_2_line(l, p));
}

/**
 * @brief Método que calcula el lado de un punto respecto a una recta
 * 
 * @param l 
 * @param p 
 * @return int 
 */
int point_set::find_side(const line &l, const point &p) const {
  const double dist = point_2_line(l, p);
  if (dist > 0) {
    return side::LEFT;
  } else if (dist < 0) {
    return side::RIGHT;
  } else {
    return side::CENTER;
  }
}

/**
 * @brief Método que calcula los puntos más a la izquierda y a la derecha
 * 
 * @param min_x 
 * @param max_x 
 */
void point_set::x_bounds(point &min_x, point &max_x) const {
  min_x = point_vector::at(0);
  max_x = point_vector::at(0);

  for (const point &p : *this) {
    if (p.first < min_x.first) {
      min_x = p;
    } else if (p.first > max_x.first) {
      max_x = p;
    }
  }
}

/**
 * @brief Método que calcula la distancia entre un punto y una recta
 * 
 * @param l 
 * @param p 
 * @return double 
 */
double point_set::point_2_line(const line &l, const point &p) const {
  const point &p1 = l.first;
  const point &p2 = l.second;

  return (p.second - p1.second) * (p2.first - p1.first) -
         (p2.second - p1.second) * (p.first - p1.first);
}

/**
 * @brief Método que calcula el punto más lejano a una recta
 * 
 * @param l 
 * @param side 
 * @param farthest 
 * @return true 
 * @return false 
 */
bool point_set::farthest_point(const line &l, int side,
                               point &farthest) const {
  farthest = point_vector::at(0);

  double max_dist = 0;

  bool found = false;

  for (const point &p : *this) {
    const double dist = distance(l, p);

    if (find_side(l, p) == side && dist > max_dist) {
      farthest = p;
      max_dist = dist;
      found = true;
    }
  }

  return found;
}

