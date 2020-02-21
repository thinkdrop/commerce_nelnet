<?php
/**
 * @file
 * quikpay_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function quikpay_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'commerce_customer_profile-billing-field_commerce_customer_phone'.
  $field_instances['commerce_customer_profile-billing-field_commerce_customer_phone'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter your telephone number without spaces or special characters.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => -9,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'field_commerce_customer_phone',
    'label' => 'Telephone',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '',
      ),
      'type' => 'telephone_default',
      'weight' => -9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Please enter your telephone number without spaces or special characters.');
  t('Telephone');

  return $field_instances;
}
