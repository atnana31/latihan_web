<?php
// Database connection configuration
$db_host = "localhost";
$db_user = "root";
$db_pass = "";
$db_name = "db_school";

// Create connection
$connection = mysqli_connect($db_host, $db_user, $db_pass, $db_name);

// Check connection
if (!$connection) {
    die("Connection Failed: " . mysqli_connect_error());
}
