// 0x0C000000
const GeoLayout klepto_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 250),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 65536),
      GEO_OPEN_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, klepto_seg5_dl_050041E8),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 62, 0, 0, klepto_seg5_dl_05003F20),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 44, 0, 0, klepto_seg5_dl_05003D80),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 58, 0, 0, klepto_seg5_dl_05003BD0),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, -3, 17, 17, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, klepto_seg5_dl_05004330),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 68, 0, 0, klepto_seg5_dl_050047C8),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
                     GEO_OPEN_NODE(),
                        GEO_SWITCH_CASE(6, geo_switch_anim_state),
                        GEO_OPEN_NODE(),
                           GEO_NODE_START(),
                           GEO_NODE_START(),
                           GEO_OPEN_NODE(),
                              GEO_SCALE(0x00, 16384),
                              GEO_OPEN_NODE(),
                                 GEO_ASM(0, geo_offset_klepto_held_object),
                                 GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 100, 0, 180, 270, 0, mario_cap_seg3_dl_03022F48),
                              GEO_CLOSE_NODE(),
                           GEO_CLOSE_NODE(),
                           GEO_NODE_START(),
                           GEO_OPEN_NODE(),
                              GEO_SCALE(0x00, 16384),
                              GEO_OPEN_NODE(),
                                 GEO_ASM(0, geo_offset_klepto_held_object),
                                 GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 100, 0, 180, 270, 0, star_seg3_dl_0302B870),
                                 GEO_ASM(0, geo_offset_klepto_held_object),
                                 GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 0, 100, 0, 180, 270, 0, star_seg3_dl_0302BA18),
                              GEO_CLOSE_NODE(),
                           GEO_CLOSE_NODE(),
                           GEO_NODE_START(),
                           GEO_OPEN_NODE(),
                              GEO_SCALE(0x00, 16384),
                              GEO_OPEN_NODE(),
                                 GEO_ASM(0, geo_offset_klepto_held_object),
                                 GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 100, 0, 180, 270, 0, transparent_star_seg3_dl_0302C620),
                              GEO_CLOSE_NODE(),
                           GEO_CLOSE_NODE(),
                           GEO_NODE_START(),
                           GEO_OPEN_NODE(),
                              GEO_SCALE(0x00, 16384),
                              GEO_OPEN_NODE(),
                                 GEO_ASM(0, geo_offset_klepto_held_object),
                                 GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 100, 0, 180, 270, 0, luigi_capbase),
                              GEO_CLOSE_NODE(),
                           GEO_CLOSE_NODE(),
                           GEO_NODE_START(),
                           GEO_OPEN_NODE(),
                              GEO_SCALE(0x00, 16384),
                              GEO_OPEN_NODE(),
                                 GEO_ASM(0, geo_offset_klepto_held_object),
                                 GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 0, 100, 0, 180, 270, 0, wario_capbase),
                              GEO_CLOSE_NODE(),
                           GEO_CLOSE_NODE(),
                        GEO_CLOSE_NODE(),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, -3, 17, -17, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, klepto_seg5_dl_05004438),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 68, 0, 0, klepto_seg5_dl_05004B58),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 49, -9, -17, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, klepto_seg5_dl_05004D38),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_ALPHA, 34, 0, 0, klepto_seg5_dl_05004F58),
                     GEO_OPEN_NODE(),
                        GEO_ANIMATED_PART(LAYER_ALPHA, 79, 0, 0, klepto_seg5_dl_05005178),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 49, -9, 17, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, klepto_seg5_dl_05004C28),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_ALPHA, 34, 0, 0, klepto_seg5_dl_05004E48),
                     GEO_OPEN_NODE(),
                        GEO_ANIMATED_PART(LAYER_ALPHA, 79, 0, 0, klepto_seg5_dl_05005068),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, klepto_seg5_dl_05004118),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
