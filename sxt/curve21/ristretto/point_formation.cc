#include "sxt/curve21/ristretto/point_formation.h"

#include "sxt/curve21/operation/add.h"
#include "sxt/curve21/ristretto/elligator.h"
#include "sxt/curve21/type/element_p3.h"
#include "sxt/field51/type/element.h"

namespace sxt::c21rs {
//--------------------------------------------------------------------------------------------------
// form_ristretto_point
//--------------------------------------------------------------------------------------------------
CUDA_CALLABLE
void form_ristretto_point(c21t::element_p3& p, const f51t::element& r0,
                          const f51t::element& r1) noexcept {
  c21t::element_p3 p0;
  apply_elligator(p0, r0);
  apply_elligator(p, r1);
  c21o::add(p, p, p0);
}
}  // namespace sxt::c21rs
