// Generated by gencpp from file home_main_sys/home_std_srvRequest.msg
// DO NOT EDIT!


#ifndef HOME_MAIN_SYS_MESSAGE_HOME_STD_SRVREQUEST_H
#define HOME_MAIN_SYS_MESSAGE_HOME_STD_SRVREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace home_main_sys
{
template <class ContainerAllocator>
struct home_std_srvRequest_
{
  typedef home_std_srvRequest_<ContainerAllocator> Type;

  home_std_srvRequest_()
    : debugMode(0)
    , newFaceName()
    , textCommand()  {
    }
  home_std_srvRequest_(const ContainerAllocator& _alloc)
    : debugMode(0)
    , newFaceName(_alloc)
    , textCommand(_alloc)  {
  (void)_alloc;
    }



   typedef int8_t _debugMode_type;
  _debugMode_type debugMode;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _newFaceName_type;
  _newFaceName_type newFaceName;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _textCommand_type;
  _textCommand_type textCommand;





  typedef boost::shared_ptr< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct home_std_srvRequest_

typedef ::home_main_sys::home_std_srvRequest_<std::allocator<void> > home_std_srvRequest;

typedef boost::shared_ptr< ::home_main_sys::home_std_srvRequest > home_std_srvRequestPtr;
typedef boost::shared_ptr< ::home_main_sys::home_std_srvRequest const> home_std_srvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::home_main_sys::home_std_srvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace home_main_sys

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a6f1b0d3644656a0ddd1371d8aef44d8";
  }

  static const char* value(const ::home_main_sys::home_std_srvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa6f1b0d3644656a0ULL;
  static const uint64_t static_value2 = 0xddd1371d8aef44d8ULL;
};

template<class ContainerAllocator>
struct DataType< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "home_main_sys/home_std_srvRequest";
  }

  static const char* value(const ::home_main_sys::home_std_srvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 debugMode\n\
string newFaceName\n\
string textCommand\n\
";
  }

  static const char* value(const ::home_main_sys::home_std_srvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.debugMode);
      stream.next(m.newFaceName);
      stream.next(m.textCommand);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct home_std_srvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::home_main_sys::home_std_srvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::home_main_sys::home_std_srvRequest_<ContainerAllocator>& v)
  {
    s << indent << "debugMode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.debugMode);
    s << indent << "newFaceName: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.newFaceName);
    s << indent << "textCommand: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.textCommand);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HOME_MAIN_SYS_MESSAGE_HOME_STD_SRVREQUEST_H