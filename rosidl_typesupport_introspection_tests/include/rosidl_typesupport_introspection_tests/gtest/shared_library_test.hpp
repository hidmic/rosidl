#ifndef ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__SHARED_LIBRARY_TEST_HPP_
#define ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__SHARED_LIBRARY_TEST_HPP_

#include <gtest/gtest.h>

#include <string>

#include <rcpputils/shared_library.hpp>

namespace rosidl_typesupport_introspection_tests {
namespace testing {

class SharedLibraryTest : public ::testing::Test {
public:
  SharedLibraryTest(const std::string & name)
    : library_(rcpputils::get_platform_library_name(name))
  {
  }

  rcpputils::SharedLibrary & GetLibrary() { return library_; }

 private:
  rcpputils::SharedLibrary library_;
};

}  // namespace testing
}  // namespace rosidl_typesupport_introspection_tests

#endif // ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__SHARED_LIBRARY_TEST_HPP_
