#include "interface.hpp"
#include <string>
#include <unordered_map>

namespace source {
  std::unordered_map< std::string, void * > &interface_registry( ) {
    static std::unordered_map< std::string, void * > interface_registry = { };
    return interface_registry;
  }

  void register_interface( std::string name, void *ptr ) {
    interface_registry( ).emplace( std::move( name ), ptr );
  }

  void *get_interface( const std::string &name ) {
    auto it = interface_registry( ).find( name );
    return it != interface_registry( ).end( ) ? it->second : nullptr;
  }
} // namespace source

enum class return_code : bool { FAILED, OK };

extern "C" __attribute__( ( used ) ) void *
CreateInterface( const char *name, return_code *ret ) {
  auto interface = source::get_interface( name );

  if ( ret != nullptr )
    *ret = static_cast< return_code >( interface != nullptr );

  return interface;
}
