#pragma once

#include <stddef.h>
#include <stdint.h>

namespace source {
  class server_unknown {
  public:
    virtual void *ihandleentity_0( ) = 0;
    virtual void *ihandleentity_1( ) = 0;
    virtual void *ihandleentity_2( ) = 0;
    virtual void *get_collideable( ) = 0;
    virtual void *get_networkable( ) = 0;
    virtual void *get_base_entity( ) = 0;
  };

  struct edict {
    int state_flags;
    short edict_index;
    short network_sn;
    void *networkable;
    server_unknown *unknown;
  };
} // namespace source
