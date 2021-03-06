// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "lib/protocol/content_handle.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace bnet {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* ContentHandle_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ContentHandle_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_lib_2fprotocol_2fcontent_5fhandle_2eproto() {
  protobuf_AddDesc_lib_2fprotocol_2fcontent_5fhandle_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "lib/protocol/content_handle.proto");
  GOOGLE_CHECK(file != NULL);
  ContentHandle_descriptor_ = file->message_type(0);
  static const int ContentHandle_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, region_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, usage_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, hash_),
  };
  ContentHandle_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ContentHandle_descriptor_,
      ContentHandle::default_instance_,
      ContentHandle_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContentHandle, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ContentHandle));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_lib_2fprotocol_2fcontent_5fhandle_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ContentHandle_descriptor_, &ContentHandle::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_lib_2fprotocol_2fcontent_5fhandle_2eproto() {
  delete ContentHandle::default_instance_;
  delete ContentHandle_reflection_;
}

void protobuf_AddDesc_lib_2fprotocol_2fcontent_5fhandle_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n!lib/protocol/content_handle.proto\022\rbne"
    "t.protocol\"<\n\rContentHandle\022\016\n\006region\030\001 "
    "\002(\007\022\r\n\005usage\030\002 \002(\007\022\014\n\004hash\030\003 \002(\014B\020B\016CCon"
    "tentHandle", 130);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "lib/protocol/content_handle.proto", &protobuf_RegisterTypes);
  ContentHandle::default_instance_ = new ContentHandle();
  ContentHandle::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_lib_2fprotocol_2fcontent_5fhandle_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_lib_2fprotocol_2fcontent_5fhandle_2eproto {
  StaticDescriptorInitializer_lib_2fprotocol_2fcontent_5fhandle_2eproto() {
    protobuf_AddDesc_lib_2fprotocol_2fcontent_5fhandle_2eproto();
  }
} static_descriptor_initializer_lib_2fprotocol_2fcontent_5fhandle_2eproto_;


// ===================================================================

const ::std::string ContentHandle::_default_hash_;
#ifndef _MSC_VER
const int ContentHandle::kRegionFieldNumber;
const int ContentHandle::kUsageFieldNumber;
const int ContentHandle::kHashFieldNumber;
#endif  // !_MSC_VER

ContentHandle::ContentHandle()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ContentHandle::InitAsDefaultInstance() {
}

ContentHandle::ContentHandle(const ContentHandle& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ContentHandle::SharedCtor() {
  _cached_size_ = 0;
  region_ = 0u;
  usage_ = 0u;
  hash_ = const_cast< ::std::string*>(&_default_hash_);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ContentHandle::~ContentHandle() {
  SharedDtor();
}

void ContentHandle::SharedDtor() {
  if (hash_ != &_default_hash_) {
    delete hash_;
  }
  if (this != default_instance_) {
  }
}

void ContentHandle::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ContentHandle::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ContentHandle_descriptor_;
}

const ContentHandle& ContentHandle::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_lib_2fprotocol_2fcontent_5fhandle_2eproto();  return *default_instance_;
}

ContentHandle* ContentHandle::default_instance_ = NULL;

ContentHandle* ContentHandle::New() const {
  return new ContentHandle;
}

void ContentHandle::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    region_ = 0u;
    usage_ = 0u;
    if (_has_bit(2)) {
      if (hash_ != &_default_hash_) {
        hash_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ContentHandle::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 region = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &region_)));
          _set_bit(0);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(21)) goto parse_usage;
        break;
      }
      
      // required fixed32 usage = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_usage:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &usage_)));
          _set_bit(1);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_hash;
        break;
      }
      
      // required bytes hash = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_hash:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_hash()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ContentHandle::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required fixed32 region = 1;
  if (_has_bit(0)) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->region(), output);
  }
  
  // required fixed32 usage = 2;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->usage(), output);
  }
  
  // required bytes hash = 3;
  if (_has_bit(2)) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->hash(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ContentHandle::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required fixed32 region = 1;
  if (_has_bit(0)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->region(), target);
  }
  
  // required fixed32 usage = 2;
  if (_has_bit(1)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->usage(), target);
  }
  
  // required bytes hash = 3;
  if (_has_bit(2)) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->hash(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ContentHandle::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 region = 1;
    if (has_region()) {
      total_size += 1 + 4;
    }
    
    // required fixed32 usage = 2;
    if (has_usage()) {
      total_size += 1 + 4;
    }
    
    // required bytes hash = 3;
    if (has_hash()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->hash());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ContentHandle::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ContentHandle* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ContentHandle*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ContentHandle::MergeFrom(const ContentHandle& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from._has_bit(0)) {
      set_region(from.region());
    }
    if (from._has_bit(1)) {
      set_usage(from.usage());
    }
    if (from._has_bit(2)) {
      set_hash(from.hash());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ContentHandle::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ContentHandle::CopyFrom(const ContentHandle& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ContentHandle::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  return true;
}

void ContentHandle::Swap(ContentHandle* other) {
  if (other != this) {
    std::swap(region_, other->region_);
    std::swap(usage_, other->usage_);
    std::swap(hash_, other->hash_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ContentHandle::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ContentHandle_descriptor_;
  metadata.reflection = ContentHandle_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bnet

// @@protoc_insertion_point(global_scope)
