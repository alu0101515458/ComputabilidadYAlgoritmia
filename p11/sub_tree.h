#pragma once

#include <cmath>
#include <iostream>

#include "point_types.h"

namespace EMST {
  class sub_tree { 
   public:
    sub_tree(void);
    ~sub_tree(void);
  
    void add_arc(const CyA::arc &a);
    void add_point(const CyA::point &p);
    bool contains(const CyA::point &p) const;
    void merge(const sub_tree &st, const CyA::weigthed_arc &a);
  
    double get_cost(void) const;
    const CyA::tree get_arcs(void) const;
    int get_max_arcs(void) const;

   private:
    CyA::tree arcs_;
    CyA::point_collection points_;
    double cost_;
  };
  
  typedef std::vector<sub_tree> sub_tree_vector;
}  // namespace EMST