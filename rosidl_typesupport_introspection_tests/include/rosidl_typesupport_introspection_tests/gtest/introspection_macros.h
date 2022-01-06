#ifndef INTROSPECTION_GTEST_MACROS_H_
#define INTROSPECTION_GTEST_MACROS_H_

#define ASSERT_ITERABLE_MEMBER_EQ(                                      \
    type_erased_message, message, member_descriptor, member_name)       \
  {                                                                     \
    ASSERT_STREQ(member_descriptor->name_, #member_name);               \
    using member_base_type = decltype(message.member_name[0]);          \
    ASSERT_TRUE(has_iterable_structure(member_descriptor));             \
    const void * type_erased_member =                                   \
        get_member(type_erased_message, member_descriptor);             \
    const size_t size = get_member_size(                                \
        type_erased_member, member_descriptor);                         \
    for (size_t i = 0u; i < size; ++i) {                                \
      const auto & item = get_const_member_item<member_base_type>(      \
          type_erased_member, member_descriptor, i);                    \
      ASSERT_EQ(item, message.member_name[i]);                          \
    }                                                                   \
  }

#define ASSERT_MEMBER_EQ(                                               \
    type_erased_message, message, member_descriptor, member_name)       \
  {                                                                     \
    ASSERT_STREQ(member_descriptor->name_, #member_name);               \
    using member_type = decltype(message.member_name);                  \
    const auto & member = get_const_member<member_type>(                \
        type_erased_message, member_descriptor);                        \
    ASSERT_EQ(member, message.member_name);                             \
  }

#define ASSERT_ARRAY_MEMBER_ASSIGNMENT(                           \
    type_erased_message, message, member_descriptor, member_name) \
  {                                                               \
    ASSERT_STREQ(member_descriptor->name_, #member_name);         \
    using member_base_type = decltype(message.member_name[0]);    \
    ASSERT_TRUE(has_array_structure(member_descriptor));          \
    const void * type_erased_member =                             \
        get_member(type_erased_message, member_descriptor);       \
    const size_t size = get_member_size(                          \
        type_erased_member, member_descriptor);                   \
    for (size_t i = 0u; i < size; ++i) {                          \
      auto & item = get_member_item<member_base_type>(            \
          type_erased_member, member_descriptor, i);              \
      item = message.member_name[i];                              \
    }                                                             \
  }

#define ASSERT_MEMBER_ASSIGNMENT(                                 \
    type_erased_message, message, member_descriptor, member_name) \
  {                                                               \
    ASSERT_STREQ(member_descriptor->name_, #member_name);         \
    using member_type = decltype(message.member_name);            \
    auto & member = get_member<member_type>(                      \
        type_erased_message, member_descriptor);                  \
    member = message.member_name;                                 \
  }

#endif // INTROSPECTION_GTEST_MACROS_H_
