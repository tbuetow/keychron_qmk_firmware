#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SATURATION
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SATURATION)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV SOLID_REACTIVE_SATURATION_math(HSV hsv, uint16_t offset) {
#            ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
#            endif
    // hsv.h += qsub8(130, offset);
    hsv.s += qsub8(130, offset);
    return hsv;
}

bool SOLID_REACTIVE_SATURATION(effect_params_t* params) {
    return effect_runner_reactive(params, &SOLID_REACTIVE_SATURATION_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
