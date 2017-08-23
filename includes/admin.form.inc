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

  $form['islandora_jstree_megabyte_max_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum file size'),
    '#element_validate' => array('element_validate_number'),
    '#default_value' => variable_get('islandora_jstree_megabyte_max_size', 500),
    '#description' => t('The manimum size of a zip file in megabytes to open'),
    '#ajax' => array(
      'callback' => 'islandora_jstree_ajax_callback',
      'wrapper' => 'file-size-div',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  if(isset($form_state['values']['islandora_jstree_megabyte_max_size'])) {
    $num_size = 1024*1024*(double)$form_state['values']['islandora_jstree_megabyte_max_size'];

    $display_size = 'Maximum file size: ' . format_size($num_size);
  }
  else
    $display_size = 'Not calculated';

  $form['islandora_jstree_display_size'] = array(
    '#prefix' => '<div id="file-size-div">',
    '#suffix' => '</div>',
    '#markup' => $display_size,
  );

  $form['islandora_jstree_max_element'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of elements'),
    '#element_validate' => array('element_validate_number'),
    '#default_value' => variable_get('islandora_jstree_max_element', 1000),
    '#description' => t('The manimum number of elements to display from a zip file'),
  );

  return system_settings_form($form);
}

function islandora_jstree_ajax_callback($form, $form_state) {
  return $form['islandora_jstree_display_size'];
}
