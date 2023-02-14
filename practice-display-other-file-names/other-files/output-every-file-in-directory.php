<?php
$directory = "/Applications/XAMPP/xamppfiles/htdocs/practice-display-other-file-names/essay-files";
$files = array_diff(scandir($directory), array('.', '..'));
?>

<h1>File Names:</h1>
<ul>
    <?php foreach ($files as $file) : ?>
        <li><?php echo $file; ?></li>
    <?php endforeach; ?>
</ul>
