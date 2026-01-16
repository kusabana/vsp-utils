#pragma once

#include <cstdint>

namespace source {
  struct surface {
    const char *name;
    short surfaceProps;
    unsigned short flags;
  };

  struct plane {
    float normal[ 3 ];
    float dist;
    std::uint8_t type;
    std::uint8_t signbits;
    std::uint8_t pad[ 2 ];
  };

  struct base_trace {
    float startpos[ 3 ];
    float endpos[ 3 ];
    plane plane;
    float fraction;
    int contents;
    unsigned short disp_flags;
    bool all_solid;
    bool start_solid;
  };

  struct game_trace : public base_trace {
    float fraction_left_solid;
    surface surface;
    int hitgroup;
    short physics_bone;
    void *entity;
    int hitbox;
  };
} // namespace source
