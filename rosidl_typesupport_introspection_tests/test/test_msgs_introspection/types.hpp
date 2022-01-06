#ifndef TEST_MSGS_INTROSPECTION__TYPES_HPP_
#define TEST_MSGS_INTROSPECTION__TYPES_HPP_

#include <rosidl_typesupport_interface/macros.h>
#include <rosidl_typesupport_introspection_c/message_introspection.h>
#include <rosidl_typesupport_introspection_cpp/message_introspection.hpp>

#include "rosidl_typesupport_introspection_tests/introspection_traits.hpp"

#include "test_msgs/msg/arrays.h"
#include "test_msgs/msg/arrays.hpp"

#include "test_msgs/msg/empty.h"
#include "test_msgs/msg/empty.hpp"

namespace rosidl_typesupport_introspection_tests {

struct TestMsgsIntrospectionCTypeSupportLibrary {
  using MessageDescriptorT = rosidl_typesupport_c__MessageMembers;
  using ServiceDescriptorT = rosidl_typesupport_c_ServiceMembers;
  using MemberDescriptorT = rosidl_typesupport_c__MessageMember;

  static constexpr char * name =
      ROSIDL_TYPESUPPORT_INTERFACE__LIBRARY_NAME(
          rosidl_typesupport_c, test_msgs);
  static constexpr char * identifier = "rosidl_typesupport_c";

  static constexpr char * messages_namespace = "test_msgs__msg";
  static constexpr char * services_namespace = "test_msgs__srv";
  static constexpr char * actions_namespace = "test_msgs__action";

  static constexpr char * message_typesupport_symbols[] = {
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_c, test_msgs, msg, Empty),
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_cpp, test_msgs, msg, BasicTypes),
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_c, test_msgs, msg, Arrays),
  };
  static constexpr char * service_typesupport_symbols[] = {
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
        rosidl_typesupport_c, test_msgs, srv, BasicTypes),
  };
  static constexpr char * action_typesupport_symbols[] = {
    ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
        rosidl_typesupport_c, test_msgs, action, Fibonacci),
  };
};

template<>
struct introspection_traits<test_msgs__msg__Empty>
{
  static constexpr char * typesupport_symbol =
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
          rosidl_typesupport_c, test_msgs, msg, Empty);
  using TypeSupportLibrary = TestMsgsIntrospectionCTypeSupportLibrary;
};

template<>
struct introspection_traits<test_msgs__msg__Arrays>
{
  static constexpr char * typesupport_symbol =
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
          rosidl_typesupport_c, test_msgs, msg, Arrays);
  using TypeSupportLibrary = TestMsgsIntrospectionCTypeSupportLibrary;
};

template<>
MakeExampleMessage<test_msgs__msg__Arrays>() {
  test_msgs__msg__Arrays message;
  test_msgs__msg__Arrays_init(&message);
  return message;
}

struct TestMsgsIntrospectionCppTypeSupportLibrary {
  using MessageDescriptorT = rosidl_typesupport_cpp::MessageMembers;
  using ServiceDescriptorT = rosidl_typesupport_cpp::ServiceMembers;
  using MemberDescriptorT = rosidl_typesupport_cpp::MessageMember;

  static constexpr char * name =
      ROSIDL_TYPESUPPORT_INTERFACE__LIBRARY_NAME(
          rosidl_typesupport_cpp, test_msgs);
  static constexpr char * identifier = "rosidl_typesupport_cpp";

  static constexpr char * messages_namespace = "test_msgs::msg";
  static constexpr char * services_namespace = "test_msgs::srv";
  static constexpr char * actions_namespace = "test_msgs::action";

  static constexpr char * message_typesupport_symbols[] = {
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_cpp, test_msgs, msg, Empty),
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_cpp, test_msgs, msg, BasicTypes),
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_cpp, test_msgs, msg, Arrays),
  };
  static constexpr char * service_typesupport_symbols[] = {
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
        rosidl_typesupport_cpp, test_msgs, srv, BasicTypes),
  };
  static constexpr char * action_typesupport_symbols[] = {
    ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
        rosidl_typesupport_cpp, test_msgs, action, Fibonacci),
  };
};

template<>
struct introspection_traits<test_msgs::msg::Empty>
{
  static constexpr char * typesupport_symbol =
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
          rosidl_typesupport_cpp, test_msgs, msg, Empty);
  using TypeSupportLibrary = TestMsgsIntrospectionCppTypeSupportLibrary;
};

template<>
struct introspection_traits<test_msgs::msg::Arrays>
{
  static constexpr char * typesupport_symbol =
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
          rosidl_typesupport_cpp, test_msgs, msg, Arrays);
  using TypeSupportLibrary = TestMsgsIntrospectionCppTypeSupportLibrary;
};

template<>
MakeExampleMessage<test_msgs::msg::Arrays>() {
  test_msgs::msg::Arrays message;
  return message;
}

}  // namespace rosidl_typesupport_introspection_tests

#endif // TEST_MSGS_INTROSPECTION__TYPES_HPP_
