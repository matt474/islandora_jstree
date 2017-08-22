(function($) {
  Drupal.behaviors.islandoraJSTree = {
    attach: function(context, settings) {
      var div = document.getElementById('jstree-error');
      div.innerHTML = 'jstree is unable to read the zip file.';
    }
  };
})(jQuery);
