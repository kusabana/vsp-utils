#pragma once
#include <string>
#include <string_view>

namespace source {
  using interface_factory_fn = void *( * ) ( const char *, int * );

  void register_interface( std::string name, void *ptr );

  class auto_interface {
  public:
    auto_interface( ) = default;

    template < typename... N >
      requires( std::is_convertible_v< N, std::string_view > && ... )
    auto_interface( N &&...names ) {
      ( register_interface(
            std::string( names ), static_cast< void * >( this ) ),
        ... );
    }
  };
} // namespace source
