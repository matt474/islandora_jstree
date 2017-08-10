(function($) {
  Drupal.behaviors.islandoraJSTree = {
    attach: function(context, settings) {    
      var $file = Drupal.settings.islandoraJSTree.resourceUri;
      
      $json = JSON.parse($file);
      
      $('#jstree').jstree({
        plugins: ['types'],
        'core' : { 
          'data' : $json
        },
        'types' : {
          'default' : { 'icon' : 'jstree-folder' },
          'file' : { 'icon' : 'jstree-file' },
        }
      });
    }
  };
})(jQuery);
