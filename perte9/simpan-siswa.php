<?php
include('connection.php');

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $nisn = trim($_POST['nisn']);
    $nama_lengkap = trim($_POST['nama_lengkap']);
    $alamat = trim($_POST['alamat']);

    // Cek duplikasi NISN
    $cek_query = "SELECT nisn FROM tb_siswa WHERE nisn = ?";
    $cek_stmt = mysqli_prepare($connection, $cek_query);
    mysqli_stmt_bind_param($cek_stmt, "s", $nisn);
    mysqli_stmt_execute($cek_stmt);
    mysqli_stmt_store_result($cek_stmt);
    if (mysqli_stmt_num_rows($cek_stmt) > 0) {
        header("Location: tambah-siswa.php?pesan=duplikat");
        exit();
    }
    mysqli_stmt_close($cek_stmt);

    // Simpan data
    $query = "INSERT INTO tb_siswa (nisn, nama_lengkap, alamat) VALUES (?, ?, ?)";
    $stmt = mysqli_prepare($connection, $query);
    mysqli_stmt_bind_param($stmt, "sss", $nisn, $nama_lengkap, $alamat);
    if (mysqli_stmt_execute($stmt)) {
        header("Location: tambah-siswa.php?pesan=sukses");
        exit();
    } else {
        $error = urlencode(mysqli_error($connection));
        header("Location: tambah-siswa.php?pesan=gagal&error=$error");
        exit();
    }
    mysqli_stmt_close($stmt);
} else {
    header("Location: tambah-siswa.php");
    exit();
}

mysqli_close($connection);