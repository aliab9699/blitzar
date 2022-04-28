#include "sxt/multiexp/index/partition_marker_utility.h"

#include "sxt/base/test/unit_test.h"
using namespace sxt;
using namespace sxt::mtxi;

TEST_CASE(
    "we can condense a sequences of indexes down to a marker of its partition "
    "set") {
  SECTION("we correctly handle cases with a single element") {
    uint64_t data[1];

    basct::span<uint64_t> values;
    uint64_t marker;

    *data = 0;
    values = data;
    marker = consume_partition_marker(values, 1);
    REQUIRE(values.empty());
    REQUIRE(marker == 1);

    *data = 1;
    values = data;
    marker = consume_partition_marker(values, 1);
    REQUIRE(values.empty());
    REQUIRE(marker == 3);

    *data = 5;
    values = data;
    marker = consume_partition_marker(values, 10);
    REQUIRE(values.empty());
    REQUIRE(marker == 32);
  }

  SECTION("we correctly handle cases with two elements with two elements") {
    uint64_t data[2];

    basct::span<uint64_t> values;
    uint64_t marker;

    data[0] = 0;
    data[1] = 1;
    values = data;
    marker = consume_partition_marker(values, 1);
    REQUIRE(values.size() == 1);
    REQUIRE(values[0] == 1);
    REQUIRE(marker == 1);

    data[0] = 0;
    data[1] = 1;
    values = data;
    marker = consume_partition_marker(values, 2);
    REQUIRE(values.empty());
    REQUIRE(marker == 3);

    data[0] = 1;
    data[1] = 2;
    values = data;
    marker = consume_partition_marker(values, 2);
    REQUIRE(values.size() == 1);
    REQUIRE(values[0] == 2);
    REQUIRE(marker == 2);

    data[0] = 3;
    data[1] = 5;
    values = data;
    marker = consume_partition_marker(values, 2);
    REQUIRE(values.size() == 1);
    REQUIRE(values[0] == 5);
    REQUIRE(marker == 6);
  }
}
