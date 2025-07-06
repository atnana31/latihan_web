<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tambah Siswa</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body>
    <div class="container mt-5">
        <h2 class="text-center mb-4">TAMBAH SISWA</h2>
        <?php
        if (isset($_GET['pesan'])) {
            if ($_GET['pesan'] == 'sukses') {
                echo '<div class="alert alert-success">Data berhasil disimpan!</div>';
            } elseif ($_GET['pesan'] == 'gagal') {
                $err = isset($_GET['error']) ? htmlspecialchars($_GET['error']) : '';
                echo '<div class="alert alert-danger">Data gagal disimpan! ' . $err . '</div>';
            } elseif ($_GET['pesan'] == 'duplikat') {
                echo '<div class="alert alert-warning">NISN sudah terdaftar, gunakan NISN lain.</div>';
            }
        }
        ?>
        <form action="simpan-siswa.php" method="POST">
            <div class="mb-3">
                <label for="nisn" class="form-label">NISN</label>
                <input type="text" class="form-control" id="nisn" name="nisn" placeholder="Masukkan NISN"
                    required>
            </div>
            <div class="mb-3">
                <label for="nama_lengkap" class="form-label">Nama Lengkap</label>
                <input type="text" class="form-control" id="nama_lengkap" name="nama_lengkap"
                    placeholder="Masukkan Nama Lengkap" required>
            </div>
            <div class="mb-3">
                <label for="alamat" class="form-label">Alamat</label>
                <textarea class="form-control" id="alamat" name="alamat" placeholder="Masukkan Alamat" rows="4" required></textarea>
            </div>
            <button type="submit" class="btn btn-primary">SIMPAN</button>
            <button type="reset" class="btn btn-secondary">RESET</button>
            <a href="index.php" class="btn btn-link">Kembali ke Daftar</a>
        </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>

</html>
