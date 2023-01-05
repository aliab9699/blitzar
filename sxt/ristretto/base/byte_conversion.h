#pragma once

#include <stdint.h>

#include "sxt/base/macro/cuda_callable.h"

namespace sxt::c21t {
struct element_p3;
}
namespace sxt::f51t {
class element;
}

namespace sxt::rstb {
//--------------------------------------------------------------------------------------------------
// to_bytes
//--------------------------------------------------------------------------------------------------
CUDA_CALLABLE
void to_bytes(uint8_t s[32], const c21t::element_p3& p) noexcept;

//--------------------------------------------------------------------------------------------------
// from_bytes
//--------------------------------------------------------------------------------------------------
CUDA_CALLABLE
int from_bytes(c21t::element_p3& p, const uint8_t* s) noexcept;
} // namespace sxt::rstb
