<?php if(isset($errorMessage)): ?>
  <?php print "<p class=\"jstree-error\">$errorMessage</p>" ?>
  <?php endif ?>

<?php if(isset($truncated)): ?>
  <?php print "<p class=\"jstree-warning\">$truncated items have been truncated.</p>" ?>
  <?php endif ?>

<div id="jstree">
  
</div>
