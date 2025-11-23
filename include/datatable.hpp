#pragma once
#include <cstring>
#include <string>

namespace source {
  constexpr int PROP_TYPE_DT = 6;

  class data_table;

  struct prop_t {
    void *vtable;
    void *matching_recv_prop;
    int type;
    int bits;
    float low_value;
    float high_value;

    prop_t *array_prop;
    int ( *array_len_proxy_fn )( const void *, int );

    int elements;
    int element_stride;

    const char *exclude_dt_name;
    const char *parent_array_prop_name;

    const char *name;
    float high_low_mul;

    int flags;

    void ( *proxy_fn )(
        const void *, const void *, const void *, void *, int, int );
    void *( *send_table_proxy_fn )(
        const prop_t *, const void *, const void *, void *, int );

    data_table *table;
    int offset;
    const void *extra_data;
  };

  class data_table {
  public:
    auto find_prop_recursive( std::string name ) -> prop_t * {
      auto recurse = [ & ]( auto &&self, data_table *t ) -> prop_t * {
        if ( !t )
          return nullptr;

        // iterate backwards so we don't take baseclass path if we don't have to
        for ( int i = t->prop_count - 1; i >= 0; --i ) {
          prop_t *prop = &t->props[ i ];

          if ( prop->name && name == prop->name )
            return prop;

          if ( prop->type == PROP_TYPE_DT && prop->table ) {
            if ( auto *found = self( self, prop->table ) )
              return found;
          }
        }
        return nullptr;
      };

      return recurse( recurse, this );
    }

  private:
    prop_t *props;
    int prop_count;
    const char *table_name;
  };
} // namespace source