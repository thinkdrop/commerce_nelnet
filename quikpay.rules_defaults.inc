<?php

/**
 * Implements hook_default_rules_configuration().
 */
function quikpay_default_rules_configuration() {

    // Add rule (clear cart before adding new product) to Rules UI
    $rules = array();
    $rule = rules_reaction_rule();
    $rule->label = t('Clear cart before adding new product');
    $rule->event('commerce_cart_product_prepare');
    $rule->action('commerce_cart_empty');
    $rule->weight = -10;
    $rules['quikpay_clear_cart_new_product'] = $rule;

    return $rules;
}
