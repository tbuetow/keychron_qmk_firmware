// Idea is to have each key start at base color, and advance hue by some increment on each keypress.
// NOT WORKING YET

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_REACTIVE_KEY_CYLCLE
RGB_MATRIX_EFFECT(REACTIVE_KEY_CYCLE)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV REACTIVE_KEY_CYCLE_math(HSV hsv, uint16_t offset) {
#            ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
#            endif
    // hsv.h += qsub8(130, offset);
    hsv.h += 30;
    return hsv;
}

bool REACTIVE_KEY_CYCLE(effect_params_t* params) {
    return effect_runner_reactive(params, &REACTIVE_KEY_CYCLE_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
