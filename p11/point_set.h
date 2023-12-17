#pragma once

#include "sub_tree.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

typedef std::vector<EMST::sub_tree> forest;

class point_set : public CyA::point_vector {
 private:
  CyA::tree emst_;
  int max_arcs = 30;

 public:
  point_set(const CyA::point_vector& points);
  ~point_set(void);

  void EMST(void);
  // MODIFICACIÓN
  int verify_max_cost_arcs(void) const;

  void write_tree(std::ostream& os) const;
  void write(std::ostream& os) const;
  void write_dot(std::ostream& os) const;

  inline const CyA::tree& get_tree(void) const;
  inline const CyA::point_vector& get_points(void) const;
  inline double get_cost(void) const;

 private:
  void compute_arc_vector(CyA::arc_vector& av) const;
  void find_incident_subtrees(const forest& st, const CyA::arc& a, int& i,
                              int& j) const;
  void merge_subtrees(forest& st, const CyA::arc& a, int i, int j) const;

  double compute_cost(void) const;

  double euclidean_distance(const CyA::arc& a) const;

  // MODIFICACIÓN
  int get_max_arcs(void) const;
};