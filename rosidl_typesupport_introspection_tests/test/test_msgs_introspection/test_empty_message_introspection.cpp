#include <gtest/gtest.h>

#include "rosidl_typesupport_introspection_tests/gtest/message_introspection_test.hpp"
#include "rosidl_typesupport_introspection_tests/introspection_functions.hpp"
#include "rosidl_typesupport_introspection_tests/introspection_traits.hpp"

#include "test_msgs_introspection/types.hpp"

namespace rosidl_typesupport_introspection_tests {
namespace {

template<typename EmptyMessageT>
class EmptyMessageIntrospectionTest :
    public MessageIntrospectionTest<EmptyMessageT>
{
};

using EmptyMessageTypes = ::testing::Types<
  test_msgs__msg__Empty, test_msgs::msg::Empty>;
TYPED_TEST_SUITE(EmptyMessageIntrospectionTest, EmptyMessageTypes);

TYPED_TEST(EmptyMessageIntrospectionTest, MessageDescriptorIsCorrect)
{
  using EmptyMessageT = TypeParam;
  using TypeSupportLibraryT =
      typename introspection_traits<EmptyMessageT>::TypeSupportLibraryT;

  auto * message_descriptor = GetMessageDescriptor();
  EXPECT_STREQ(get_message_namespace(message_descriptor),
               TypeSupportLibraryT::messages_namespace);
  EXPECT_STREQ(get_message_name(message_descriptor), "Empty");
  ASSERT_EQ(get_message_size(member_descriptor), sizeof(EmptyMessageT));
  ASSERT_EQ(get_member_count(message_descriptor), 1u);
}

}  // namespace
}  // namespace rosidl_typesupport_introspection_tests
