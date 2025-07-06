<?php
// Nonaktifkan error reporting untuk produksi
error_reporting(0);
ini_set('display_errors', 0);

include 'connection.php'; // Pastikan path ini benar dan file connection.php ada

if (isset($_GET['id_siswa'])) {
    $id = mysqli_real_escape_string($connection, $_GET['id_siswa']);

    // Gunakan prepared statement untuk mencegah SQL injection
    $query = "DELETE FROM tb_siswa WHERE id_siswa = ?";
    $stmt = mysqli_prepare($connection, $query);

    if ($stmt) {
        mysqli_stmt_bind_param($stmt, "i", $id);
        $result = mysqli_stmt_execute($stmt);

        if ($result) {
            header("Location: index.php?pesan=hapus-berhasil");
            exit;
        } else {
            header("Location: index.php?pesan=gagal-hapus&error=" . urlencode(mysqli_error($connection)));
            exit;
        }

        mysqli_stmt_close($stmt);
    } else {
        header("Location: index.php?pesan=gagal-hapus&error=" . urlencode(mysqli_error($connection)));
        exit;
    }
} else {
    header("Location: index.php?pesan=gagal-hapus&error=ID%20siswa%20tidak%20ditemukan");
    exit;
}

mysqli_close($connection);
?>