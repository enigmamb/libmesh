// $Id: face_inf_quad4.h,v 1.12 2003-03-11 00:47:40 ddreyer Exp $

// The Next Great Finite Element Library.
// Copyright (C) 2002  Benjamin S. Kirk, John W. Peterson
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


#ifndef __inf_quad4_h__
#define __inf_quad4_h__


#include "mesh_config.h"
#ifdef ENABLE_INFINITE_ELEMENTS

// C++ includes


// Local includes
#include "face_inf_quad.h"



/**
 * The \p INFQUAD4 is an infinite element in 2D composed of 4 nodes.
 * It is numbered like this:
   \verbatim
             3           2
   INFQUAD4: o           o   closer to infinity
             |           |
             |           |
             |           |  
             |           |
             |           |
             o-----------o   base side
             0           1
   \endverbatim
 */
// ------------------------------------------------------------
// InfQuad4 class definition
class InfQuad4 : public InfQuad
{
public:

  /**
   * Constructor.  By default this element has no parent.
   */
  InfQuad4 (const Elem* p=NULL);
  
  /**
   * @returns 4
   */
  unsigned int n_nodes() const { return 4; }

  /**
   * @returns \p INFQUAD4 
   */
  ElemType type () const { return INFQUAD4; }
  
  /**
   * @returns 1
   */
  unsigned int n_sub_elem() const { return 1; }
  
  /**
   * @returns \p FIRST
   */
  Order default_order() const { return FIRST; }
  
  /**
   * @returns an \p Edge2 for the base side, and an \p InfEdge2 for
   * the sides 1, 2.
   */
  AutoPtr<Elem> build_side (const unsigned int i) const
  { return this->side(i); }

  const std::vector<unsigned int> tecplot_connectivity(const unsigned int sf=0) const;
  
  void vtk_connectivity(const unsigned int,
			std::vector<unsigned int>*) const;
  
  unsigned int vtk_element_type (const unsigned int) const
  { return 9; }
  
  
protected:
  
  
#ifdef ENABLE_AMR
  
  /**
   * Matrix used to create the elements children.
   */
  Real embedding_matrix (const unsigned int i,
			 const unsigned int j,
			 const unsigned int k) const
  { return static_cast<Real>(_embedding_matrix[i][j][k]); }

  /**
   * Matrix that computes new nodal locations/solution values
   * from current nodes/solution.
   */
  static const float _embedding_matrix[2][4][4];
  
#endif
    
};



// ------------------------------------------------------------
// InfQuad4 class member functions
inline
InfQuad4::InfQuad4(const Elem* p) :
  InfQuad(InfQuad4::n_nodes(), p) 
{
}


#endif // ifdef ENABLE_INFINITE_ELEMENTS

#endif