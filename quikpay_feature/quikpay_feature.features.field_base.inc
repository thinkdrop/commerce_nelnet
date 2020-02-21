<?php
/**
 * @file
 * quikpay_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function quikpay_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_commerce_customer_phone'.
  $field_bases['field_commerce_customer_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_customer_phone',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'telephone',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'telephone',
  );

  return $field_bases;
}
