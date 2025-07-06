<?php
include 'connection.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $nisn = mysqli_real_escape_string($connection, $_POST['nisn']);
    $nama_lengkap = mysqli_real_escape_string($connection, $_POST['nama_lengkap']);
    $alamat = mysqli_real_escape_string($connection, $_POST['alamat']);

    $query = "UPDATE tb_siswa SET nama_lengkap = '$nama_lengkap', alamat = '$alamat' WHERE nisn = '$nisn'";
    $result = mysqli_query($connection, $query);

    if ($result) {
        header("Location: index.php?pesan=update-berhasil");
        exit();
    } else {
        $error = urlencode(mysqli_error($connection));
        header("Location: edit-siswa.php?nisn=$nisn&pesan=update-gagal&error=$error");
        exit();
    }
} else {
    header("Location: index.php");
    exit();
}

mysqli_close($connection);
