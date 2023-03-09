<?php
  // Get the list of file names in the essays folder
  $essaysFolder = "/html/essays/";
  $fileNames = array_map(function($file) {
    return basename($file);
  }, glob($essaysFolder . "*.html"));

  // Return the file names as a JSON object
  header("Content-Type: application/json");
  echo json_encode($fileNames);
