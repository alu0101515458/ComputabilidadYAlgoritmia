#include "sub_tree.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

/**
 * @brief Namespace para el algoritmo EMST
 * 
 */
namespace EMST {
  /**
   * @brief Constructor por defecto de sub_tree
   * 
   */
  sub_tree::sub_tree(void)
      : arcs_(),
        points_(),
        cost_(0)

  {}

  /**
   * @brief Destructor de sub_tree
   * 
   */
  sub_tree::~sub_tree(void) {}

  /**
   * @brief Método que añade un arco al sub_tree	
   * 
   * @param a 
   */
  void sub_tree::add_arc(const CyA::arc &a) {
    arcs_.push_back(a);

    points_.insert(a.first);
    points_.insert(a.second);
  }

  /**
   * @brief Método que añade un punto al sub_tree
   * 
   * @param p 
   */
  void sub_tree::add_point(const CyA::point &p) { points_.insert(p); }

  /**
   * @brief Método que comprueba si un punto está en el sub_tree
   * 
   * @param p 
   * @return true 
   * @return false 
   */
  bool sub_tree::contains(const CyA::point &p) const {
    return points_.find(p) != points_.end();
  }

  /**
   * @brief Método que fusiona dos sub_trees
   * 
   * @param st 
   * @param a 
   */
  void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a) {
    arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
    arcs_.push_back(a.second);

    points_.insert(st.points_.begin(), st.points_.end());
    points_.insert(a.second.first);
    points_.insert(a.second.second);

    cost_ += a.first + st.get_cost();
  }

  /**
   * @brief Método que devuelve el coste del sub_tree
   * 
   * @return double 
   */
  double sub_tree::get_cost(void) const { return cost_; }

  /**
   * @brief Método que devuelve el árbol del sub_tree
   * 
   * @return const CyA::tree 
   */
  const CyA::tree sub_tree::get_arcs() const { return arcs_; }
}  // namespace EMST
