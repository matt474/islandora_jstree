(function($) {
  Drupal.behaviors.islandoraJSTree = {
    attach: function(context, settings) {    
      var $file = Drupal.settings.islandoraJSTree.resourceUri;
      
      $json = JSON.parse($file);
      
      $('#jstree').jstree({
        plugins: ["checkbox", "sort", "types", "wholerow", "search"],
        'core' : { 
          'data' : $json
        }
      });
    }
  };
})(jQuery);
