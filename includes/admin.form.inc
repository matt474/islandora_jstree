<?php
/**
 * @file
 * Admin callbacks for Islandora jsTree
 */

/**
 * Admin form.
 */
function islandora_jstree_admin($form, &$form_state) {
  // Get settings.
  $form = array();

  $form['islandora_jstree_max_element'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of elements'),
    '#element_validate' => array('element_validate_number'),
    '#default_value' => variable_get('islandora_jstree_max_element', 1000),
    '#description' => t('The manimum number of elements to read from a zip file'),
  );

  return system_settings_form($form);
}
