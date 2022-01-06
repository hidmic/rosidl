#ifndef ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__INTROSPECTION_FUNCTIONS_HPP_
#define ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__INTROSPECTION_FUNCTIONS_HPP_

namespace rosidl_typesupport_introspection_tests {

#define MEMBER_EXPRESSION_TYPE(type, expression)  \
  decltype(std::declval<type>().expression)

template <typename MemberDescriptorT>
bool has_simple_structure(MemberDescriptorT * member_descriptor)
{
  return (!member_descriptor->is_array_ &&
          member_descriptor->size_function == nullptr &&
          member_descriptor->get_function == nullptr &&
          member_descriptor->get_const_function == nullptr &&
          member_descriptor->resize_function == nullptr);
}

template <typename MemberDescriptorT>
bool has_iterable_structure(MemberDescriptorT * member_descriptor)
{
  return (member_descriptor->is_array_ &&
          member_descriptor->size_function != nullptr &&
          member_descriptor->get_function != nullptr &&
          member_descriptor->get_const_function != nullptr);
}

template <typename MemberDescriptorT>
bool has_array_structure(MemberDescriptorT * member_descriptor)
{
  return (has_iterable_structure(member_descriptor) &&
          member_descriptor->resize_function == nullptr);
}

template <typename MemberDescriptorT>
bool has_array_structure(MemberDescriptorT * member_descriptor, size_t size)
{
  return (has_array_structure(member_descriptor) &&
          member_descriptor->array_size_ == size);
}

template <typename MessageT, typename MemberDescriptorT, typename TypeIdT>
bool is_message_type_member(MemberDescriptorT * member_descriptor)
{
  const rosidl_message_type_support_t * ts =
      get_message_type_support_handle<MessageT>();
  return (member_descriptor->type_id_ == ROS_TYPE_MESSAGE &&
          member_descriptor->members_ == ts);
}



template <typename MessageTypeDescriptorT>
void * initialize(void * message, MessageTypeDescriptorT * message_type_descriptor)
{
  message_type_descriptor->init_function(message, ALL);
  return message;
}

template <typename MessageTypeDescriptorT>
void finalize(void * message, MessageTypeDescriptorT * message_type_descriptor)
{
  message_type_descriptor->fini_function(message);
}


template <typename MemberDescriptorT>
void * get_member(void * message, MemberDescriptorT * member_descriptor)
{
  return message + member_descriptor->offset_;
}

template <typename MemberT, typename MemberDescriptorT>
MemberT& get_member(void * message, MemberDescriptorT * member_descriptor)
{
  return *reinterpret_cast<MemberT *>(get_member(message, member_descriptor));
}

template <typename MemberDescriptorT>
const void *
get_const_member(void * message, MemberDescriptorT * member_descriptor)
{
  return message + member_descriptor->offset_;
}

template <typename MemberT, typename MemberDescriptorT>
const MemberT&
get_const_member(void * message, MemberDescriptorT * member_descriptor)
{
  return *reinterpret_cast<const MemberT *>(
      get_const_member(message, member_descriptor));
}

template <typename MemberDescriptorT>
void * get_member_item(void * member, MemberDescriptorT * member_descriptor, size_t index)
{
  return member_descriptor->get_function(member, index);
}

template <typename ItemT, typename MemberDescriptorT>
ItemT& get_member_item(void * member, MemberDescriptorT * member_descriptor, size_t index)
{
  return *reinterpret_cast<ItemT *>(get_member_item(member, member_descriptor, index));
}

template <typename MemberDescriptorT>
const void * get_const_member_item(
    void * member, MemberDescriptorT * member_descriptor, size_t index)
{
  return member_descriptor->get_const_function(member, index);
}

template <typename ItemT, typename MemberDescriptorT>
const ItemT&
get_const_member_item(void * member, MemberDescriptorT * member_descriptor, size_t index)
{
  return *reinterpret_cast<const ItemT *>(
      get_const_member_item(message, member_descriptor, index));
}

template <typename MemberDescriptorT>
size_t get_member_size(void * member, MemberDescriptorT * member_descriptor)
{
  return member_descriptor->size_function(member);
}

}  // namespace rosidl_typesupport_introspection_tests

#endif // ROSIDL_TYPESUPPORT_INTROSPECTION_TESTS__INTROSPECTION_FUNCTIONS_HPP_
