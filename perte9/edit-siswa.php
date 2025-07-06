<?php
include 'connection.php';

if (isset($_GET['nisn'])) {
    $nisn = mysqli_real_escape_string($connection, $_GET['nisn']);
    $query = "SELECT * FROM tb_siswa WHERE nisn = '$nisn'";
    $result = mysqli_query($connection, $query);

    if (mysqli_num_rows($result) > 0) {
        $row = mysqli_fetch_assoc($result);
        ?>
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Edit Siswa</title>
            <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
        </head>
        <body>
            <div class="container mt-5">
                <h2 class="text-center mb-4">Edit Siswa</h2>
                <form action="update-siswa.php" method="POST">
                    <input type="hidden" name="nisn" value="<?php echo htmlspecialchars($row['nisn']); ?>">
                    <div class="mb-3">
                        <label class="form-label">NISN</label>
                        <input type="text" name="nisn" class="form-control" value="<?php echo htmlspecialchars($row['nisn']); ?>" readonly>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Nama Lengkap</label>
                        <input type="text" name="nama_lengkap" class="form-control" value="<?php echo htmlspecialchars($row['nama_lengkap']); ?>" required>
                    </div>
                    <div class="mb-3">
                        <label class="form-label">Alamat</label>
                        <input type="text" name="alamat" class="form-control" value="<?php echo htmlspecialchars($row['alamat']); ?>" required>
                    </div>
                    <button type="submit" class="btn btn-primary">Simpan</button>
                    <a href="index.php" class="btn btn-secondary">Kembali</a>
                </form>
            </div>
            <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
        </body>
        </html>
        <?php
    } else {
        echo "Data tidak ditemukan.";
    }
} else {
    echo "NISN tidak diterima.";
}

mysqli_close($connection);
?>