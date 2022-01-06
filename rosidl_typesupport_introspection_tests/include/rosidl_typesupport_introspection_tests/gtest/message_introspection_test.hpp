#ifndef ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__MESSAGE_INTROSPECTION_TEST_H_
#define ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__MESSAGE_INTROSPECTION_TEST_H_

#include "rosidl_typesupport_introspection_tests/gtest/shared_library_test.hpp"
#include "rosidl_typesupport_introspection_tests/introspection_traits.hpp"

namespace rosidl_typesupport_introspection_tests {
namespace testing {

template<typename MessageT>
class MessageIntrospectionTest : public SharedLibraryTest
{
 public:
  using TypeSupportLibraryT =
      typename introspection_traits<MessageT>::TypeSupportLibraryT;
  MessageIntrospectionTest() : SharedLibraryTest(TypeSupportLibraryT::name)
  {
  }

  using MessageDescriptorT =
      typename TypeSupportLibraryT::MessageDescriptorT;

  MessageDescriptorT * GetMessageDescriptor() {
    return reinterpret_cast<MessageDescriptorT *>(GetLibrary().get_symbol(
        introspection_traits<MessageT>::typesupport_symbol));
  }

  auto MakeTypeErasedMessage() {
    auto * message_descriptor = GetMessageDescriptor();
    std::allocate<MessageT> allocator;
    auto type_erased_message_deleter = [=](void * ptr) {
      finalize_message(ptr, message_descriptor);
      allocator.deallocate(ptr);
    };
    std::unique_ptr<void, decltype(deleter)> type_erased_message{
      initialize_message(allocator.allocate(1), message_descriptor),
      type_erased_message_deleter};
    return type_erased_message;
  }
};

}  // namespace testing
}  // namespace rosidl_typesupport_introspection_tests

#endif // ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__MESSAGE_INTROSPECTION_TEST_H_
