#include "point_set.h"
#include "sub_tree.h"

/**
 * @brief Construye un nuevo objeto point_set
 * 
 * @param points 
 */
point_set::point_set(const CyA::point_vector& points)
    : CyA::point_vector(points) {
  EMST();
}

/**
 * @brief Destruye el objeto point_set
 * 
 */
point_set::~point_set() {}

/**
 * @brief Método que calcula el árbol de expansión mínima
 * 
 */
void point_set::EMST(void) {
  CyA::arc_vector av;
  compute_arc_vector(av);

  forest st;

  for (const CyA::point &p : *this) {
    EMST::sub_tree s;
    s.add_point(p);

    st.push_back(s);
  }

  for (const CyA::weigthed_arc &a : av) {
    int i, j;
    find_incident_subtrees(st, a.second, i, j);
    if (i != j) {
      merge_subtrees(st, a.second, i, j);
    }
  }
  emst_ = st[0].get_arcs();
}

/**
 * @brief Método que escribe el árbol de expansión mínima en un fichero de salida
 * 
 * @param os 
 */
void point_set::write_tree(std::ostream &os) const {
  os << std::endl;
  for (const CyA::arc &a : emst_) {
    os << "(" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << a.first.first << ", " << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << a.first.second << ") - (" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << a.second.first << ", " << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << a.second.second << ")" << std::endl;
  }

  os << std::endl;
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC+2) << get_cost() << std::endl;
}

/**
 * @brief Método que escribe el conjunto de puntos en un fichero de salida
 * 
 * @param os 
 */
void point_set::write(std::ostream &os) const {
  os << (CyA::point_vector &)(*this) << std::endl;
}

/**
 * @brief Método que escribe el árbol de expansión mínima en un fichero DOT
 * 
 * @param os 
 */
void point_set::write_dot(std::ostream &os) const {
  char c = 'a';
  std::vector<char> vector_aux;
    os << "graph {\n";
    for (const CyA::point& p : *this) {
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
 * @brief Método que devuelve el árbol de expansión mínima
 * 
 * @return const CyA::tree& 
 */
inline const CyA::tree &point_set::get_tree(void) const { return emst_; }

/**
 * @brief Método que devuelve el conjunto de puntos
 * 
 * @return const CyA::point_vector& 
 */
inline const CyA::point_vector &point_set::get_points(void) const {
  return *this;
}

/**
 * @brief Método que devuelve el coste del árbol
 * 
 * @return double 
 */
inline double point_set::get_cost(void) const { return compute_cost(); }

/**
 * @brief Método que calcula el vector de arcos
 * 
 * @param av 
 */
void point_set::compute_arc_vector(CyA::arc_vector &av) const {
  av.clear();
  const int n = size();
  for (int i = 0; i < n - 1; ++i) {
    const CyA::point &p_i = (*this)[i];
    for (int j = i + 1; j < n; ++j) {
      const CyA::point &p_j = (*this)[j];

      const double dist = euclidean_distance(std::make_pair(p_i, p_j));

      av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
    }
  }
  std::sort(av.begin(), av.end());
}

/**
 * @brief Método que encuentra los subárboles incidentes
 * 
 * @param st 
 * @param a 
 * @param i 
 * @param j 
 */
void point_set::find_incident_subtrees(const forest &st, const CyA::arc &a,
                                       int &i, int &j) const {
  i = j = -1;
  const int n = st.size();
  for (int k = 0; k < n; ++k) {
    if (st[k].contains(a.first)) {
      i = k;
    }
    if (st[k].contains(a.second)) {
      j = k;
    }
  }

  if ((i == -1) && (j == -1)) {
    return;
  }
}

/**
 * @brief Método que fusiona los subárboles
 * 
 * @param st 
 * @param a 
 * @param i 
 * @param j 
 */
void point_set::merge_subtrees(forest &st, const CyA::arc &a, int i,
                               int j) const {
  st[i].merge(st[j], std::make_pair(euclidean_distance(a), a));
  st.erase(st.begin() + j);
}

/**
 * @brief Método que calcula el coste del árbol
 * 
 * @return double 
 */
double point_set::compute_cost(void) const {
  double cost = 0;

  for (const CyA::arc &a : emst_) {
    cost += euclidean_distance(a);
  }

  return cost;
}

/**
 * @brief Método que calcula la distancia euclídea entre dos puntos
 * 
 * @param a 
 * @return double 
 */
double point_set::euclidean_distance(const CyA::arc &a) const {
  return std::sqrt(std::pow(a.first.first - a.second.first, 2) +
                   std::pow(a.first.second - a.second.second, 2));
}

// MODIFICACIÓN
/**
 * @brief Método que devuelve el número máximo de arcos permitidos.
 * 
 * @return int 
 */
int point_set::get_max_arcs(void) const { return max_arcs; }

/**
 * @brief Método que verifica todos los arcos del arbol, si alguno sobrepasa el máximo permitido, lo muestra por pantalla.
 * 
 * @return int
 */
int point_set::verify_max_cost_arcs(void) const {
  int count = 0;
  for (const CyA::arc &a : emst_) {
    if (euclidean_distance(a) > get_max_arcs()) {
      ++count;
    }
  }
  return count;
}