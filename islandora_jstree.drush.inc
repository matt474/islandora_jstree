<?php

/**
 * @file
 * drush integration for islandora_jstree.
 */

/**
 * Define plugin URIs.
 */
define('JSTREE_URI', 'https://github.com/vakata/jstree/zipball/3.3.4');


/**
 * Define directorys
 */
define('JSTREE_ORIGINAL_DIR', 'jstree');

/**
 * Implements hook_drush_command().
 */
function islandora_jstree_drush_command() {
  $items = array();
  // The key in the $items array is the name of the command.
  $items['jstree-plugin'] = array(
    'callback' => 'drush_islandora_jstree_plugin',
    'description' => dt('Download and install the jsTree plugin.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'path' => dt('Optional. A path where to install the jsTree plugin. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('jstreeplugin'),
  );
  
  return $items;
}

function drush_islandora_jstree_plugin() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = _drush_core_directory("@site:sites/all/libraries");
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the zip archive.
  if ($filepath = drush_download_file(JSTREE_URI)) {
    $filename = basename($filepath);
    $dirname = JSTREE_ORIGINAL_DIR;

    // Remove any existing plugin directory.
    if (is_dir($dirname)) {
      drush_delete_dir($dirname, TRUE);
      drush_log(dt('A existing plugin was deleted from @path', array('@path' => $path)), 'notice');
    }


    $midname = $dirname . 'file';
    // Decompress the zip archive.
    drush_tarball_extract($filename, $midname);
    
    //Move up a directory
    drush_move_dir($midname . '/vakata-jstree-a6a0d0d', $dirname, FALSE);
    drush_delete_dir($midname, TRUE);
  }

  if (is_dir($dirname)) {
    drush_log(dt('jsTree plugin has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the jsTree plugin to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
