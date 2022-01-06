#ifndef ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__TYPESUPPORT_LIBRARY_TEST_HPP_
#define ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__TYPESUPPORT_LIBRARY_TEST_HPP_

#include <gtest/gtest.h>

#include <string>

#include <rosidl_runtime_c/message_type_support_struct.h>
#include <rosidl_runtime_c/service_type_support_struct.h>

#include "rosidl_typesupport_introspection_tests/gtest/shared_library_test.hpp"

namespace rosidl_typesupport_introspection_tests {
namespace testing {

template <typename TypeSupportLibraryT>
class TypeSupportLibraryTest : public SharedLibraryTest
{
 public:
  TypeSupportLibraryTest() : SharedLibraryTest(LibraryT::name)
  {
  }
};

TYPED_TEST_SUITE_P(TypeSupportLibraryTest);

TEST_P(TypeSupportLibraryTest, MessageTypeSupportSymbolsAreCorrect) {
  using TypeSupportLibraryT = TypeParam;
  using MessageDescriptorT = typename TypeSupportLibraryT::MessageDescriptorT;

  if constexpr (TypeSupportLibraryT::has_message_typesupport_symbols) {
    const auto & message_typesupport_symbols =
        TypeSupportLibraryT::message_typesupport_symbols;
    for (const std::string symbol : message_typesupport_symbols) {
      ASSERT_TRUE(GetSharedLibrary().has_symbol(symbol));
      auto message_typesupport =
          reinterpret_cast<rosidl_message_type_support_t *>(
              GetSharedLibrary().get_symbol(symbol));
      ASSERT_NE(message_typesupport, nullptr);
      message_typesupport = rosidl_get_message_typesupport_handle(
          message_typesupport, TypeSupportLibraryT::identifier);
      ASSERT_NE(message_typesupport, nullptr);
      auto message_descriptor =
          reinterpret_cast<MessageDescriptorT *>(message_typesupport->data);
      ASSERT_STREQ(message_descriptor->message_namespace,
                   TypeSupportLibraryT::messages_namespace);
    }
  } else {
    GTEST_SKIP() << "No message typesupport symbols";
  }
}

TEST_P(TypeSupportLibraryTest, ServiceTypeSupportSymbolsAreCorrect) {
  using TypeSupportLibraryT = TypeParam;
  using MessageDescriptorT = typename TypeSupportLibraryT::MessageDescriptorT;
  using ServiceDescriptorT = typename TypeSupportLibraryT::ServiceDescriptorT;

  if constexpr (TypeSupportLibraryT::has_service_typesupport_symbols) {
    const auto & service_typesupport_symbols =
        TypeSupportLibraryT::service_typesupport_symbols
    for (const std::string symbol : service_typesupport_symbols) {
      ASSERT_TRUE(GetSharedLibrary().has_symbol(symbol));
      auto service_typesupport =
          reinterpret_cast<rosidl_service_type_support_t *>(
              GetSharedLibrary().get_symbol(symbol));
      ASSERT_NE(service_typesupport, nullptr);
      service_typesupport = rosidl_get_service_typesupport_handle(
          service_typesupport, TypeSupportLibraryT::identifier);
      ASSERT_NE(service_typesupport, nullptr);
      auto service_descriptor =
          reinterpret_cast<ServiceDescriptorT *>(service_typesupport->data);
      ASSERT_STREQ(service_descriptor->service_namespace_,
                   TypeSupportLibraryT::services_namespace);

      const std::string request_symbol = symbol + "_Request";
      ASSERT_TRUE(GetSharedLibrary().has_symbol(request_symbol));
      auto service_request_typesupport =
          reinterpret_cast<rosidl_message_type_support_t *>(
              GetSharedLibrary().get_symbol(request_symbol));
      ASSERT_NE(service_request_typesupport, nullptr);
      service_request_typesupport = rosidl_get_message_typesupport_handle(
          service_request_typesupport, TypeSupportLibraryT::identifier);
      ASSERT_NE(service_request_typesupport, nullptr);
      auto service_request_descriptor =
      reinterpret_cast<MessageDescriptorT *>(
          service_request_typesupport->data);
      ASSERT_EQ(service_descriptor->request_members,
                service_request_descriptor);
      ASSERT_STREQ(service_request_descriptor->message_namespace_,
                   TypeSupportLibraryT::services_namespace);

      const std::string response_symbol = symbol + "_Response";
      ASSERT_TRUE(GetSharedLibrary().has_symbol(response_symbol));
      auto service_response_typesupport =
          reinterpret_cast<rosidl_message_type_support_t *>(
              GetSharedLibrary().get_symbol(response_symbol));
      ASSERT_NE(service_response_typesupport, nullptr);
      service_response_typesupport = rosidl_get_message_typesupport_handle(
          service_response_typesupport, TypeSupportLibraryT::identifier);
      ASSERT_NE(service_response_typesupport, nullptr);
      auto service_response_descriptor =
          reinterpret_cast<MessageDescriptorT *>(
              service_response_typesupport->data);
      ASSERT_EQ(service_descriptor->response_members,
                service_response_descriptor);
      ASSERT_STREQ(service_response_descriptor->message_namespace_,
                   TypeSupportLibraryT::services_namespace);
    }
  } else {
    GTEST_SKIP() << "No service typesupport symbols";
  }
}

TEST_P(TypeSupportLibraryTest, ActionTypeSupportSymbolsAreCorrect) {
  using TypeSupportLibraryT = TypeParam;
  using MessageDescriptorT = typename TypeSupportLibraryT::MessageDescriptorT;
  using ServiceDescriptorT = typename TypeSupportLibraryT::ServiceDescriptorT;

  if constexpr (TypeSupportLibraryT::has_action_typesupport_symbols) {
    const auto & action_typesupport_symbols =
        TypeSupportLibraryT::action_typesupport_symbols;
    for (const std::string symbol : action_typesupport_symbols) {
      const auto action_message_symbols = {
        symbol + "_Feedback", symbol + "_FeedbackMessage",
        symbol + "_Result", symbol + "_Goal"};
      for (const auto & message_symbol : action_messages_symbols) {
        ASSERT_TRUE(GetSharedLibrary().has_symbol(message_symbol));
        auto message_typesupport =
            reinterpret_cast<rosidl_message_type_support_t *>(
                GetSharedLibrary().get_symbol(message_symbol));
        ASSERT_NE(message_typesupport, nullptr);
        message_typesupport = rosidl_get_message_typesupport_handle(
            message_typesupport, TypeSupportLibraryT::identifier);
        ASSERT_NE(message_typesupport, nullptr);
        auto message_descriptor =
            reinterpret_cast<MessageDescriptorT *>(message_typesupport->data);
        ASSERT_STREQ(message_descriptor->message_namespace,
                     TypeSupportLibraryT::actions_namespace);
      }
      const auto action_service_symbols = {
        symbol + "_GetResult", symbol + "_SendGoal"};
      for (const auto & service_symbol : action_services_symbols) {
        ASSERT_TRUE(GetSharedLibrary().has_symbol(service_symbol));
        auto service_typesupport =
            reinterpret_cast<rosidl_service_type_support_t *>(
                GetSharedLibrary().get_symbol(service_symbol));
        ASSERT_NE(service_typesupport, nullptr);
        service_typesupport = rosidl_get_service_typesupport_handle(
            service_typesupport, TypeSupportLibraryT::identifier);
        ASSERT_NE(service_typesupport, nullptr);
        auto service_descriptor =
            reinterpret_cast<ServiceDescriptorT *>(service_typesupport->data);
        ASSERT_STREQ(service_descriptor->service_namespace_,
                     TypeSupportLibraryT::services_namespace);

        const std::string service_request_symbol =
            service_symbol + "_Request";
        ASSERT_TRUE(GetSharedLibrary().has_symbol(service_request_symbol));
        auto service_request_typesupport =
            reinterpret_cast<rosidl_message_type_support_t *>(
                GetSharedLibrary().get_symbol(service_request_symbol));
        ASSERT_NE(service_request_typesupport, nullptr);
        service_request_typesupport = rosidl_get_message_typesupport_handle(
            service_request_typesupport, TypeSupportLibraryT::identifier);
        ASSERT_NE(service_request_typesupport, nullptr);
        auto service_request_descriptor =
            reinterpret_cast<MessageDescriptorT *>(
                service_request_typesupport->data);
        ASSERT_EQ(service_descriptor->request_members,
                  service_request_descriptor);
        ASSERT_STREQ(service_request_descriptor->message_namespace_,
                     TypeSupportLibraryT::services_namespace);

        const std::string service_response_symbol =
            service_symbol + "_Response";
        ASSERT_TRUE(GetSharedLibrary().has_symbol(service_response_symbol));
        auto service_response_typesupport =
            reinterpret_cast<rosidl_message_type_support_t *>(
                GetSharedLibrary().get_symbol(service_response_symbol));
        ASSERT_NE(service_response_typesupport, nullptr);
        service_response_typesupport = rosidl_get_message_typesupport_handle(
            service_response_typesupport, TypeSupportLibraryT::identifier);
        ASSERT_NE(service_response_typesupport, nullptr);
        auto service_response_descriptor =
            reinterpret_cast<MessageDescriptorT *>(
                service_response_typesupport->data);
        ASSERT_EQ(service_descriptor->response_members,
                  service_response_descriptor);
        ASSERT_STREQ(service_response_descriptor->message_namespace_,
                     TypeSupportLibraryT::services_namespace);
      }
    }
  } else {
    GTEST_SKIP() << "No service typesupport symbols";
  }
}

REGISTER_TYPED_TEST_SUITE_P(
    TypeSupportLibraryTest,
    MessageTypeSupportSymbolsAreCorrect,
    ServiceTypeSupportSymbolsAreCorrect,
    ActionTypeSupportSymbolsAreCorrect);

}  // namespace testing
}  // namespace rosidl_typesupport_introspection_tests

#endif // ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__GTEST__TYPESUPPORT_LIBRARY_TEST_HPP_
