<?php
/**
 * @file
 * quikpay_feature.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function quikpay_feature_defaultconfig_features() {
  return array(
    'quikpay_feature' => array(
      'field_default_fields' => 'field_default_fields',
    ),
  );
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function quikpay_feature_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'commerce_customer_profile-billing-field_commerce_customer_phone'.
  $fields['commerce_customer_profile-billing-field_commerce_customer_phone'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_commerce_customer_phone',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'telephone',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'telephone',
    ),
    'field_instance' => array(
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
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Please enter your telephone number without spaces or special characters.');
  t('Telephone');

  return $fields;
}
