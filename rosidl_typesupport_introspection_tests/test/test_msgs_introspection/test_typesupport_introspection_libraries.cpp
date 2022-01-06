#include <gtest/gtest.h>

#include "rosidl_typesupport_introspection_tests/gtest/typesupport_library_test.hpp"

#include "test_msgs/types.hpp"

namespace rosidl_typesupport_introspection_tests {
namespace {

using IntrospectionTypeSupportLibraries = ::testing::Types<
  TestMsgsIntrospectionCTypeSupportLibrary,
  TestMsgsIntrospectionCppTypeSupportLibrary>;

INSTANTIATE_TYPED_TEST_SUITE_P(Introspection, TypeSupportLibraryTest,
                               IntrospectionTypeSupportLibraries);

}  // namespace
}  // namespace rosidl_typesupport_introspection_tests
